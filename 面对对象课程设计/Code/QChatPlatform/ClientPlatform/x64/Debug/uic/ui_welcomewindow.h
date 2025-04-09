/********************************************************************************
** Form generated from reading UI file 'welcomewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOMEWINDOW_H
#define UI_WELCOMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WelcomeWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *lineEditAddress;
    QLabel *label_2;
    QLineEdit *lineEditPort;
    QPushButton *connectBtn;
    QGroupBox *groupBoxOpen;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditIdentification;
    QCheckBox *checkBoxQQ;
    QCheckBox *checkBoxWeChat;
    QCheckBox *checkBoxWeiBo;
    QPushButton *pushButtonOpen;
    QGroupBox *groupBoxLogin;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButtonQQ;
    QPushButton *pushButtonWeChat;
    QPushButton *pushButtonWeiBo;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WelcomeWindow)
    {
        if (WelcomeWindow->objectName().isEmpty())
            WelcomeWindow->setObjectName("WelcomeWindow");
        WelcomeWindow->resize(500, 350);
        centralwidget = new QWidget(WelcomeWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\351\232\266\344\271\246")});
        font.setPointSize(12);
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        lineEditAddress = new QLineEdit(centralwidget);
        lineEditAddress->setObjectName("lineEditAddress");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEditAddress->sizePolicy().hasHeightForWidth());
        lineEditAddress->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223")});
        font1.setPointSize(9);
        lineEditAddress->setFont(font1);

        gridLayout->addWidget(lineEditAddress, 0, 1, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEditPort = new QLineEdit(centralwidget);
        lineEditPort->setObjectName("lineEditPort");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\351\232\266\344\271\246")});
        font2.setPointSize(9);
        lineEditPort->setFont(font2);

        gridLayout->addWidget(lineEditPort, 1, 1, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);

        connectBtn = new QPushButton(centralwidget);
        connectBtn->setObjectName("connectBtn");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(connectBtn->sizePolicy().hasHeightForWidth());
        connectBtn->setSizePolicy(sizePolicy1);
        QFont font3;
        font3.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\351\232\266\344\271\246")});
        font3.setPointSize(10);
        connectBtn->setFont(font3);

        horizontalLayout_2->addWidget(connectBtn);


        verticalLayout_3->addLayout(horizontalLayout_2);

        groupBoxOpen = new QGroupBox(centralwidget);
        groupBoxOpen->setObjectName("groupBoxOpen");
        verticalLayout = new QVBoxLayout(groupBoxOpen);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(groupBoxOpen);
        label->setObjectName("label");
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(label);

        lineEditIdentification = new QLineEdit(groupBoxOpen);
        lineEditIdentification->setObjectName("lineEditIdentification");
        sizePolicy.setHeightForWidth(lineEditIdentification->sizePolicy().hasHeightForWidth());
        lineEditIdentification->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lineEditIdentification);


        verticalLayout->addLayout(horizontalLayout);

        checkBoxQQ = new QCheckBox(groupBoxOpen);
        checkBoxQQ->setObjectName("checkBoxQQ");
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(checkBoxQQ->sizePolicy().hasHeightForWidth());
        checkBoxQQ->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(checkBoxQQ);

        checkBoxWeChat = new QCheckBox(groupBoxOpen);
        checkBoxWeChat->setObjectName("checkBoxWeChat");
        sizePolicy3.setHeightForWidth(checkBoxWeChat->sizePolicy().hasHeightForWidth());
        checkBoxWeChat->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(checkBoxWeChat);

        checkBoxWeiBo = new QCheckBox(groupBoxOpen);
        checkBoxWeiBo->setObjectName("checkBoxWeiBo");
        sizePolicy3.setHeightForWidth(checkBoxWeiBo->sizePolicy().hasHeightForWidth());
        checkBoxWeiBo->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(checkBoxWeiBo);

        pushButtonOpen = new QPushButton(groupBoxOpen);
        pushButtonOpen->setObjectName("pushButtonOpen");

        verticalLayout->addWidget(pushButtonOpen);


        verticalLayout_3->addWidget(groupBoxOpen);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 3);

        horizontalLayout_3->addLayout(verticalLayout_3);

        groupBoxLogin = new QGroupBox(centralwidget);
        groupBoxLogin->setObjectName("groupBoxLogin");
        verticalLayout_2 = new QVBoxLayout(groupBoxLogin);
        verticalLayout_2->setObjectName("verticalLayout_2");
        pushButtonQQ = new QPushButton(groupBoxLogin);
        pushButtonQQ->setObjectName("pushButtonQQ");

        verticalLayout_2->addWidget(pushButtonQQ);

        pushButtonWeChat = new QPushButton(groupBoxLogin);
        pushButtonWeChat->setObjectName("pushButtonWeChat");

        verticalLayout_2->addWidget(pushButtonWeChat);

        pushButtonWeiBo = new QPushButton(groupBoxLogin);
        pushButtonWeiBo->setObjectName("pushButtonWeiBo");

        verticalLayout_2->addWidget(pushButtonWeiBo);


        horizontalLayout_3->addWidget(groupBoxLogin);

        horizontalLayout_3->setStretch(0, 2);
        horizontalLayout_3->setStretch(1, 1);

        verticalLayout_4->addLayout(horizontalLayout_3);

        WelcomeWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WelcomeWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 500, 23));
        WelcomeWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(WelcomeWindow);
        statusbar->setObjectName("statusbar");
        WelcomeWindow->setStatusBar(statusbar);

        retranslateUi(WelcomeWindow);

        QMetaObject::connectSlotsByName(WelcomeWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WelcomeWindow)
    {
        WelcomeWindow->setWindowTitle(QCoreApplication::translate("WelcomeWindow", "MainWindow", nullptr));
        label_3->setText(QCoreApplication::translate("WelcomeWindow", "Address", nullptr));
        label_2->setText(QCoreApplication::translate("WelcomeWindow", "Port", nullptr));
        lineEditPort->setText(QString());
        connectBtn->setText(QCoreApplication::translate("WelcomeWindow", "connect", nullptr));
        groupBoxOpen->setTitle(QCoreApplication::translate("WelcomeWindow", "\345\274\200\351\200\232\346\234\215\345\212\241", nullptr));
        label->setText(QCoreApplication::translate("WelcomeWindow", "\350\272\253\344\273\275\350\257\201\345\217\267", nullptr));
        checkBoxQQ->setText(QCoreApplication::translate("WelcomeWindow", "QQ", nullptr));
        checkBoxWeChat->setText(QCoreApplication::translate("WelcomeWindow", "\345\276\256\344\277\241", nullptr));
        checkBoxWeiBo->setText(QCoreApplication::translate("WelcomeWindow", "\345\276\256\345\215\232", nullptr));
        pushButtonOpen->setText(QCoreApplication::translate("WelcomeWindow", "\345\274\200\351\200\232", nullptr));
        groupBoxLogin->setTitle(QCoreApplication::translate("WelcomeWindow", "\346\234\215\345\212\241\347\231\273\345\275\225", nullptr));
        pushButtonQQ->setText(QCoreApplication::translate("WelcomeWindow", "QQ", nullptr));
        pushButtonWeChat->setText(QCoreApplication::translate("WelcomeWindow", "\345\276\256\344\277\241", nullptr));
        pushButtonWeiBo->setText(QCoreApplication::translate("WelcomeWindow", "\345\276\256\345\215\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WelcomeWindow: public Ui_WelcomeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOMEWINDOW_H
