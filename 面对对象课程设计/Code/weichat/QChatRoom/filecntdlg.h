#ifndef FILECNTDLG_H
#define FILECNTDLG_H

#include <QDialog>
#include <QFile>
#include <QTime>
#include <QTcpSocket>
#include <QHostAddress>

class QTcpSocket;

namespace Ui {
class FileCntDlg;
}

class FileCntDlg : public QDialog
{
    Q_OBJECT

public:
    explicit FileCntDlg(QWidget *parent = 0);
    ~FileCntDlg();
    void getSrvAddr(QHostAddress saddr);
    void getLocPath(QString lpath);

protected:
    void closeEvent(QCloseEvent *);

private slots:
    void createConnToSrv();

    void readChatMsg();

    void on_cntClosePushButton_clicked();

private:
    Ui::FileCntDlg *ui;
    QTcpSocket *myCntSocket;
    QHostAddress mySrvAddr;
    qint16 mySrvPort;

    qint64 myTotalBytes;
    qint64 myRcvedBytes;
    QByteArray myInputBlock;
    quint16 myBlockSize;

    QFile *myLocPathFile;
    QString myFileName;
    qint64 myFileNameSize;

    QTime mytime;
};

#endif // FILECNTDLG_H
