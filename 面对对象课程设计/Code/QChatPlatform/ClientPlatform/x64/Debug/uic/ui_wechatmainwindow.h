/********************************************************************************
** Form generated from reading UI file 'wechatmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WECHATMAINWINDOW_H
#define UI_WECHATMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WeChatMainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_3;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *lineEditAddress;
    QLineEdit *lineEditPort;
    QLineEdit *lineEditName;
    QLabel *label;
    QVBoxLayout *verticalLayout_3;
    QPushButton *connectBtn;
    QPushButton *pushButtonLogin;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *clientState;
    QVBoxLayout *verticalLayout;
    QTextEdit *chatRecord;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEditGroupSend;
    QPushButton *pushButtonGroupSend;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WeChatMainWindow)
    {
        if (WeChatMainWindow->objectName().isEmpty())
            WeChatMainWindow->setObjectName("WeChatMainWindow");
        WeChatMainWindow->resize(500, 450);
        centralwidget = new QWidget(WeChatMainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\351\232\266\344\271\246")});
        font.setPointSize(12);
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 6, 0, 1, 1);

        lineEditAddress = new QLineEdit(centralwidget);
        lineEditAddress->setObjectName("lineEditAddress");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223")});
        font1.setPointSize(9);
        lineEditAddress->setFont(font1);

        gridLayout->addWidget(lineEditAddress, 0, 1, 1, 1);

        lineEditPort = new QLineEdit(centralwidget);
        lineEditPort->setObjectName("lineEditPort");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\351\232\266\344\271\246")});
        font2.setPointSize(9);
        lineEditPort->setFont(font2);

        gridLayout->addWidget(lineEditPort, 2, 1, 1, 1);

        lineEditName = new QLineEdit(centralwidget);
        lineEditName->setObjectName("lineEditName");
        lineEditName->setFont(font2);

        gridLayout->addWidget(lineEditName, 6, 1, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);


        horizontalLayout_3->addLayout(gridLayout);


        horizontalLayout_7->addLayout(horizontalLayout_3);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        connectBtn = new QPushButton(centralwidget);
        connectBtn->setObjectName("connectBtn");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(connectBtn->sizePolicy().hasHeightForWidth());
        connectBtn->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\351\232\266\344\271\246")});
        font3.setPointSize(10);
        connectBtn->setFont(font3);

        verticalLayout_3->addWidget(connectBtn);

        pushButtonLogin = new QPushButton(centralwidget);
        pushButtonLogin->setObjectName("pushButtonLogin");
        sizePolicy.setHeightForWidth(pushButtonLogin->sizePolicy().hasHeightForWidth());
        pushButtonLogin->setSizePolicy(sizePolicy);
        pushButtonLogin->setFont(font3);

        verticalLayout_3->addWidget(pushButtonLogin);


        horizontalLayout_7->addLayout(verticalLayout_3);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        clientState = new QLabel(centralwidget);
        clientState->setObjectName("clientState");
        clientState->setFont(font);

        horizontalLayout_2->addWidget(clientState);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        chatRecord = new QTextEdit(centralwidget);
        chatRecord->setObjectName("chatRecord");
        QFont font4;
        font4.setFamilies({QString::fromUtf8("SimSun-ExtB")});
        font4.setPointSize(9);
        chatRecord->setFont(font4);

        verticalLayout->addWidget(chatRecord);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lineEditGroupSend = new QLineEdit(centralwidget);
        lineEditGroupSend->setObjectName("lineEditGroupSend");

        horizontalLayout->addWidget(lineEditGroupSend);

        pushButtonGroupSend = new QPushButton(centralwidget);
        pushButtonGroupSend->setObjectName("pushButtonGroupSend");
        pushButtonGroupSend->setFont(font);

        horizontalLayout->addWidget(pushButtonGroupSend);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        WeChatMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WeChatMainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 500, 23));
        WeChatMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(WeChatMainWindow);
        statusbar->setObjectName("statusbar");
        WeChatMainWindow->setStatusBar(statusbar);

        retranslateUi(WeChatMainWindow);

        QMetaObject::connectSlotsByName(WeChatMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WeChatMainWindow)
    {
        WeChatMainWindow->setWindowTitle(QCoreApplication::translate("WeChatMainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("WeChatMainWindow", "Port", nullptr));
        label_4->setText(QCoreApplication::translate("WeChatMainWindow", "Name", nullptr));
        lineEditPort->setText(QString());
        label->setText(QCoreApplication::translate("WeChatMainWindow", "Address", nullptr));
        connectBtn->setText(QCoreApplication::translate("WeChatMainWindow", "connect", nullptr));
        pushButtonLogin->setText(QCoreApplication::translate("WeChatMainWindow", "login/register", nullptr));
        clientState->setText(QCoreApplication::translate("WeChatMainWindow", "\345\234\250\347\272\277\347\212\266\346\200\201\357\274\232\347\246\273\347\272\277", nullptr));
        pushButtonGroupSend->setText(QCoreApplication::translate("WeChatMainWindow", "send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WeChatMainWindow: public Ui_WeChatMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WECHATMAINWINDOW_H
