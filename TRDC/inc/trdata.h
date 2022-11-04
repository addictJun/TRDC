#pragma once
#include <QString>
#include <QVariant>

class TRData {

public:
	// ��Ϣ�ڵ�����ܹ���ָ�룬�����Ļ���
	// ���Զ�����������ÿ��ʹ����Data֮�����Ƿ���Ҫ�ֶ��ͷ���Դ
	typedef QSharedPointer<TRData> Ptr;
	TRData(const QString &name);
	~TRData();

public:
	QString &GetName();
	void SetArgument(const QString &key, const QVariant &value);  //����ֵ
	QVariant GetArgument(const QString &key); //����ֵ

private:
	QString name;   //��������
	QVariantMap arguments;  //��Ϣ�ľ�������

};
