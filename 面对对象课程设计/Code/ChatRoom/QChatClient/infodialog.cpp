#include "infodialog.h"
#include "ui_infodialog.h"

InfoDialog::InfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoDialog)
{
    ui->setupUi(this);
    ui->lineEditAccount->setReadOnly(true);
    ui->lineEditRegister->setReadOnly(true);
    ui->lineEditAccount->setStyleSheet(lineEditStyle);
    ui->lineEditPassword->setStyleSheet(lineEditStyle);
    ui->lineEditName->setStyleSheet(lineEditStyle);
    ui->lineEditIdentification->setStyleSheet(lineEditStyle);
    ui->lineEditBirth->setStyleSheet(lineEditStyle);
    ui->lineEditPlace->setStyleSheet(lineEditStyle);
    ui->lineEditRegister->setStyleSheet(lineEditStyle);

    ui->pushButtonUpdate->setStyleSheet(buttonStyle);
    ui->pushButtonClose->setStyleSheet(buttonStyle);

    this->setWindowTitle("个人信息");
    this->setWindowFlags(Qt::SubWindow | Qt::Dialog);
}

InfoDialog::~InfoDialog()
{
    delete ui;
}

void InfoDialog::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    QPixmap pixMap;
    pixMap.load(":/Resource/background4.jpg");
    painter.setOpacity(0.8);
    painter.drawPixmap(0, 0, this->width(), this->height(), pixMap);
}

void InfoDialog::setInfo(QString number, QString password, QString name, QString identification, QString birth, QString date, QString place)
{
    ui->lineEditAccount->setText(number);
    ui->lineEditPassword->setText(password);
    ui->lineEditName->setText(name);
    ui->lineEditIdentification->setText(identification);
    ui->lineEditBirth->setText(birth);
    ui->lineEditRegister->setText(date);
    ui->lineEditPlace->setText(place);
}

void InfoDialog::on_pushButtonUpdate_clicked()
{
    QString number =ui->lineEditAccount->text();
    QString password=ui->lineEditPassword->text();
    QString name=ui->lineEditName->text();
    QString identification=ui->lineEditIdentification->text();
    QString birth=ui->lineEditBirth->text();
    QString date=ui->lineEditRegister->text();
    QString place=ui->lineEditPlace->text();
    emit updateInfo(number,password,name,identification,birth,date,place);
}

void InfoDialog::on_pushButtonClose_clicked()
{
    this->close();
}
