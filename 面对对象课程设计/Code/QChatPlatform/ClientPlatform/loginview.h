#ifndef LOGINVIEW_H
#define LOGINVIEW_H

#include "stdafx.h"

namespace Ui {
class LoginView;
}

class LoginView : public QWidget
{
    Q_OBJECT

public:
    explicit LoginView(QWidget *parent = nullptr);
    ~LoginView();

    void paintEvent(QPaintEvent* event);
    void keyPressEvent(QKeyEvent *event);
    void setIdentification(QString identification);

signals:
    void loginAccount(QString name,QString password,QString identification);
    void registerAccount(QString name,QString password,QString identification);

private slots:
    void on_pushButtonLogin_clicked();
    void on_pushButtonRegister_clicked();

private:
    Ui::LoginView *ui;
};

#endif // LOGINVIEW_H
