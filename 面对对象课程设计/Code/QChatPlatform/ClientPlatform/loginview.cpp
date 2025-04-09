#include "loginview.h"
#include "ui_loginview.h"

LoginView::LoginView(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::LoginView)
{
    ui->setupUi(this);

    this->setWindowTitle(QStringLiteral("系统登录"));

    ui->lineEditAccount->setStyleSheet(lineEditStyle);
    ui->lineEditPassword->setStyleSheet(lineEditStyle);
    ui->lineEditIdentification->setStyleSheet(lineEditStyle);
    ui->pushButtonLogin->setStyleSheet(buttonStyle);
    ui->pushButtonRegister->setStyleSheet(buttonStyle);
}

LoginView::~LoginView()
{
    delete ui;
}

void LoginView::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    QPixmap pixMap;
    pixMap.load(":/Resource/background4.jpg");
    painter.setOpacity(0.8);
    painter.drawPixmap(0, 0, this->width(), this->height(), pixMap);
}

void LoginView::keyPressEvent(QKeyEvent* event)
{
    switch (event->key())
    {
    case Qt::Key_Return:    //Enter键
    case Qt::Key_Enter:     //数字键盘的Enter键
        on_pushButtonLogin_clicked();
        break;
    default:
        break;
    }
}

void LoginView::setIdentification(QString identification)
{
    ui->lineEditIdentification->setText(identification);
}

void LoginView::on_pushButtonLogin_clicked()
{
    QString account = ui->lineEditAccount->text();
    QString password = ui->lineEditPassword->text();
    QString identification = ui->lineEditIdentification->text();
    emit loginAccount(account, password, identification);
}

void LoginView::on_pushButtonRegister_clicked()
{
    QString account = ui->lineEditAccount->text();
    QString password = ui->lineEditPassword->text();
    QString identification = ui->lineEditIdentification->text();
    emit registerAccount(account, password, identification);
}
