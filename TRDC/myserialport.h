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
    void myGetBaud(QString qstr);
    void myGetName(QString qstr);
    void myOpenCom();
    int myComSend(QString str_send);
    void myGetCom(QString qstr);
    QStringList myScanCom();
    QTimer *recvDelayTimer;
    void mySignalEmit();
    void mySetDataType(bool hex_type);

private:
    QSerialPort::BaudRate CombaudRate;
    QSerialPort::DataBits ComdataBits;
    QSerialPort::StopBits ComstopBits;
    QSerialPort::Parity   ComParity;
    QString PortNum;
    QString PortName;
    QSerialPort MyCom;                  //唯一的串口对象
    bool hexData;
    long ComSendNum,ComRecvNum;
private slots:
    void portDataReady();
    QString myComRecv();
    void errorHandle(QSerialPort::SerialPortError);
};


#endif // MYSERIALPORT_H
