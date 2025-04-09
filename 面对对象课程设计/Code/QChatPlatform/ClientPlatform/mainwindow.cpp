#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "datahandler.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setQssStyle();

    clientName = "user";
    pixMap.load(":/Resource/background4.jpg");

    ui->toolBox->setStyleSheet("background:transparent");

    ui->headBtn->setFixedSize(80, 80);
    ui->pushButtonFriendSend->setStyleSheet(buttonStyle);
    ui->pushButtonGroupSend->setStyleSheet(buttonStyle);
    ui->connectBtn->setStyleSheet(buttonStyle);
    ui->backgroundBtn->setStyleSheet(buttonStyle);
    ui->headBtn->setStyleSheet("QPushButton{border:0px}");
    ui->headBtn->setIcon(QPixmap(":/Resource/head.jpg"));
    ui->headBtn->setIconSize(ui->headBtn->size());

    ui->lineEditAddress->setText("127.0.0.1");
    ui->lineEditPort->setText(QString::number(9999));
    ui->lineEditName->setText(clientName);
    ui->lineEditAddress->setStyleSheet(lineEditStyle);
    ui->lineEditPort->setStyleSheet(lineEditStyle);
    ui->lineEditName->setStyleSheet(lineEditStyle);

    ui->lineEditGroupSend->setStyleSheet(lineEditStyle);
    ui->lineEditFriendSend->setStyleSheet(lineEditStyle);

    this->setWindowTitle(clientName);
    this->setWindowIcon(QPixmap(":/Resource/clientIcon.png"));
    ui->pushButtonGroupSend->setEnabled(false);
    ui->pushButtonFriendSend->setEnabled(false);
    ui->chatRecord->setReadOnly(true);
    ui->chatRecord->setStyleSheet("background:transparent");
    ui->treeWidget->header()->setFont(QFont(QStringLiteral("楷体")));

    connect(&loginView, SIGNAL(loginAccount(QString, QString,QString)), this, SLOT(loginAccount(QString, QString,QString)));
    connect(&loginView, SIGNAL(registerAccount(QString, QString,QString)), this, SLOT(registerAccount(QString, QString,QString)));
    connect(&infoDialog, SIGNAL(updateInfo(QString, QString, QString, QString, QString,QString,QString)), this,
            SLOT(updateInfo(QString, QString, QString, QString, QString,QString,QString)));

}

MainWindow::~MainWindow()
{
    if (client)
    {
        QByteArray getConnectMessage = QTime::currentTime().toString("hh:mm:ss").toUtf8() + QStringLiteral(" [聊天室]").toUtf8()
            + clientName.toUtf8() + QStringLiteral(" 断开连接!").toUtf8();
        client->write(getConnectMessage);

        QEventLoop loop;
        QTimer::singleShot(1000, &loop,SLOT(quit()));
        loop.exec();

        delete client;
        client = NULL;
    }
    delete ui;
}

void MainWindow::setQssStyle()
{
    QString qss;
    QFile file(":/qss/lightblue.css");
    if(file.open(QFile::ReadOnly))
    {
        QStringList list;
        QTextStream in(&file);
        while(!in.atEnd())
        {
            QString line;
            in >> line;
            list << line;
        }
        qss = list.join("\n");

        QString paletteColor = qss.mid(20, 7);
        qApp->setPalette(QPalette(QColor(paletteColor)));
        qApp->setStyleSheet(qss);
        file.close();
    }
}

void MainWindow::paintEvent(QPaintEvent* event)
{
    //绘制背景图片，定义画家对象，形参指定this表示在当前窗体内开始绘图
    QPainter painter(this);
    //设置透明度
    painter.setOpacity(0.8);
    //在(0,0)开始画pixMap，图片的宽高跟主窗体一致
    painter.drawPixmap(0, 0, this->width(), this->height(), pixMap);
}

