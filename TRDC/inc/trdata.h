#pragma once
#include <QString>
#include <QVariant>

class TRData {

public:
	// 信息节点的智能共享指针，这样的话，
	// 就自动析构不用再每次使用完Data之后担心是否需要手动释放资源
	typedef QSharedPointer<TRData> Ptr;
	TRData(const QString &name);
	~TRData();

public:
	QString &GetName();
	void SetArgument(const QString &key, const QVariant &value);  //设置值
	QVariant GetArgument(const QString &key); //设置值

private:
	QString name;   //数据名称
	QVariantMap arguments;  //消息的具体内容

};
