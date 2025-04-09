#ifndef _QQINFO_H_
#define _QQINFO_H_

#include "BaseInfo.h"

class QQInfo : public BaseInfo
{
public:
	QQInfo();
	QQInfo(QString identificationNumber, QString userAddress, QString registerDate, QString birthDate, QString qqNumber, QString qqName);
	~QQInfo();

	QString getNumber();
	QString getName();

public:
	QMap<QString,QString> friendMap;

private:
	QString qqNumber;
	QString qqName;
};

#endif // !_QQINFO_H_
