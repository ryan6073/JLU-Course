#include "welcomewindow.h"
#include "ui_welcomewindow.h"

WelcomeWindow::WelcomeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(QStringLiteral("服务界面"));
    this->setWindowIcon(QPixmap(":/Resource/clientIcon.png"));

    ui->lineEditAddress->setText("127.0.0.1");
    ui->lineEditPort->setText(QString::number(9999));
    ui->pushButtonOpen->setEnabled(false);
}

WelcomeWindow::~WelcomeWindow()
{
    if (client)
    {
        delete client;
        client = NULL;
    }
    delete ui;
}

void WelcomeWindow::analysisJson(QVariantMap &map)
{
    if (map["function"] == "function")
    {
        if (map["operation"] == "open")
        {
            if(map["identification"] == ui->lineEditIdentification->text())
            {
                QString str;
                bool qq = map["qq"].toBool();
                bool wechat = map["wechat"].toBool();
                bool weibo = map["weibo"].toBool();
                QString result = map["result"].toString();
                if(result != "1")
                {
                    QMessageBox::information(this, QStringLiteral("系统消息"), QStringLiteral("选中服务开通失败"));
                    return;
                }
                if(qq)
                {
                    str.append(QStringLiteral("QQ "));
                }
                if(wechat)
                {
                    str.append(QStringLiteral("微信 "));
                }
                if(weibo)
                {
                    str.append(QStringLiteral("微博 "));
                }
                str.append(QStringLiteral("开通成功"));
                QMessageBox::information(this, QStringLiteral("系统消息"), str);
            }
        }
    }
}

void WelcomeWindow::on_pushButtonQQ_clicked()
{
    mainWindow.show();
}

void WelcomeWindow::on_pushButtonWeChat_clicked()
{
    wechatWindow.show();
}

void WelcomeWindow::on_pushButtonWeiBo_clicked()
{
    QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("功能开发中"));
}

void WelcomeWindow::on_connectBtn_clicked()
{
    if(!client || client->state() != QAbstractSocket::ConnectedState)
    {
        client = new QTcpSocket(this);
        client->connectToHost(QHostAddress(ui->lineEditAddress->text()), ui->lineEditPort->text().toInt());

        connect(client, &QTcpSocket::stateChanged, [=]() {
            if (client->state() == QAbstractSocket::ConnectedState)
            {
                //断开按钮
                ui->connectBtn->setText("ConnectedState");
                ui->connectBtn->setEnabled(false);
                ui->pushButtonOpen->setEnabled(true);
            }
            else if (client->state() == QAbstractSocket::ClosingState)
            {
                ui->connectBtn->setEnabled(true);
                ui->connectBtn->setText("Connect");
            }
            else if (client->state() == QAbstractSocket::UnconnectedState)
            {
                ui->connectBtn->setEnabled(true);
                ui->pushButtonOpen->setEnabled(false);
                ui->connectBtn->setText("Connect");
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
        });
    }
}

void WelcomeWindow::on_pushButtonOpen_clicked()
{
    QVariantMap map;
    map["function"] = "function";
    map["operation"] = "open";
    map["identification"] = ui->lineEditIdentification->text();
    map["qq"] = ui->checkBoxQQ->isChecked();
    map["wechat"]=ui->checkBoxWeChat->isChecked();
    map["weibo"] = ui->checkBoxWeiBo->isChecked();
    QString json = QJsonDocument::fromVariant(map).toJson();
    client->write(json.toUtf8());
}
