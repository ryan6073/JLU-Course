#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "datahandler.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEditAddress->setText("127.0.0.1");
    ui->lineEditPort->setText(QString::number(9999));

    ui->sendBtn->setFixedHeight(ui->lineEditSend->height());
    ui->listenBtn->setFixedHeight(ui->lineEditSend->height() * 2);
    ui->sendBtn->setStyleSheet("QPushButton{border:0px}");
    ui->listenBtn->setStyleSheet("QPushButton{border:0px}");

    ui->lineEditAddress->setStyleSheet("QLineEdit{ background-color: rgba(252,252,252,120); }QLineEdit:focus{background-color: rgb(255,255,255)}"); // 设置样式
    ui->lineEditPort->setStyleSheet("QLineEdit{ background-color: rgba(252,252,252,120); }QLineEdit:focus{background-color: rgb(255,255,255)}"); // 设置样式
    ui->lineEditSend->setStyleSheet("QLineEdit{ background-color: rgba(252,252,252,120); }QLineEdit:focus{background-color: rgb(255,255,255)}"); // 设置样式

    ui->chatRecord->setReadOnly(true);
    ui->chatRecord->setStyleSheet("background:transparent");

    this->setWindowTitle("Server");
    this->setWindowIcon(QPixmap(":/Resource/serverIcon.png"));

    //创建监听
    listen = new QTcpServer(this);

    //监听listen按钮信号
    connect(ui->listenBtn,&QPushButton::clicked,this,[=](){
        //设置监听事件
        listen->listen(QHostAddress(ui->lineEditAddress->text()),ui->lineEditPort->text().toInt());
        ui->chatRecord->append("Server listen success!");
        ui->listenBtn->setEnabled(false);
    });

    //监听IP地址以及端口号是否变化，如果变化，就开启监听按钮
    connect(ui->lineEditAddress,&QLineEdit::textChanged,[=](){
        ui->listenBtn->setEnabled(true);
        listen->close();
        for(int i = 0;i < connList.size();i++)
        {
            delete connList[i];
        }
        connList.clear();
        connectMap.clear();
        ui->chatRecord->append("IP changed!Server stop listen!");
    });
    connect(ui->lineEditPort,&QLineEdit::textChanged,[=](){
        ui->listenBtn->setEnabled(true);
        listen->close();
        for(int i = 0;i < connList.size();i++)
        {
            delete connList[i];
        }
        connList.clear();
        connectMap.clear();
        ui->chatRecord->append("Port changed!Server stop listen!");
    });

    //当有新的连接进来的时候监听信号
    connect(listen,&QTcpServer::newConnection,[=](){
        //定义一个TCPSocket*类型的对象
        QTcpSocket* conn = listen->nextPendingConnection();
        conn->write("[Server Say]server get your connection!");
        //为了保证conn一定是有效的连接，我们把消息读取函数放进信号监听的函数里
        //消息读取
        connect(conn,&QTcpSocket::readyRead,[=](){
            QByteArray readMessage = conn->readAll();

            if (!QJsonDocument::fromJson(readMessage).isObject())
            {
                distributeMessage(readMessage);
                appendFile(readMessage);
                //更新聊天记录窗口
                ui->chatRecord->append(readMessage);
            }
            else
            {
                QVariantMap map = QJsonDocument::fromJson(readMessage).toVariant().toMap();
                analysisJson(conn,map);
                ui->chatRecord->append(readMessage);
            }
        });
        connList.push_back(conn);
    });

    //实现服务器的消息群发
    connect(ui->sendBtn,&QPushButton::clicked,[=](){
        if(ui->lineEditSend->text() == "")
        {
            return ;
        }
        QByteArray sendMessage = "[Server Say]";
        sendMessage.append(ui->lineEditSend->text().toUtf8());
        distributeMessage(sendMessage);
        appendFile(sendMessage);
        //更新聊天记录窗口
        ui->chatRecord->append(sendMessage);
        //清空输入框
        ui->lineEditSend->clear();
    });

    DataHandler::GetInstance()->readQQ();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::appendFile(QString newMessage)
{
    QFile file("../QChatServer/Data/ChatRecord.txt");
    file.open(QIODevice::ReadWrite | QIODevice::Append);
    file.write(newMessage.toStdString().c_str());
    file.write("\r\n");
    file.close();
}