void MainWindow::analysisJson(QVariantMap& map)
{
    if (map["function"] == "qq")
    {
        if (map["operation"] == "login")
        {
            if (map["account"] == tryAccount && (map["password"] == tryPassword || map["password"] == "auto"))
            {
                if (map["result"] == "1")
                {
                    QMessageBox::information(this, QStringLiteral("系统消息"), QString(QStringLiteral("[%1]登录成功")).arg(tryAccount));
                    currentUser = tryAccount;
                    DataHandler::GetInstance()->currentQQ = map["identification"].toString();
                    ui->pushButtonGroupSend->setEnabled(true);
                    ui->pushButtonFriendSend->setEnabled(true);
                    ui->connectBtn->setText("Online");
                    ui->connectBtn->setEnabled(false);
                    ui->clientState->setText(QStringLiteral("在线状态：在线"));
                    ui->lineEditName->setReadOnly(true);

                    QVariantMap request;
                    request["function"] = "qq";
                    request["operation"] = "query";
                    request["account"] = currentUser;
                    QString json = QJsonDocument::fromVariant(request).toJson();
                    client->write(json.toUtf8());
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
        else if (map["operation"] == "append" || map["operation"] == "delete" || map["operation"] == "alter" || map["operation"] == "get")
        {
            QString operation = "未知操作";
            if (map["operation"] == "append")
            {
                operation = "添加好友";
            }
            else if (map["operation"] == "delete")
            {
                operation = "删除好友";
            }
            else if (map["operation"] == "alter")
            {
                operation = "修改备注";
            }
            else if (map["operation"] == "get")
            {
                operation = "刷新列表";
            }
            if (map["account"] == currentUser && map["result"] == "1")
            {
                ui->treeWidget->clear();
                QJsonValue value = map.value("list").toJsonValue();
                QVariantMap friendMap = value.toVariant().toMap();
                for(auto iter = friendMap.begin();iter!=friendMap.end();++iter)
                {
                    QString number = iter.key();
                    QString remark = iter.value().toString();
                    QTreeWidgetItem* newItem = new QTreeWidgetItem(ui->treeWidget, QStringList() << number << remark);
                    Q_UNUSED(newItem);
                }
                QMessageBox::information(this, QStringLiteral("系统消息"), operation + QStringLiteral("成功"));
            }
            else
            {
                QMessageBox::information(this, QStringLiteral("系统消息"), operation + QStringLiteral("失败"));
            }
        }
        else if (map["operation"] == "query")
        {
            if (map["account"] == currentUser && map["result"] == "1")
            {
                QString number = map["number"].toString();
                QString password = map["password"].toString();
                QString name = map["name"].toString();
                QString identification = map["identification"].toString();
                QString birth = map["birth"].toString();
                QString date = map["date"].toString();
                QString place = map["place"].toString();
                clientName = name;
                ui->lineEditName->setText(clientName);
                if(isQueryOperation)
                {
                    infoDialog.setInfo(number,password,name,identification, birth, date, place);
                    infoDialog.show();
                }
                isQueryOperation = false;
            }
        }
        else if (map["operation"] == "update")
        {
            if (map["account"] == currentUser && map["result"] == "1")
            {
                QMessageBox::information(this, QStringLiteral("系统消息"), QStringLiteral("更新个人信息成功"));
                infoDialog.close();

                QVariantMap request;
                request["function"] = "qq";
                request["operation"] = "query";
                request["account"] = currentUser;
                QString json = QJsonDocument::fromVariant(request).toJson();
                client->write(json.toUtf8());
            }
            else
            {
                QMessageBox::information(this, QStringLiteral("系统消息"), QStringLiteral("更新个人信息失败"));
            }
        }
        else if (map["operation"] == "chat")
        {
            if (map["account"] == currentUser && map["result"] == "1")
            {
                QString friendNumber = map["friend"].toString();
                QString message = map["message"].toString();
                QTreeWidgetItemIterator iter(ui->treeWidget);
                while (*iter)
                {
                    if ((*iter)->text(0) == friendNumber)
                    {
                        (*iter)->setText(2, message);
                        QString original = (*iter)->data(2,Qt::UserRole + 1).toString();
                        (*iter)->setData(2,Qt::UserRole + 1,original + message);
                        break;
                    }
                }
            }
        }
    }
}

void MainWindow::on_treeWidget_customContextMenuRequested(const QPoint& pos)
{
    Q_UNUSED(pos);

    if (currentUser.isEmpty())
    {
        return;
    }
    QMenu menu;
    QAction* addFriend = menu.addAction("添加好友");
    QAction* alterFriend = menu.addAction("修改好友");
    QAction* refreshFriend = menu.addAction("刷新列表");

    QAction* deleteFriend = 0;
    if (ui->treeWidget->currentItem())
    {
        deleteFriend = menu.addAction("删除好友");
    }
    QAction* ret = menu.exec(QCursor::pos());
    if (!ret)
    {
        return;
    }
    if (ret == addFriend)
    {
        QString number = QInputDialog::getText(this, QStringLiteral("号码查找"), QStringLiteral("请输入需要查找的QQ号"));
        if (!number.isEmpty())
        {
            QVariantMap map;
            map["function"] = "qq";
            map["operation"] = "append";
            map["account"] = currentUser;
            map["friend"] = number;
            QString json = QJsonDocument::fromVariant(map).toJson();
            client->write(json.toUtf8());
        }
    }
    else if (ret == deleteFriend)
    {
        QVariantMap map;
        map["function"] = "qq";
        map["operation"] = "delete";
        map["account"] = currentUser;
        map["friend"] = ui->treeWidget->currentItem()->text(0);
        QString json = QJsonDocument::fromVariant(map).toJson();
        client->write(json.toUtf8());
    }
    else if (ret == alterFriend)
    {
        QString remark = QInputDialog::getText(this, "号码查找", "请输入新的备注");
        if(!remark.isEmpty())
        {
            QVariantMap map;
            map["function"] = "qq";
            map["operation"] = "alter";
            map["account"] = currentUser;
            map["friend"] = ui->treeWidget->currentItem()->text(0);
            map["remark"] = remark;
            QString json = QJsonDocument::fromVariant(map).toJson();
            client->write(json.toUtf8());
        }
    }
    else if (ret == refreshFriend)
    {
        QVariantMap map;
        map["function"] = "qq";
        map["operation"] = "get";
        map["account"] = currentUser;
        QString json = QJsonDocument::fromVariant(map).toJson();
        client->write(json.toUtf8());
    }
}

void MainWindow::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    QString history = item->data(2,Qt::UserRole + 1).toString();
    QPlainTextEdit* plainText = new QPlainTextEdit();
    plainText->setWindowTitle(clientName + " && " + item->text(1));
    plainText->setReadOnly(true);
    plainText->setAttribute(Qt::WA_DeleteOnClose);
    plainText->setPlainText(history);
    plainText->show();
}

void MainWindow::on_headBtn_clicked()
{
    //弹出文件对话框
    QString fileName = QFileDialog::getOpenFileName(this, "选择头像");
    if (fileName.isEmpty())
    {
        return;
    }
    //用文件路径组成一个图片对象并设置按钮
    ui->headBtn->setIcon(QPixmap(fileName));
    //设置按钮的大小
    ui->headBtn->setIconSize(ui->headBtn->size());
}

void MainWindow::on_backgroundBtn_clicked()
{
    QString fileName = ":/Resource/background";
    static int index = 1;
    if (index == 4)
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
}

void MainWindow::on_connectBtn_clicked()
{   
    //进行与服务器的连接
    if(!client || client->state() != QAbstractSocket::ConnectedState)
    {
        client = new QTcpSocket(this);
        client->connectToHost(QHostAddress(ui->lineEditAddress->text()), ui->lineEditPort->text().toInt());
        //试图连接之后给服务器发送连接成功消息
        QByteArray tryConnectMessage = clientName.toUtf8();
        tryConnectMessage.append(" try to get a connection");
        ui->chatRecord->append(tryConnectMessage);

        connect(client, &QTcpSocket::stateChanged, [=]() {
            if (client->state() == QAbstractSocket::ConnectedState)
            {
                //断开按钮
                ui->connectBtn->setText("Connected");
                ui->clientState->setText(QStringLiteral("在线状态：待登录"));
                //告诉服务器链接成功了
                QByteArray getConnectMessage = QDateTime::currentDateTime()
                        .toString("yyyy-MM-dd hh:mm:ss").toUtf8() + " [聊天室]" + clientName.toUtf8() + " 连接!";
                client->write(getConnectMessage);
                //恢复发送按钮
                ui->pushButtonGroupSend->setEnabled(true);

                //loginView.show();
            }
            else if (client->state() == QAbstractSocket::ClosingState)
            {
                ui->chatRecord->append("Server stop listen");
            }
            else if (client->state() == QAbstractSocket::UnconnectedState)
            {
                ui->chatRecord->append("Can not get a connection");
                ui->connectBtn->setEnabled(true);
                ui->connectBtn->setText("Connect");
                ui->clientState->setText("在线状态：离线");
                ui->pushButtonGroupSend->setEnabled(false);
            }
        });

        //客户端接收数据
        connect(client, &QTcpSocket::readyRead, [=]() {
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
    }
    else
    {
        if(!DataHandler::GetInstance()->currentWeChat.isEmpty())
        {
            loginView.setIdentification(DataHandler::GetInstance()->currentWeChat);
        }
        loginView.show();
    }
}

void MainWindow::on_pushButtonFriendSend_clicked()
{
    QTreeWidgetItem* currentFriend = ui->treeWidget->currentItem();
    if (currentFriend)
    {
        QVariantMap map;
        map["function"] = "qq";
        map["operation"] = "chat";
        map["account"] = currentUser;
        map["friend"] = currentFriend->text(0);
        map["message"] = QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss]")
                + clientName + ": " + ui->lineEditFriendSend->text() + "\n";

        QString original = currentFriend->data(2,Qt::UserRole + 1).toString();
        currentFriend->setData(2,Qt::UserRole + 1,original + map["message"].toString());

        QString json = QJsonDocument::fromVariant(map).toJson();
        client->write(json.toUtf8());
    }
}

void MainWindow::on_pushButtonGroupSend_clicked()
{
    QByteArray sendMessage = ui->lineEditGroupSend->text().toUtf8();
    //不允许发送空信息
    if (sendMessage != "")
    {
        QString finalMessage = QTime::currentTime().toString("hh:mm:ss") + " " + clientName + ": " + sendMessage;
        client->write(finalMessage.toUtf8());
        ui->lineEditGroupSend->clear();
    }
}

void MainWindow::on_lineEditAddress_textChanged(const QString& arg1)
{
    if (client)
    {
        //在客户端主动断开连接的时候如果流程是
        //1、client->close();
        //2、delete(client);
        //3、client = NULL;
        //那么状态也会从ConnectedState->ClosingState->UnconnectedState
        //就无法确定是服务器主动断开连接还是客户端主动断开
        //所以我们把上述的第一步省略，不去关闭连接，而是直接释放连接指针
        delete(client);
        client = NULL;
    }
}

void MainWindow::on_lineEditPort_textChanged(const QString& arg1)
{
    if (client)
    {
        delete(client);
        client = NULL;
    }
}

void MainWindow::on_lineEditName_textChanged(const QString& arg1)
{
    clientName = ui->lineEditName->text();
    this->setWindowTitle(clientName);
}

void MainWindow::on_headBtn_customContextMenuRequested(const QPoint &pos)
{
    Q_UNUSED(pos);

    QMenu menu;
    QAction* changeHead = nullptr;
    QAction* alterInfo = nullptr;

    if (!currentUser.isEmpty())
    {
        changeHead = menu.addAction("更换头像");
        alterInfo = menu.addAction("信息修改");
    }

    QAction* ret = menu.exec(QCursor::pos());
    if (!ret)
    {
        return;
    }
    if (ret == changeHead)
    {
        //弹出文件对话框
        QString fileName = QFileDialog::getOpenFileName(this, "选择头像");
        if (fileName.isEmpty())
        {
            return;
        }
        //用文件路径组成一个图片对象并设置按钮
        ui->headBtn->setIcon(QPixmap(fileName));
        //设置按钮的大小
        ui->headBtn->setIconSize(ui->headBtn->size());
    }
    else if (ret == alterInfo)
    {
        QVariantMap map;
        map["function"] = "qq";
        map["operation"] = "query";
        map["account"] = currentUser;
        QString json = QJsonDocument::fromVariant(map).toJson();
        client->write(json.toUtf8());
        isQueryOperation = true;
    }
}

void MainWindow::loginAccount(QString account, QString password,QString identification)
{
    tryAccount = account;
    tryPassword = password;

    QVariantMap map;
    map["function"] = "qq";
    map["operation"] = "login";
    map["account"] = account;

    if(identification == DataHandler::GetInstance()->currentWeChat && !DataHandler::GetInstance()->currentWeChat.isEmpty())
    {
        QMessageBox::information(this, QStringLiteral("系统消息"), QStringLiteral("您的微信已登录，QQ自动登录"));
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

void MainWindow::registerAccount(QString account, QString password,QString identification)
{
    tryAccount = account;
    tryPassword = password;

    QVariantMap map;
    map["function"] = "qq";
    map["operation"] = "register";
    map["account"] = account;
    map["password"] = password;
    map["identification"] = identification;
    map["date"] = QDate::currentDate().toString("yyyy-MM-dd");
    QString json = QJsonDocument::fromVariant(map).toJson();
    client->write(json.toUtf8());
}

void MainWindow::updateInfo(QString number, QString password, QString name, QString identification, QString birth, QString date, QString place)
{
    QVariantMap map;
    map["function"] = "qq";
    map["operation"] = "update";
    map["account"] = number;
    map["password"] = password;
    map["name"] = name;
    map["identification"] = identification;
    map["birth"] = birth;
    map["date"] = date;
    map["place"] = place;
    QString json = QJsonDocument::fromVariant(map).toJson();
    client->write(json.toUtf8());
}
