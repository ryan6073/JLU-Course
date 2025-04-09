#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <QObject>

class DataHandler
{
public:
    DataHandler();

    static DataHandler* GetInstance();

public:
    QString currentQQ;
    QString currentWeChat;
};

#endif // DATAHANDLER_H