void MainWindow::distributeMessage(const QByteArray &data)
{
    if(data.isEmpty())
    {
        return;
    }
    for (int i = 0;i < connList.size();i++)
    {
        if(connList[i]->state() == QTcpSocket::UnconnectedState)
        {
            connectMap.remove(connList[i]);
            //如果有链接是无效的就移除
            delete connList[i];
            connList.removeAt(i);
        }
        connList[i]->write(data);
    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    //绘制背景图片，定义画家对象，形参指定this表示在当前窗体内开始绘图
    QPainter painter(this);
    //定义图片对象
    QPixmap pixMap;
    //加载图片资源
    pixMap.load(":/Resource/background.jpg");
    //设置透明度
    painter.setOpacity(0.8);
    //在(0,0)开始画pixMap，图片的宽高跟主窗体一致
    painter.drawPixmap(0, 0, this->width(), this->height(), pixMap);
}

void MainWindow::analysisJson(QTcpSocket *conn, QVariantMap& map)
{
    if(map["function"] == "qq")
    {
        QString account = map["account"].toString();
        if(map["operation"] == "register")
        {
            QString password = map["password"].toString();
            QString date = map["date"].toString();

            if(account.isEmpty() || password.isEmpty())
            {
                map["result"] = "0";
            }
            else if(DataHandler::GetInstance()->registerQQ(account,"user",date,password))
            {
                DataHandler::GetInstance()->writeQQ();
                map["result"] = "1";
            }
            else
            {
                map["result"] = "0";
            }
            conn->write(QJsonDocument::fromVariant(map).toJson());
        }
        else if(map["operation"] == "login")
        {
            QString password = map["password"].toString();
            if(DataHandler::GetInstance()->loginQQ(account,password))
            {
                connectMap[conn] = account;
                map["result"] = "1";
            }
            else
            {
                map["result"] = "0";
            }
            conn->write(QJsonDocument::fromVariant(map).toJson());
        }
        else if(map["operation"] == "query")
        {
            bool ret = false;
            QQInfo selfInfo = DataHandler::GetInstance()->queryQQ(account,ret);

            if(ret)
            {
                map["number"] = selfInfo.getNumber();
                map["password"] = selfInfo.getPassword();
                map["name"] = selfInfo.getName();
                map["identification"] = selfInfo.getIdentificationNumber();
                map["birth"] = selfInfo.getBirthDate();
                map["date"] = selfInfo.getRegister();
                map["place"] = selfInfo.getUserAddress();
                map["result"] = "1";
            }
            else
            {
                map["result"] = "0";
            }
            conn->write(QJsonDocument::fromVariant(map).toJson());
        }
        else if(map["operation"] == "update")
        {
            QString password = map["password"].toString();
            QString name = map["name"].toString();
            QString identification = map["identification"].toString();
            QString birth = map["birth"].toString();
            QString date = map["date"].toString();
            QString place = map["place"].toString();
            if(DataHandler::GetInstance()->updateQQ(account,name,date,password,identification,place,birth))
            {
                DataHandler::GetInstance()->writeQQ();
                map["result"] = "1";
            }
            else
            {
                map["result"] = "0";
            }
            conn->write(QJsonDocument::fromVariant(map).toJson());
        }
        else if(map["operation"] == "append")
        {
            QString friendNumber = map["friend"].toString();
            if(DataHandler::GetInstance()->addQQFriend(account,friendNumber))
            {
                DataHandler::GetInstance()->writeQQ();
                map["list"] = DataHandler::GetInstance()->getQQFriendList(account);
                map["result"] = "1";
            }
            else
            {
                map["result"] = "0";
            }
            conn->write(QJsonDocument::fromVariant(map).toJson());
        }
        else if(map["operation"] == "delete")
        {
            QString friendNumber = map["friend"].toString();
            if(DataHandler::GetInstance()->deleteQQFriend(account,friendNumber))
            {
                DataHandler::GetInstance()->writeQQ();
                map["list"] = DataHandler::GetInstance()->getQQFriendList(account);
                map["result"] = "1";
            }
            else
            {
                map["result"] = "0";
            }
            conn->write(QJsonDocument::fromVariant(map).toJson());
        }
        else if(map["operation"] == "alter")
        {
            QString friendNumber = map["friend"].toString();
            QString friendRemark = map["remark"].toString();
            if(DataHandler::GetInstance()->alterQQFriend(account,friendNumber,friendRemark))
            {
                DataHandler::GetInstance()->writeQQ();
                map["list"] = DataHandler::GetInstance()->getQQFriendList(account);
                map["result"] = "1";
            }
            else
            {
                map["result"] = "0";
            }
            conn->write(QJsonDocument::fromVariant(map).toJson());
        }
        else if(map["operation"] == "get")
        {
            bool ret = false;
            QQInfo selfInfo = DataHandler::GetInstance()->queryQQ(account,ret);

            if(ret)
            {
                map["list"] = DataHandler::GetInstance()->getQQFriendList(account);
                map["result"] = "1";
            }
            else
            {
                map["result"] = "0";
            }
            conn->write(QJsonDocument::fromVariant(map).toJson());
        }
        else if(map["operation"] == "chat")
        {
            QString friendNumber = map["friend"].toString();
            if(DataHandler::GetInstance()->isQQFriend(account,friendNumber))
            {
                map["friend"] = account;
                map["account"] = friendNumber;
                map["result"] = "1";
            }
            else
            {
                map["result"] = "0";
            }
            for(auto iter=connectMap.begin();iter!=connectMap.end();++iter)
            {
                if(iter.value() == friendNumber)
                {
                    (iter.key())->write(QJsonDocument::fromVariant(map).toJson());
                    break;
                }
            }
        }
    }
}
