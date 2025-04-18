﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>
#include <QPainter>
#include <QList>
#include <QFile>
#include <QJsonDocument>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void appendFile(QString newMessage);
    void distributeMessage(const QByteArray &data);
    void distributeMessageQQ(const QByteArray &data);
    void distributeMessageWeChat(const QByteArray &data);
    void paintEvent(QPaintEvent* event);

    void analysisJson(QTcpSocket* conn,QVariantMap& map);

private:
    Ui::MainWindow *ui;
    //定义监听指针
    QTcpServer* listen;
    //定义连接指针序列
    QList<QTcpSocket*> connList;
    QMap<QTcpSocket*,QString> qqConnectMap;
    QMap<QTcpSocket*,QString> weChatConnectMap;
};
#endif // MAINWINDOW_H
