#ifndef WECHATMAINWINDOW_H
#define WECHATMAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QHostAddress>
#include <QTime>
#include <QPainter>
#include <QFileDialog>

#include "loginview.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WeChatMainWindow; }
QT_END_NAMESPACE

class WeChatMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    WeChatMainWindow(QWidget *parent = nullptr);
    ~WeChatMainWindow();
    void paintEvent(QPaintEvent *event);
    void analysisJson(QVariantMap &map);

private slots:
    void on_pushButtonLogin_clicked();

    void loginAccount(QString account, QString password,QString identification);
    void registerAccount(QString account, QString password, QString identification);

private:
    Ui::WeChatMainWindow *ui;

    QTcpSocket* client;
    QString clientName;
    QPixmap pixMap;//背景图片
    QString tryAccount;
    QString tryPassword;
    LoginView loginView;
    QString currentUser;
};

#endif // WECHATMAINWINDOW_H
