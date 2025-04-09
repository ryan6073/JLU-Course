/********************************************************************************
** Form generated from reading UI file 'loginview.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINVIEW_H
#define UI_LOGINVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginView
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEditAccount;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEditPassword;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonLogin;
    QPushButton *pushButtonRegister;

    void setupUi(QWidget *LoginView)
    {
        if (LoginView->objectName().isEmpty())
            LoginView->setObjectName("LoginView");
        LoginView->resize(400, 200);
        verticalLayout = new QVBoxLayout(LoginView);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(LoginView);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267")});
        font.setPointSize(11);
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        lineEditAccount = new QLineEdit(LoginView);
        lineEditAccount->setObjectName("lineEditAccount");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223")});
        font1.setPointSize(11);
        lineEditAccount->setFont(font1);

        horizontalLayout_2->addWidget(lineEditAccount);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_2 = new QLabel(LoginView);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        horizontalLayout_3->addWidget(label_2);

        lineEditPassword = new QLineEdit(LoginView);
        lineEditPassword->setObjectName("lineEditPassword");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223")});
        font2.setPointSize(11);
        font2.setStyleStrategy(QFont::PreferDefault);
        lineEditPassword->setFont(font2);
        lineEditPassword->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(lineEditPassword);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButtonLogin = new QPushButton(LoginView);
        pushButtonLogin->setObjectName("pushButtonLogin");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267")});
        font3.setPointSize(12);
        pushButtonLogin->setFont(font3);

        horizontalLayout->addWidget(pushButtonLogin);

        pushButtonRegister = new QPushButton(LoginView);
        pushButtonRegister->setObjectName("pushButtonRegister");
        pushButtonRegister->setFont(font3);

        horizontalLayout->addWidget(pushButtonRegister);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(LoginView);

        QMetaObject::connectSlotsByName(LoginView);
    } // setupUi

    void retranslateUi(QWidget *LoginView)
    {
        LoginView->setWindowTitle(QCoreApplication::translate("LoginView", "Form", nullptr));
        label->setText(QCoreApplication::translate("LoginView", "\350\264\246\346\210\267\347\274\226\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("LoginView", "\347\231\273\345\275\225\345\257\206\347\240\201", nullptr));
        pushButtonLogin->setText(QCoreApplication::translate("LoginView", "\347\231\273\345\275\225", nullptr));
        pushButtonRegister->setText(QCoreApplication::translate("LoginView", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginView: public Ui_LoginView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINVIEW_H
