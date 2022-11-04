#pragma once

#include<QObject>
#include"TRDC.h"
#include"myserialport.h"
#include"global.h"
#include"trdata.h"

#define TR_CMD_CONNECT_EXEC(cmd, func) if(cmd == data->GetName()) \
			{func; return;}

/*
	胶水代码
	这里是所有代码汇集的地方
*/
class Core : public QObject 
{
	Q_OBJECT
public:
	explicit Core(QObject* parent = nullptr);
	~Core();

private:
	void SignalSlotInit();

private slots:
	void Recv(const TRData::Ptr data);

signals:
	void SendSerial(); //发送数据
	void SendUI(); //发送数据

//信号处理函数
public:
	void ScanSerial();  //扫描串口
	void OpenSerial(const TRData::Ptr data); //打开串口
	void CloseSerial(const QString& name); //关闭串口





//缓存数据
private:
	TRDC *w=NULL;
	mySerialPort* my_port = NULL;


};