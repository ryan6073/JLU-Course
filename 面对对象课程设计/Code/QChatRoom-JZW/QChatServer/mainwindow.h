#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>
#include <QPainter>
#include <QList>
#include <QFile>

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
    void paintEvent(QPaintEvent* event);

private:
    Ui::MainWindow *ui;
    //定义监听指针
    QTcpServer* listen;
    //定义连接指针序列
    QList<QTcpSocket*> connList;
};
#endif // MAINWINDOW_H
