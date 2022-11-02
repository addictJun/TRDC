#ifndef MYSERIALPORT_H
#define MYSERIALPORT_H

#include <QObject>
#include <QTimer>
#include <QString>
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>
#include <QMessageBox>
#include <QDebug>



class mySerialPort : public QObject
{
    Q_OBJECT
public:
    explicit mySerialPort(QObject *parent = nullptr);
    ~mySerialPort();
    void mySetBaud(QString qstr);
    void myOpenCom();
    int myComSend(QString str_send);
    void mySetCom(QString qstr);
    QStringList myScanCom();
    QTimer *recvDelayTimer;
    void mySignalEmit();
    void mySetDataType(bool hex_type);

private:
    //串口配置
    QSerialPort::BaudRate CombaudRate;
    QSerialPort::DataBits ComdataBits;
    QSerialPort::StopBits ComstopBits;
    QSerialPort::Parity   ComParity;
    QString PortNum;
    QSerialPort MyCom;                  //唯一的串口对象
    //收/发数据类型，true为十六进制，false为字符串
    bool hexData;
    //收/发流量统计
    long ComSendNum,ComRecvNum;
private slots:
    void portDataReady();
    QString myComRecv();
    void errorHandle(QSerialPort::SerialPortError);
};


#endif // MYSERIALPORT_H
