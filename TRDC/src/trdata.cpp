#include"TRData.h"

TRData::TRData(const QString& name):
	name(name),arguments(QVariantMap()) {}

TRData::~TRData() {}


void TRData::SetArgument(const QString& key, const QVariant& value) {
	arguments.insert(key, value);
}

QVariant TRData::GetArgument(const QString& key) {
	return arguments.value(key);
}

QString &TRData::GetName() {
	return this->name;
}

