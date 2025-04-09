#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QHostAddress>
#include <QJsonDocument>
#include <QVariantMap>
#include <QMessageBox>

#include "mainwindow.h"
#include "wechatmainwindow.h"

namespace Ui {
class WelcomeWindow;
}

class WelcomeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit WelcomeWindow(QWidget *parent = nullptr);
    ~WelcomeWindow();

    void analysisJson(QVariantMap& map);

private slots:
    void on_pushButtonQQ_clicked();
    void on_pushButtonWeChat_clicked();
    void on_pushButtonWeiBo_clicked();
    void on_connectBtn_clicked();
    void on_pushButtonOpen_clicked();

private:
    Ui::WelcomeWindow *ui;
    MainWindow mainWindow;
    WeChatMainWindow wechatWindow;
    QTcpSocket* client = nullptr;
};

#endif // WELCOMEWINDOW_H
