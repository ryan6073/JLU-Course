#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "stdafx.h"
#include "loginview.h"
#include "infodialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setQssStyle();
    void paintEvent(QPaintEvent *event);
    void analysisJson(QVariantMap& map);

private slots:
    void on_treeWidget_customContextMenuRequested(const QPoint &pos);
    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);
    void on_headBtn_clicked();
    void on_backgroundBtn_clicked();
    void on_connectBtn_clicked();
    void on_pushButtonFriendSend_clicked();
    void on_pushButtonGroupSend_clicked();
    void on_lineEditAddress_textChanged(const QString &arg1);
    void on_lineEditPort_textChanged(const QString &arg1);
    void on_lineEditName_textChanged(const QString &arg1);
    void on_headBtn_customContextMenuRequested(const QPoint &pos);

    void loginAccount(QString account,QString password);
    void registerAccount(QString account,QString password);
    void updateInfo(QString number, QString password, QString name, QString identification, QString birth, QString date, QString place);

private:
    Ui::MainWindow *ui;

    QTcpSocket* client = nullptr;

    QString currentUser;
    QString clientName;
    QString tryAccount;
    QString tryPassword;
    bool isQueryOperation = false;

    QPixmap pixMap;
    LoginView loginView;
    InfoDialog infoDialog;
};
#endif // MAINWINDOW_H
