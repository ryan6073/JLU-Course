#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QUdpSocket>
#include <QNetworkInterface>
#include <QDateTime>
#include <QFile>
#include <QFileDialog>
#include "qdom.h"

class FileSrvDlg;

namespace Ui {
class MainWindow;
}

enum ChatMsgType { ChatMsg, OnLine, OffLine, SfileName, RefFile };//消息类型
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();    
    void initMainWindow();
    void onLine(QString name, QString time);//处理新用户加入
    void offLine(QString name, QString time);//处理用户离开
    void sendChatMsg(ChatMsgType msgType, QString rmtName = "");//广播UDP消息
    QString getLocHostIp();//获取本端IP地址
    QString getLocChatMsg();//获取本端聊天信息内容
    void recvFileName(QString name, QString hostip, QString rmtname, QString filename);

protected:
    void closeEvent(QCloseEvent *event);//重写关闭窗口方法以便发送通知离开消息

private slots:
    void on_sendPushButton_clicked();

    void recvAndProcessChatMsg();//接收并处理UDP数据报

    void on_searchPushButton_clicked();

    void getSfileName(QString);

    void on_transPushButton_clicked();

private:
    Ui::MainWindow *ui;
    QString myname = "";//本端用户名
    QUdpSocket *myUdpSocket;
    qint16 myUdpPort;
    QDomDocument myDoc;
    QString myFileName;
    FileSrvDlg *myfsrv;
};

#endif // MAINWINDOW_H
