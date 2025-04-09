/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QLabel *label;
    QPushButton *loginPushButton;
    QLineEdit *usrLineEdit;
    QLineEdit *pwdLineEdit;
    QLabel *label_2;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName("LoginDialog");
        LoginDialog->resize(280, 400);
        label = new QLabel(LoginDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 280, 400));
        label->setFrameShape(QFrame::Box);
        label->setFrameShadow(QFrame::Sunken);
        label->setPixmap(QPixmap(QString::fromUtf8("images/login.jpg")));
        loginPushButton = new QPushButton(LoginDialog);
        loginPushButton->setObjectName("loginPushButton");
        loginPushButton->setGeometry(QRect(36, 258, 212, 43));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font.setPointSize(10);
        font.setBold(true);
        loginPushButton->setFont(font);
        loginPushButton->setFlat(true);
        usrLineEdit = new QLineEdit(LoginDialog);
        usrLineEdit->setObjectName("usrLineEdit");
        usrLineEdit->setGeometry(QRect(85, 215, 113, 20));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font1.setPointSize(10);
        usrLineEdit->setFont(font1);
        usrLineEdit->setAlignment(Qt::AlignCenter);
        pwdLineEdit = new QLineEdit(LoginDialog);
        pwdLineEdit->setObjectName("pwdLineEdit");
        pwdLineEdit->setGeometry(QRect(85, 235, 113, 20));
        pwdLineEdit->setEchoMode(QLineEdit::Password);
        pwdLineEdit->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(LoginDialog);
        label_2->setObjectName("label_2");
        label_2->setEnabled(true);
        label_2->setGeometry(QRect(0, -40, 361, 461));

        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "\345\276\256 \344\277\241 \345\256\242 \346\210\267 \347\253\257", nullptr));
        label->setText(QString());
        loginPushButton->setText(QCoreApplication::translate("LoginDialog", "\347\231\273\345\275\225", nullptr));
        usrLineEdit->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
