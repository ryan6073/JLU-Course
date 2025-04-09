#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    clientName = "client name";
    client = NULL;
    //加载图片资源
    pixMap.load(":/Resource/background4.jpg");

    ui->sendBtn->setFixedHeight(ui->lineEditSend->height());
    ui->connectBtn->setFixedHeight(ui->lineEditAddress->height() * 1.5);
    ui->backgroundBtn->setFixedHeight(ui->lineEditAddress->height() * 1.5);
    ui->headBtn->setFixedSize(80,80);
    ui->sendBtn->setStyleSheet("QPushButton{border:0px}");
    ui->connectBtn->setStyleSheet("QPushButton{border:0px}");
    ui->backgroundBtn->setStyleSheet("QPushButton{border:0px}");
    ui->headBtn->setStyleSheet("QPushButton{border:0px}");
    ui->headBtn->setIcon(QPixmap(":/Resource/head.jpg"));
    ui->headBtn->setIconSize(ui->headBtn->size());

    ui->lineEditAddress->setText("127.0.0.1");
    ui->lineEditPort->setText(QString::number(9999));
    ui->lineEditName->setText(clientName);
    ui->lineEditAddress->setStyleSheet("QLineEdit{ background-color: rgba(252,252,252,120); }QLineEdit:focus{background-color: rgb(255,255,255)}"); // 设置样式
    ui->lineEditPort->setStyleSheet("QLineEdit{ background-color: rgba(252,252,252,120); }QLineEdit:focus{background-color: rgb(255,255,255)}"); // 设置样式
    ui->lineEditName->setStyleSheet("QLineEdit{ background-color: rgba(252,252,252,120); }QLineEdit:focus{background-color: rgb(255,255,255)}"); // 设置样式

    this->setWindowTitle(clientName);
    this->setWindowIcon(QPixmap(":/Resource/clientIcon.png"));
    ui->sendBtn->setEnabled(false);
    ui->chatRecord->setEnabled(false);
    ui->chatRecord->setStyleSheet("background:transparent");

    //监听文本编辑框
    connect(ui->lineEditAddress,&QLineEdit::textChanged,[=](){
        if(client)
        {
            delete(client);
            client = NULL;
        }
    });

    connect(ui->lineEditPort,&QLineEdit::textChanged,[=](){
        if(client)
        {
            delete(client);
            client = NULL;
        }
    });

    connect(ui->lineEditName,&QLineEdit::textChanged,[=](){
        clientName = ui->lineEditName->text();
        this->setWindowTitle(clientName);
    });

    //监听connect按钮
    connect(ui->connectBtn,&QPushButton::clicked,[=](){
        ui->connectBtn->setEnabled(false);
        //进行与服务器的连接
        client = new QTcpSocket(this);
        client->connectToHost(QHostAddress(ui->lineEditAddress->text()),ui->lineEditPort->text().toInt());
        //试图连接之后给服务器发送连接成功消息
        QByteArray tryConnectMessage = clientName.toUtf8();
        tryConnectMessage.append(" try to get a connection");
        ui->chatRecord->append(tryConnectMessage);

        connect(client,&QTcpSocket::stateChanged,[=](){
            if(client->state() == QAbstractSocket::ConnectedState)
            {
                //断开按钮
                ui->connectBtn->setText("Connected");
                ui->clientState->setText("在线状态：在线");
                //告诉服务器链接成功了
                QByteArray getConnectMessage = QTime::currentTime().toString("hh:mm:ss").toUtf8() + " " + clientName.toUtf8() + " come!";
                client->write(getConnectMessage);
                //恢复发送按钮
                ui->sendBtn->setEnabled(true);
            }
            else if(client->state() == QAbstractSocket::ClosingState)
            {
                //在客户端主动断开连接的时候如果流程是
                //1、client->close();
                //2、delete(client);
                //3、client = NULL;
                //那么状态也会从ConnectedState->ClosingState->UnconnectedState
                //就无法确定是服务器主动断开连接还是客户端主动断开
                //所以我们把上述的第一步省略，不去关闭连接，而是直接释放连接指针
                ui->chatRecord->append("Server stop listen");
            }
            else if(client->state() == QAbstractSocket::UnconnectedState)
            {
                ui->chatRecord->append("Can not get a connection");
                ui->connectBtn->setEnabled(true);
                ui->connectBtn->setText("Connect");
                ui->clientState->setText("在线状态：离线");
                ui->sendBtn->setEnabled(false);
            }
        });

        //给客户端发送数据
        connect(ui->sendBtn,&QPushButton::clicked,[=](){
            QByteArray sendMessage = ui->lineEditSend->text().toUtf8();
            //不允许发送空信息
            if(sendMessage != "")
            {
                QString finalMessage = QTime::currentTime().toString("hh:mm:ss") + " " + clientName + ": " + sendMessage;
                client->write(finalMessage.toUtf8());
                ui->lineEditSend->clear();
            }
        });

        //客户端接收数据
        connect(client,&QTcpSocket::readyRead,[=](){
            QByteArray readMessage = client->readAll();
            ui->chatRecord->append(readMessage);
        });
    });

    //监听更换头像按钮
    connect(ui->headBtn,&QPushButton::clicked,this,[=](){
        //弹出文件对话框
        QString fileName = QFileDialog::getOpenFileName(this,"选择头像");
        //用文件路径组成一个图片对象并设置按钮
        ui->headBtn->setIcon(QPixmap(fileName));
        //设置按钮的大小
        ui->headBtn->setIconSize(ui->headBtn->size());
    });

    //更换背景
    connect(ui->backgroundBtn,&QPushButton::clicked,this,[=](){
        QString fileName = ":/Resource/background";
        static int index = 1;
        if(index == 4)
        {
            index = 1;
        }
        else
        {
            index++;
        }
        fileName.append(QString::number(index)).append(".jpg");
        pixMap.load(fileName);
        update();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    //绘制背景图片，定义画家对象，形参指定this表示在当前窗体内开始绘图
    QPainter painter(this);
    //设置透明度
    painter.setOpacity(0.8);
    //在(0,0)开始画pixMap，图片的宽高跟主窗体一致
    painter.drawPixmap(0, 0, this->width(), this->height(), pixMap);
}
