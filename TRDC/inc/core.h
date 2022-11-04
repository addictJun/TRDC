#pragma once

#include<QObject>
#include"TRDC.h"
#include"myserialport.h"
#include"global.h"
#include"trdata.h"

#define TR_CMD_CONNECT_EXEC(cmd, func) if(cmd == data->GetName()) \
			{func; return;}

#define VARIANT_TO_CUSTOM(pObject, ClassName)  static_cast<ClassName*>(pObject.value<void*>())	

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

//UI界面的命令处理
public:
	void ScanSerial();  //扫描串口
	void OpenSerial(const TRData::Ptr data); //打开串口
	void CloseSerial(const QString& name); //关闭串口
	void StopRev(const TRData::Ptr data);  //停止显示
	void StartRev(const TRData::Ptr data);  //开始显示
	void SendData(const TRData::Ptr data); //发送数据

//串口阶段的命令处理
public:



//缓存数据
private:
	TRDC *w=NULL;
	mySerialPort* my_port = NULL;


};