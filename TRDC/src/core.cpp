#include"core.h"


Core::Core(QObject* parent) : QObject(parent) {
	//1.初始化界面
	this->w = new TRDC();
	w->show();

	//2.初始化串口
	this->my_port = new mySerialPort();
	
	//3.初始化连接函数
	SignalSlotInit();

	//4.初步交互，获取串口信息

}

void Core::SignalSlotInit() {
	//与上层的连接
	connect(w, SIGNAL(signal(const TRData::Ptr)),\
		this, SLOT(Recv(const TRData::Ptr)));

	//与下层的连接
	//connect(this, SIGNAL(Send), \
	//	this, SLOT());
}

Core::~Core() {

}

//解析数据
void Core::Recv(const TRData::Ptr data) {
	
	TR_CMD_CONNECT_EXEC(S_SCAN_SERIAL, ScanSerial());
	TR_CMD_CONNECT_EXEC(S_OPEN_SERIAL, OpenSerial(data));
	TR_CMD_CONNECT_EXEC(S_CLOSE_SERIAL, CloseSerial(data->GetName()));
	
}

void Core::ScanSerial() {
	QStringList res = my_port->myScanCom();
	w->SetComboBoxNo(res);
}

void Core::OpenSerial(const TRData::Ptr data) {

}

void Core::CloseSerial(const QString &name) {

}