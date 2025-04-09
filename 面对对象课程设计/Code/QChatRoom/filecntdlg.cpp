#include "filecntdlg.h"
#include "ui_filecntdlg.h"

FileCntDlg::FileCntDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FileCntDlg)
{
    ui->setupUi(this);
    myCntSocket = new QTcpSocket(this);
    mySrvPort = 5555;
    connect(myCntSocket, SIGNAL(readyRead()), this, SLOT(readChatMsg()));
    myFileNameSize = 0;
    myTotalBytes = 0;
    myRcvedBytes = 0;
}

FileCntDlg::~FileCntDlg()
{
    delete ui;
}

void FileCntDlg::getLocPath(QString lpath)
{
    myLocPathFile = new QFile(lpath);
}

void FileCntDlg::getSrvAddr(QHostAddress saddr)
{
    mySrvAddr = saddr;
    createConnToSrv();
}

void FileCntDlg::createConnToSrv()
{
    myBlockSize = 0;
    myCntSocket->abort();
    myCntSocket->connectToHost(mySrvAddr, mySrvPort);
    mytime = QTime::currentTime();
}

void FileCntDlg::readChatMsg()
{
    QDataStream in(myCntSocket);
    in.setVersion(QDataStream::Qt_5_0);
    QTime curtime = QTime::currentTime();
    float usedTime = 0 - curtime.msecsTo(mytime);
    mytime = curtime;

    if (myRcvedBytes <= sizeof(qint64)*2)
    {
        if ((myCntSocket->bytesAvailable() >= sizeof(qint64)*2) && (myFileNameSize == 0))
        {
            in >> myTotalBytes >> myFileNameSize;
            myRcvedBytes += sizeof(qint64)*2;
        }
        if ((myCntSocket->bytesAvailable() >= myFileNameSize) && (myFileNameSize != 0))
        {
            in >> myFileName;
            myRcvedBytes += myFileNameSize;
            myLocPathFile->open(QFile::WriteOnly);
            ui->rfileNameLineEdit->setText(myFileName);
        } else {
            return;
        }
    }
    if (myRcvedBytes < myTotalBytes)
    {
        myRcvedBytes += myCntSocket->bytesAvailable();
        myInputBlock = myCntSocket->readAll();
        myLocPathFile->write(myInputBlock);
        myInputBlock.resize(0);
    }
    ui->recvProgressBar->setMaximum(myTotalBytes);
    ui->recvProgressBar->setValue(myRcvedBytes);
    double transpeed = myRcvedBytes / usedTime;
    ui->rfileSizeLineEdit->setText(tr("%1").arg(myTotalBytes / (1024 * 1024)) + " MB");
    ui->recvSizeLineEdit->setText(tr("%1").arg(myRcvedBytes / (1024 * 1024)) + " MB");
    ui->rateLabel->setText(tr("%1").arg(transpeed * 1000 / (1024 * 1024), 0, 'f', 2) + " MB/秒");
    if (myRcvedBytes == myTotalBytes)
    {
        myLocPathFile->close();
        myCntSocket->close();
        ui->rateLabel->setText("接收完毕！");
    }
}

void FileCntDlg::on_cntClosePushButton_clicked()
{
    myCntSocket->abort();
    myLocPathFile->close();
    close();
}

void FileCntDlg::closeEvent(QCloseEvent *)
{
    on_cntClosePushButton_clicked();
}
