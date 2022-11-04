#include "myserialport.h"
#include <iostream>

mySerialPort::mySerialPort(QObject *parent) : QObject(parent)
{
//调试代码
     //QString strsend = "sh /home/root/new_ISR/tesh.sh &";
     QString strsend = "ls";
     mySetBaud("115200");
     mySerialPort::mySetCom("COM1");
     myOpenCom();
     mySetDataType(false);
     myComSend(strsend);
//调试结束
    recvDelayTimer = new QTimer;   //新建定时器，定时时间到，则触发接收延时函数，延时函数触发timeout信号，
                                   //进行数据接收
    //recvDelayTimer->start(2000);
    recvDelayTimer->stop();
    connect(recvDelayTimer,SIGNAL(timeout()),this,SLOT(myComRecv()));
    connect(&MyCom, SIGNAL(readyRead()), this, SLOT(portDataReady()));
    connect(&MyCom, SIGNAL(errorOccurred(QSerialPort::SerialPortError)), \
            this, SLOT(errorHandle(QSerialPort::SerialPortError)));
}

/******************************************
 * 设置波特率函数
 * 设置波特率并保存
 * ****************************************/
void mySerialPort::mySetBaud(QString qstr){
    //获取波特率
    if(qstr=="1200")
    {
        CombaudRate = QSerialPort::Baud1200;
    }
    else if(qstr=="2400")
    {
        CombaudRate = QSerialPort::Baud2400;
    }
    else if(qstr=="4800")
    {
        CombaudRate = QSerialPort::Baud4800;
    }
    else if(qstr=="9600")
    {
        CombaudRate = QSerialPort::Baud9600;
    }
    else if(qstr=="19200")
    {
        CombaudRate = QSerialPort::Baud19200;
    }
    else if(qstr=="38400")
    {
        CombaudRate = QSerialPort::Baud38400;
    }
    else if(qstr=="57600")
    {
        CombaudRate = QSerialPort::Baud57600;
    }
    else if(qstr=="115200")
    {
        CombaudRate = QSerialPort::Baud115200;
    }
    else
    {
        CombaudRate = QSerialPort::UnknownBaud;
    }
}

/******************************************
 * 设置串口号函数
 * 获取当前串口号并保存
 * ****************************************/
void mySerialPort::mySetCom(QString qstr){
    PortNum = qstr;
}

/******************************************
 * 设置数据类型函数
 * true为hex接收/发送，false为字符串接收/发送
 * ****************************************/
void mySerialPort::mySetDataType(bool hex_type){
    if(hex_type){
        hexData = true;
    }
    else{
        hexData = false;
    }
}

/******************************************
 * 打开串口函数
 * 1.获取当前端口号、比特率、数据位、停止位、校验方式
 * 2.初始化串口MyCom
 * 3.打开串口
 *  3.1 打开失败，返回错误消息
 * 4.调用该函数后记得在使用串口完毕后关闭串口，方法：MyCom.close()
 * ****************************************/
void mySerialPort::myOpenCom(){
    //qDebug() << PortNum <<CombaudRate<<endl;
    MyCom.setPortName(PortNum);
    MyCom.setParity(QSerialPort::NoParity);
    MyCom.setBaudRate(CombaudRate);
    MyCom.setDataBits(QSerialPort::Data8);
    MyCom.setStopBits(QSerialPort::OneStop);
   // MyCom.setFlowControl(QSerialPort::NoFlowControl);
    bool openFlag;
    if((openFlag = MyCom.open(QIODevice::ReadWrite)) == false){
        std::cout << "串口打开失败，该端口可能被占用或不存在！\r\n";
    }
    else{
        std::cout << "串口打开成功！\r\n";
    }
}

/******************************************
 * 串口接收数据槽函数
 * 1.由定时器timeout()信号触发
 * 2.接受当前缓冲区所有数据
 * 3.更新接收流量统计
 * 4.返回收到的字符串
 * ****************************************/
QString mySerialPort::myComRecv(){
    recvDelayTimer->stop();
    QByteArray MyComRevBuf;
    QString strTemp,strTemp1;

    //读取串口数据，并格式化
    MyComRevBuf = MyCom.readAll();

    //接收流量统计
    ComRecvNum += MyComRevBuf.size();

    strTemp = QString::fromLocal8Bit(MyComRevBuf);
    //十六进制显示
    if(hexData){
        strTemp = MyComRevBuf.toHex().toUpper();
        for(int i =0; i < strTemp.length(); i+=2){
            strTemp1 += strTemp.mid(i,2);
            strTemp1 += " ";
        }
        //qDebug() <<  strTemp1;
        return strTemp1;
    }
    //正常显示
    else {
        //qDebug() << strTemp;
        return strTemp;
    }
}

/******************************************
 * 串口发送数据函数
 * 1.发送指定数据，返回发送的字节数
 * 2.更新发送流量统计
 * 3.若hexData为true，则发送十六进制，否则，以字符串发送
 * 4.若指定发送为十六进制，则接收也默认为十六进制
 * ****************************************/
int mySerialPort::myComSend(QString str_send){
    QByteArray MyComSendBuf;
    QString strTemp = str_send;
    int ret = -1;
    //十六进制发送
    if(hexData){
        strTemp.append("0D0A");
        MyComSendBuf = QByteArray::fromHex(str_send.toUtf8()).data();
    }
    else{
        strTemp.append("\r\n");
        MyComSendBuf = strTemp.toLocal8Bit().data();//获取字符串
    }
    if((ret = MyCom.write(MyComSendBuf))){
        //接收流量统计
        ComSendNum += MyComSendBuf.size();
    }
    //刷新缓冲区，如果发送不能成功，则需要调用flush（）,数据才可以真正发送
   // MyCom.flush();
    return ret;
}

/******************************************
 * 串口扫描函数
 * 扫描所有可用串口，返回串口号以及对应的标识信息到QStringList
 * ****************************************/
QStringList mySerialPort::myScanCom(){
    QStringList activePortList;

    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts()){
        QString activePortNum = info.portName() + ": " + info.description();
        activePortList << activePortNum;
    }
    return activePortList;
}

/******************************************
 * 延时接收函数
 * 1.由于串口接收是以readyRead信号为触发标准，为了后续接收中文不会分段，进行延时
 * 2.绑定了readyRead信号，由该信号触发
 * ****************************************/
void mySerialPort::portDataReady(){
    recvDelayTimer->stop();
    recvDelayTimer->start(1);
}

/******************************************
 * 错误处理槽函数函数
 * 若串口操作出现错误，则捕捉错误信号，并绑定此错误处理函数
 * ****************************************/
void mySerialPort::errorHandle(QSerialPort::SerialPortError){
    std::cout << MyCom.error();
}


/******************************************
 * 析构函数函数
 * 关闭串口
 * ****************************************/

mySerialPort::~mySerialPort()
{
    MyCom.close();
}












