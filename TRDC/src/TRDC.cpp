#include "TRDC.h"

#ifdef Q_OS_WIN
#pragma execution_character_set("utf-8")   //解决 VS编译器下中文乱码
#endif

//构造与析构
TRDC::TRDC(QWidget *parent)
    : QMainWindow(parent)
{
    //1.绑定UI界面
    ui.setupUi(this);

    //2.初始化
    this->Init();  //页面初始化
    this->SignalSlotInit();  //信号槽机制初始化
    
}
TRDC::~TRDC()
{}

//初始化
void TRDC::SignalSlotInit() {
    //连接重定义的模块
    connect(comboBoxNo, SIGNAL(signal(TRData::Ptr)), \
        this, SLOT(ScanActivePort(TRData::Ptr)));
}
void TRDC::Init() {
    this->RefreshDPI();  //根据dpi调整窗口大小
    this->TimeInit();  //周期发送
    this->AddStatusBar();  //下标状态栏
    this->AddScanPort(); //添加串口按钮
    this->ButtonState(false);   // 隐藏发送按钮和接收
    this->ShowTime();  //延迟显示时间
}
void TRDC::RefreshDPI()
{
    //计算dpi
    QList<QScreen*> screens = QApplication::screens();
    QScreen* screen = screens[0];
    qreal dpi = screen->logicalDotsPerInch();

    //计算dpi对应的缩放比例
    double object_rate = dpi / 96.0;
    ChangeObjectSize(*this, object_rate);
    resize(width() * object_rate, height() * object_rate);

    ui.groupBoxRev->setFixedWidth(541 * object_rate);//根据屏幕分辨率不一样固定接收组的大小
    ui.TextRev->setFixedWidth(521 * object_rate);//根据屏幕分辨率不一样固定接收窗口的大小
    this->setFixedSize(729 * object_rate, 587 * object_rate);//根据屏幕分辨率不一样固定主窗口的大小
}
void TRDC::TimeInit() {
    //创建周期发送、时间显示、延时接收定时器，并初始化
    PriecSendTimer = new QTimer;
    PriecSendTimer->setInterval(1000);//默认周期1000ms
    connect(PriecSendTimer, &QTimer::timeout, this, [=]() {on_pushButtonSend_clicked(); });//定时器槽关联,关联至发送按钮槽函数，即定时到来时，自动发送数据
}
void TRDC::ChangeObjectSize(const QObject& o, double object_rate)
{
    for (int i = 0; i < o.children().size(); ++i) {
        QWidget* pWidget = qobject_cast<QWidget*>(o.children().at(i));
        if (pWidget != nullptr) {
            pWidget->setGeometry(pWidget->x() * object_rate, pWidget->y() * object_rate,
                pWidget->width() * object_rate, pWidget->height() * object_rate);
            ChangeObjectSize(*(o.children().at(i)), object_rate);
        }
    }
}
void TRDC::ButtonState(const bool &flag)
{
    //发送区
    ui.pushButtonSend->setEnabled(flag);
    //接收区
    ui.pushButtonSaveRev->setEnabled(flag);
    ui.pushButtonStopRev->setEnabled(flag);
    ui.pushButtonClearRev->setEnabled(flag);
    ui.checkBoxReVTime->setEnabled(flag);
    ui.checkBoxRevHex->setEnabled(flag);
    //发送设置
    comboBoxNo->setEnabled(!flag);
    ui.pushButtonRdFile->setEnabled(flag);
    ui.pushButtonClearSend->setEnabled(flag);
    ui.checkBoxSendHex->setEnabled(flag);
    ui.checkBoxPeriodicSend->setEnabled(flag);
    ui.lineEditTime->setEnabled(flag);
}
void TRDC::ShowTime() {

    QTimer* DateTimer = new QTimer(this);//状态栏显示时间，日期
    connect(DateTimer, &QTimer::timeout, this, [=]() {sTimeUpdate(); });
    DateTimer->start(1000); //每隔1000ms发送timeout的信号
}
void TRDC::sTimeUpdate()
{
    QDateTime current_time = QDateTime::currentDateTime();//获取时间
    QString timestr = current_time.toString("yyyy-MM-dd hh:mm:ss"); //设置显示的格式
    currentTimeLabel->setText(timestr); //设置label的文本内容为时间
}
void TRDC::AddStatusBar() {

    //创建下标状态栏
    QStatusBar* STABar = statusBar();//获取状态栏
    qlbSendSum = new QLabel(this);//创建发送统计标签
    qlbRevSum = new QLabel(this);//创建接收统计标签
    currentTimeLabel = new QLabel(this); // 创建时间，日期显示标签
    qlbLinkSource = new QLabel(this);//源码链接标签对象

    //创建标签大小
    qlbLinkSource->setMinimumSize(90, 20);
    qlbSendSum->setMinimumSize(100, 20);
    qlbRevSum->setMinimumSize(100, 20);
    currentTimeLabel->setMinimumSize(100, 20);

    //赋值
    ComSendSum = 0;
    ComRevSum = 0;
    SetNumOnLabel(qlbSendSum, "Tx: ", ComSendSum);
    SetNumOnLabel(qlbRevSum, "Rx: ", ComRevSum);
    STABar->addPermanentWidget(qlbSendSum);//发送
    STABar->addPermanentWidget(qlbRevSum);//接收
    STABar->addPermanentWidget(currentTimeLabel);//时间
    STABar->addWidget(qlbLinkSource);// github官网
    qlbLinkSource->setOpenExternalLinks(true);
    qlbLinkSource->setText("<style> a {text-decoration: none} </style> <a href=\"https://github.com/addictJun/TRDC\">--助手源代码--");// 无下划线
}

