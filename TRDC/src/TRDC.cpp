#include "TRDC.h"

#ifdef Q_OS_WIN
#pragma execution_character_set("utf-8")   //��� VS����������������
#endif

TRDC::TRDC(QWidget *parent)
    : QMainWindow(parent)
{
    //1.��UI����
    ui.setupUi(this);

    //2.��ʼ��
    this->SignalSlotInit();
    this->Init();
}

TRDC::~TRDC()
{}

void TRDC::SignalSlotInit() {
    
}

/***********************************************************
*��ʼ��ҳ������
***********************************************************/
void TRDC::Init() {
    this->RefreshDPI();  //����dpi�������ڴ�С
    this->TimeInit();  //���ڷ���
    this->AddStatusBar();  //�±�״̬��
    this->AddScanPort(); //��Ӵ��ڰ�ť
    this->ButtonState(false);   // ���ط��Ͱ�ť�ͽ���
    this->ShowTime();  //�ӳ���ʾʱ��
}

/***********************************************************
*ˢ��dpi����ȡ��ǰ��Ļ״̬�����������ÿؼ��Ĵ�С
*ֻ�ڴ��ڹ��캯���е��ã���ˣ��ı���Ļ�ֱ�����Ҫ�����������
***********************************************************/
void TRDC::RefreshDPI()
{
    //����dpi
    QList<QScreen*> screens = QApplication::screens();
    QScreen* screen = screens[0];
    qreal dpi = screen->logicalDotsPerInch();

    //����dpi��Ӧ�����ű���
    double object_rate = dpi / 96.0;
    ChangeObjectSize(*this, object_rate);
    resize(width() * object_rate, height() * object_rate);

    ui.groupBoxRev->setFixedWidth(541 * object_rate);//������Ļ�ֱ��ʲ�һ���̶�������Ĵ�С
    ui.TextRev->setFixedWidth(521 * object_rate);//������Ļ�ֱ��ʲ�һ���̶����մ��ڵĴ�С
    this->setFixedSize(729 * object_rate, 587 * object_rate);//������Ļ�ֱ��ʲ�һ���̶������ڵĴ�С
}


void TRDC::TimeInit() {
    //�������ڷ��͡�ʱ����ʾ����ʱ���ն�ʱ��������ʼ��
    PriecSendTimer = new QTimer;
    PriecSendTimer->setInterval(1000);//Ĭ������1000ms
    connect(PriecSendTimer, &QTimer::timeout, this, [=]() {on_pushButtonSend_clicked(); });//��ʱ���۹���,���������Ͱ�ť�ۺ���������ʱ����ʱ���Զ���������
}

/***********************************************************
* ������Ļ��յ����ؼ���С
***********************************************************/
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
/***********************************************************
* ��ť״̬
***********************************************************/
void TRDC::ButtonState(const bool &flag)
{
    //������
    ui.pushButtonSend->setEnabled(flag);
    //������
    ui.pushButtonSaveRev->setEnabled(flag);
    ui.pushButtonStopRev->setEnabled(flag);
    ui.pushButtonClearRev->setEnabled(flag);
    ui.checkBoxReVTime->setEnabled(flag);
    ui.checkBoxRevHex->setEnabled(flag);
    //��������
    comboBoxNo->setEnabled(!flag);
    ui.pushButtonRdFile->setEnabled(flag);
    ui.pushButtonClearSend->setEnabled(flag);
    ui.checkBoxSendHex->setEnabled(flag);
    ui.checkBoxPeriodicSend->setEnabled(flag);
    ui.lineEditTime->setEnabled(flag);
}

void TRDC::ShowTime() {

    QTimer* DateTimer = new QTimer(this);//״̬����ʾʱ�䣬����
    connect(DateTimer, &QTimer::timeout, this, [=]() {sTimeUpdate(); });
    DateTimer->start(1000); //ÿ��1000ms����timeout���ź�
}

void TRDC::sTimeUpdate()
{

    QDateTime current_time = QDateTime::currentDateTime();//��ȡʱ��
    QString timestr = current_time.toString("yyyy-MM-dd hh:mm:ss"); //������ʾ�ĸ�ʽ
    currentTimeLabel->setText(timestr); //����label���ı�����Ϊʱ��
}



