#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QChatRoom.h"

class QChatRoom : public QMainWindow
{
    Q_OBJECT

public:
    QChatRoom(QWidget *parent = nullptr);
    ~QChatRoom();

private:
    Ui::QChatRoomClass ui;
};