//公开接口
void TRDC::SetComboBoxNo(const QStringList& list) {
    // 先清空列表项，防止多次刷新后重叠
    comboBoxNo->clear();
    comboBoxNo->addItems(list);
    comboBoxNo->showPopup();
}
void TRDC::SetCloseSerial() {
    ui.pushButtonOpen->setText("关闭串口");
    ButtonState(true); //使能其他按钮
}
void TRDC::SetOpenSerial() {
    ui.pushButtonOpen->setText("打开串口");
    ButtonState(false); //使能其他按钮
}
void TRDC::SetStopRev() {
    ui.pushButtonStopRev->setText("停止显示");
}
void TRDC::SetStartRev() {
    ui.pushButtonStopRev->setText("继续显示");
}

//信号发送
void TRDC::OpenSerial() {
    //发射信号
    TRData::Ptr p_data(new TRData(S_OPEN_SERIAL));
    p_data->SetArgument(BAUD, ui.comboBoxComBaud->currentText());
    p_data->SetArgument(COM, comboBoxNo->currentText());
    emit signal(p_data);
}
void TRDC::CloseSerial() {
    //发射信号
    TRData::Ptr p_data(new TRData(S_CLOSE_SERIAL));
    emit signal(p_data);
}
void TRDC::ScanActivePort(const TRData::Ptr data) {
    emit signal(data);
} //扫描串口
void TRDC::on_pushButtonStopRev_clicked() {
    if (ui.pushButtonStopRev->text() == "停止显示")
    {
        TRData::Ptr p_data(new TRData(S_STOP_REV));
        emit signal(p_data);
    }
    else
    {
        TRData::Ptr p_data(new TRData(S_START_REV));
        emit signal(p_data);
    }
}
void TRDC::on_pushButtonSend_clicked() {
    //封装数据
    TRData::Ptr p_data(new TRData(S_SEND_DATA));
    p_data->SetArgument(SEND_DATA, ui.TextSend->toPlainText());
    p_data->SetArgument(HEX_FLAG, ui.checkBoxSendHex->checkState());
    p_data->SetArgument(WEEK_FLAG, ui.checkBoxPeriodicSend->checkState());
    emit signal(p_data);
}

