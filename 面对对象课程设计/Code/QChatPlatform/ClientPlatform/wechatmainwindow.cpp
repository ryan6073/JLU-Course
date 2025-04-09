#include "wechatmainwindow.h"
#include "ui_wechatmainwindow.h"

#include "datahandler.h"

WeChatMainWindow::WeChatMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WeChatMainWindow)
{
    ui->setupUi(this);

    clientName = "client name";
    client = NULL;
    //加载图片资源
    pixMap.load(":/Resource/background4.jpg");

    ui->pushButtonGroupSend->setFixedHeight(ui->lineEditGroupSend->height());
    ui->connectBtn->setFixedHeight(ui->lineEditAddress->height() * 1.5);
    ui->pushButtonLogin->setFixedHeight(ui->lineEditAddress->height() * 1.5);
    ui->pushButtonGroupSend->setStyleSheet("QPushButton{border:0px}");
    ui->connectBtn->setStyleSheet("QPushButton{border:0px}");
    ui->pushButtonLogin->setStyleSheet("QPushButton{border:0px}");

    ui->lineEditAddress->setText("127.0.0.1");
    ui->lineEditPort->setText(QString::number(9999));
    ui->lineEditName->setText(clientName);
    ui->lineEditAddress->setStyleSheet("QLineEdit{ background-color: rgba(252,252,252,120); }QLineEdit:focus{background-color: rgb(255,255,255)}"); // 设置样式
    ui->lineEditPort->setStyleSheet("QLineEdit{ background-color: rgba(252,252,252,120); }QLineEdit:focus{background-color: rgb(255,255,255)}"); // 设置样式
    ui->lineEditName->setStyleSheet("QLineEdit{ background-color: rgba(252,252,252,120); }QLineEdit:focus{background-color: rgb(255,255,255)}"); // 设置样式

    this->setWindowTitle(clientName);
    this->setWindowIcon(QPixmap(":/Resource/clientIcon.png"));
    ui->pushButtonGroupSend->setEnabled(false);
    ui->chatRecord->setReadOnly(true);
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

    connect(&loginView, SIGNAL(loginAccount(QString, QString,QString)), this, SLOT(loginAccount(QString, QString,QString)));
    connect(&loginView, SIGNAL(registerAccount(QString, QString,QString)), this, SLOT(registerAccount(QString, QString,QString)));

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
                ui->pushButtonGroupSend->setEnabled(true);
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
                ui->pushButtonGroupSend->setEnabled(false);
            }
        });

        //给客户端发送数据
        connect(ui->pushButtonGroupSend,&QPushButton::clicked,[=](){
            QByteArray sendMessage = ui->lineEditGroupSend->text().toUtf8();
            //不允许发送空信息
            if(sendMessage != "")
            {
                QString finalMessage = QTime::currentTime().toString("hh:mm:ss") + " " + clientName + ": " + sendMessage;
                client->write(finalMessage.toUtf8());
                ui->lineEditGroupSend->clear();
            }
        });

        //客户端接收数据
        connect(client,&QTcpSocket::readyRead,[=](){
            QByteArray readMessage = client->readAll();
            if (QJsonDocument::fromJson(readMessage).isObject())
            {
                QVariantMap map = QJsonDocument::fromJson(readMessage).toVariant().toMap();
                analysisJson(map);
            }
            else
            {
                ui->chatRecord->append(readMessage);
            }
        });
    });
}

WeChatMainWindow::~WeChatMainWindow()
{
    delete ui;
}

void WeChatMainWindow::paintEvent(QPaintEvent *event)
{
    //绘制背景图片，定义画家对象，形参指定this表示在当前窗体内开始绘图
    QPainter painter(this);
    //设置透明度
    painter.setOpacity(0.8);
    //在(0,0)开始画pixMap，图片的宽高跟主窗体一致
    painter.drawPixmap(0, 0, this->width(), this->height(), pixMap);
}

void WeChatMainWindow::analysisJson(QVariantMap& map)
{
    if (map["function"] == "wechat")
    {
        if (map["operation"] == "login")
        {
            if (map["account"] == tryAccount && (map["password"] == tryPassword || map["password"] == "auto"))
            {
                if (map["result"] == "1")
                {
                    QMessageBox::information(this, QStringLiteral("系统消息"), QString(QStringLiteral("[%1]登录成功")).arg(tryAccount));
                    currentUser = tryAccount;
                    DataHandler::GetInstance()->currentWeChat = map["identification"].toString();
                    ui->pushButtonGroupSend->setEnabled(true);
                    ui->connectBtn->setText("Online");
                    ui->connectBtn->setEnabled(false);
                    ui->clientState->setText("在线状态：在线");
                }
                else
                {
                    QMessageBox::warning(this, QStringLiteral("系统消息"), QString(QStringLiteral("[%1]登录失败")).arg(tryAccount));
                    currentUser = "";
                }
                loginView.hide();
            }
        }
        else if (map["operation"] == "register")
        {
            if (map["account"] == tryAccount && map["password"] == tryPassword)
            {
                if (map["result"] == "1")
                {
                    QMessageBox::information(this, QStringLiteral("系统消息"), QString(QStringLiteral("[%1]注册成功")).arg(tryAccount));
                    currentUser = tryAccount;
                }
                else
                {
                    QMessageBox::warning(this, QStringLiteral("系统消息"), QString(QStringLiteral("[%1]注册失败")).arg(tryAccount));
                    currentUser = "";
                }
                loginView.hide();
            }
        }
    }
}

void WeChatMainWindow::loginAccount(QString account, QString password,QString identification)
{
    tryAccount = account;
    tryPassword = password;

    QVariantMap map;
    map["function"] = "wechat";
    map["operation"] = "login";
    map["account"] = account;
    if(identification == DataHandler::GetInstance()->currentQQ && !DataHandler::GetInstance()->currentQQ.isEmpty())
    {
        QMessageBox::information(this,QStringLiteral("系统消息"), QStringLiteral("您的QQ已登录，微信自动登录"));
        map["password"] = "auto";
    }
    else
    {
         map["password"] = password;
    }

    QString json = QJsonDocument::fromVariant(map).toJson();
    client->write(json.toUtf8());
    loginView.hide();
}

void WeChatMainWindow::registerAccount(QString account, QString password,QString identification)
{
    tryAccount = account;
    tryPassword = password;

    QVariantMap map;
    map["function"] = "wechat";
    map["operation"] = "register";
    map["account"] = account;
    map["password"] = password;
    map["identification"] = identification;
    map["date"] = QDate::currentDate().toString("yyyy-MM-dd");
    QString json = QJsonDocument::fromVariant(map).toJson();
    client->write(json.toUtf8());
}

void WeChatMainWindow::on_pushButtonLogin_clicked()
{
    if(!client)
    {
        QMessageBox::information(this,QStringLiteral("系统消息"), QStringLiteral("请先连接服务器"));
        return;
    }
    if(!DataHandler::GetInstance()->currentQQ.isEmpty())
    {
        loginView.setIdentification(DataHandler::GetInstance()->currentQQ);
    }
    loginView.show();
}