void TRDC::AddStatusBar() {

    //�����±�״̬��
    QStatusBar* STABar = statusBar();//��ȡ״̬��
    qlbSendSum = new QLabel(this);//��������ͳ�Ʊ�ǩ
    qlbRevSum = new QLabel(this);//��������ͳ�Ʊ�ǩ
    currentTimeLabel = new QLabel(this); // ����ʱ�䣬������ʾ��ǩ
    qlbLinkSource = new QLabel(this);//Դ�����ӱ�ǩ����

    //������ǩ��С
    qlbLinkSource->setMinimumSize(90, 20);
    qlbSendSum->setMinimumSize(100, 20);
    qlbRevSum->setMinimumSize(100, 20);
    currentTimeLabel->setMinimumSize(100, 20);

    //��ֵ
    ComSendSum = 0;
    ComRevSum = 0;
    SetNumOnLabel(qlbSendSum, "Tx: ", ComSendSum);
    SetNumOnLabel(qlbRevSum, "Rx: ", ComRevSum);
    STABar->addPermanentWidget(qlbSendSum);//����
    STABar->addPermanentWidget(qlbRevSum);//����
    STABar->addPermanentWidget(currentTimeLabel);//ʱ��
    STABar->addWidget(qlbLinkSource);// github����
    qlbLinkSource->setOpenExternalLinks(true);
    qlbLinkSource->setText("<style> a {text-decoration: none} </style> <a href=\"https://github.com/addictJun/TRDC\">--����Դ����--");// ���»���
}

void TRDC::AddScanPort() {
    comboBoxNo = new myComboBox(ui.groupBoxComSet);
    comboBoxNo->setObjectName(QStringLiteral("comboBoxNo"));
    comboBoxNo->setGeometry(QRect(10, 20, 51, 19));
}

void TRDC::sPeriodicallySendData() {

}

/***********************************************************
 * ״̬����ǩ��ʾ����ֵ
 * 1.���ñ�ǩ��ʾ����
 ***********************************************************/
void TRDC::SetNumOnLabel(QLabel* lbl, QString strS, long num)
{
    // ��ǩ��ʾ
    QString strN;
    strN.sprintf("%ld", num);
    QString str = strS + strN;
    lbl->setText(str);
}

/***********************************************************
 * �򿪴���
 ***********************************************************/
void TRDC::on_pushButtonOpen_clicked() {

    if (ui.pushButtonOpen->text() == "�򿪴���") {
        if (ConnectSerial()) {
            OpenSerial();
        }
        else {
            qDebug() << "connect is fail";
        }   
    }
    else {
        CloseSerial(); //�رմ���
    }
}

void TRDC::on_checkBoxPeriodicSend_stateChanged(int arg1) {
    if (arg1 == false)//δѡ��
    {
        PriecSendTimer->stop();//�رն�ʱ��
        qDebug() << "δ���ڷ���" <<endl;
    }
    else
    {
        PriecSendTimer->start(ui.lineEditTime->text().toInt());//�������ڷ��Ͷ�ʱ��
        qDebug() << "���������ڷ���" << endl;
    }
}

void TRDC::OpenSerial() {
    ui.pushButtonOpen->setText("�رմ���");
    ButtonState(true); //�رմ���
}

void TRDC::CloseSerial() {
    ui.pushButtonOpen->setText("�򿪴���");
    ButtonState(false); //�رմ���
}

bool TRDC::ConnectSerial() {
    qDebug() << "name:open serial";
    qDebug() << "canshu:" << endl;
    return true;
}

void TRDC::on_checkBoxReVTime_stateChanged(int arg1) {
    
}