//其他私有函数
void TRDC::AddScanPort() {
    comboBoxNo = new myComboBox(ui.groupBoxComSet);
    comboBoxNo->setObjectName(QStringLiteral("comboBoxNo"));
    comboBoxNo->setGeometry(QRect(10, 21, 144, 22));
}
void TRDC::on_checkBoxPeriodicSend_stateChanged(int arg1) {
    if (arg1 == false)//未选中
    {
        PriecSendTimer->stop();//关闭定时器
        qDebug() << "未周期发送" << endl;
    }
    else
    {
        PriecSendTimer->start(ui.lineEditTime->text().toInt());//启动周期发送定时器
        qDebug() << "已设置周期发送" << endl;
    }
}
void TRDC::on_pushButtonOpen_clicked() {

    if (ui.pushButtonOpen->text() == "打开串口") {
        OpenSerial();
    }
    else {
        CloseSerial(); //关闭串口
    }
}
void TRDC::on_checkBoxReVTime_stateChanged(int arg1) {
    
}
void TRDC::on_pushButtonClearRev_clicked() {
    ui.TextRev->clear();
    ComSendSum = 0;
    ComRevSum = 0;
    SetNumOnLabel(qlbSendSum, "Tx: ", ComSendSum);
    SetNumOnLabel(qlbRevSum, "Rx: ", ComRevSum);
}
void TRDC::on_pushButtonClearSend_clicked() {
    ui.TextSend->clear();
    ComSendSum = 0;
    ComRevSum = 0;
    SetNumOnLabel(qlbSendSum, "Tx: ", ComSendSum);
    SetNumOnLabel(qlbRevSum, "Rx: ", ComRevSum);
}
void TRDC::on_pushButtonRdFile_clicked() {
    QString curPath = QDir::currentPath();//获取系统当前目录
    QString dlgTitle = "打开一个文件"; //对话框标题
    QString filter = "文本文件(*.txt);;所有文件(*.*)"; //文件过滤器
    QString aFileName = QFileDialog::getOpenFileName(this, dlgTitle, curPath, filter);
    if (aFileName.isEmpty())
        return;
    openTextByIODevice(aFileName);
}
bool TRDC::openTextByIODevice(const QString& aFileName)
{
    QFile   aFile(aFileName);//用IODevice方式打开文本文件
    if (!aFile.exists()) //文件不存在
        return false;
    if (!aFile.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;
    QByteArray text = aFile.readAll();
    QString strText = byteArrayToUnicode(text);//编码格式转换，防止GBK中文乱码
    ui.TextSend->setPlainText(strText);
    aFile.close();
    return  true;
}
QString TRDC::byteArrayToUnicode(const QByteArray& array)
{
    // state用于保存转换状态，它的成员invalidChars，可用来判断是否转换成功
    // 如果转换成功，则值为0，如果值大于0，则说明转换失败
    QTextCodec::ConverterState state;
    // 先尝试使用utf-8的方式把QByteArray转换成QString
    QString text = QTextCodec::codecForName("UTF-8")->toUnicode(array.constData(), array.size(), &state);
    // 如果转换时无效字符数量大于0，说明编码格式不对
    if (state.invalidChars > 0)
    {
        // 再尝试使用GBK的方式进行转换，一般就能转换正确(当然也可能是其它格式，但比较少见了)
        text = QTextCodec::codecForName("GBK")->toUnicode(array);
    }
    return text;
}
void TRDC::on_pushButtonSaveRev_clicked() {
    QString curPath = QDir::currentPath();//获取系统当前目录
    QString dlgTitle = "另存为一个文件"; //对话框标题
    QString filter = "文本文件(*.txt);;所有文件(*.*);;h文件(*.h);;c++文件(*.cpp)"; //文件过滤器
    QString aFileName = QFileDialog::getSaveFileName(this, dlgTitle, curPath, filter);
    if (aFileName.isEmpty())
        return;
    saveTextByIODevice(aFileName);
}
bool TRDC::saveTextByIODevice(const QString& aFileName)
{ //用IODevice方式保存文本文件
    QFile aFile(aFileName);
    //aFile.setFileName(aFileName);
    if (!aFile.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;
    QString str = ui.TextRev->toPlainText();//整个内容作为字符串
    QByteArray  strBytes = str.toUtf8();//转换为字节数组

    aFile.write(strBytes, strBytes.length());  //写入文件
    aFile.close();
    return true;
}
void TRDC::SetNumOnLabel(QLabel* lbl, QString strS, long num)
{
    // 标签显示
    QString strN;
    strN.sprintf("%ld", num);
    QString str = strS + strN;
    lbl->setText(str);
}