void TRDC::on_pushButtonSend_clicked() {

    QByteArray ComSendData;
    QString SendTemp;
    //��ȡ���ʹ�������
    SendTemp = ui.TextSend->toPlainText();
    //�жϷ��͸�ʽ������ʽ������
    if (ui.checkBoxSendHex->checkState() != false)//16���Ʒ���
    {
        SendTemp.append("0D0A");// ������ӻ���
        ComSendData = QByteArray::fromHex(SendTemp.toUtf8()).data();//��ȡ�ַ���
        qDebug() << "name:16 ����send_data";
        qDebug() << "canshu:" << ComSendData << endl;
    }
    else //�ַ�����ʽ����
    {
        SendTemp.append("\r\n");// ������ӻ���
        ComSendData = SendTemp.toLocal8Bit().data();//��ȡ�ַ���
        qDebug() << "name:send_data";
        qDebug() << "canshu:" << ComSendData << endl;
    }
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

void TRDC::on_pushButtonStopRev_clicked() {
    if (ui.pushButtonStopRev->text() == "ֹͣ��ʾ")
    {
        ui.pushButtonStopRev->setText("������ʾ");
    }
    else
    {
        ui.pushButtonStopRev->setText("ֹͣ��ʾ");
    }
}

void TRDC::on_pushButtonRdFile_clicked() {
    QString curPath = QDir::currentPath();//��ȡϵͳ��ǰĿ¼
    QString dlgTitle = "��һ���ļ�"; //�Ի������
    QString filter = "�ı��ļ�(*.txt);;�����ļ�(*.*)"; //�ļ�������
    QString aFileName = QFileDialog::getOpenFileName(this, dlgTitle, curPath, filter);
    if (aFileName.isEmpty())
        return;
    openTextByIODevice(aFileName);
}

/***********************************************************
 *���ļ�����
 * ��ȡ�ļ��������ļ�������ʾ�ڷ��Ϳ�
 ***********************************************************/
bool TRDC::openTextByIODevice(const QString& aFileName)
{
    QFile   aFile(aFileName);//��IODevice��ʽ���ı��ļ�
    if (!aFile.exists()) //�ļ�������
        return false;
    if (!aFile.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;
    QByteArray text = aFile.readAll();
    QString strText = byteArrayToUnicode(text);//�����ʽת������ֹGBK��������
    ui.TextSend->setPlainText(strText);
    aFile.close();
    return  true;
}
/***********************************************************
*�����ʽת��
*��ֹGBK��������
***********************************************************/
QString TRDC::byteArrayToUnicode(const QByteArray& array)
{
    // state���ڱ���ת��״̬�����ĳ�ԱinvalidChars���������ж��Ƿ�ת���ɹ�
    // ���ת���ɹ�����ֵΪ0�����ֵ����0����˵��ת��ʧ��
    QTextCodec::ConverterState state;
    // �ȳ���ʹ��utf-8�ķ�ʽ��QByteArrayת����QString
    QString text = QTextCodec::codecForName("UTF-8")->toUnicode(array.constData(), array.size(), &state);
    // ���ת��ʱ��Ч�ַ���������0��˵�������ʽ����
    if (state.invalidChars > 0)
    {
        // �ٳ���ʹ��GBK�ķ�ʽ����ת����һ�����ת����ȷ(��ȻҲ������������ʽ�����Ƚ��ټ���)
        text = QTextCodec::codecForName("GBK")->toUnicode(array);
    }
    return text;
}

void TRDC::on_pushButtonSaveRev_clicked() {
    QString curPath = QDir::currentPath();//��ȡϵͳ��ǰĿ¼
    QString dlgTitle = "���Ϊһ���ļ�"; //�Ի������
    QString filter = "�ı��ļ�(*.txt);;�����ļ�(*.*);;h�ļ�(*.h);;c++�ļ�(*.cpp)"; //�ļ�������
    QString aFileName = QFileDialog::getSaveFileName(this, dlgTitle, curPath, filter);
    if (aFileName.isEmpty())
        return;
    saveTextByIODevice(aFileName);
}
/***********************************************************
*д�ļ�����
*ִ���ļ����湤��
***********************************************************/
bool TRDC::saveTextByIODevice(const QString& aFileName)
{ //��IODevice��ʽ�����ı��ļ�
    QFile aFile(aFileName);
    //aFile.setFileName(aFileName);
    if (!aFile.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;
    QString str = ui.TextRev->toPlainText();//����������Ϊ�ַ���
    QByteArray  strBytes = str.toUtf8();//ת��Ϊ�ֽ�����

    aFile.write(strBytes, strBytes.length());  //д���ļ�
    aFile.close();
    return true;
}

