/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *headBtn;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *lineEditAddress;
    QLineEdit *lineEditPort;
    QLineEdit *lineEditName;
    QLabel *label;
    QVBoxLayout *verticalLayout_3;
    QPushButton *backgroundBtn;
    QPushButton *connectBtn;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *clientState;
    QTextEdit *chatRecord;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEditSend;
    QPushButton *sendBtn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(350, 600);
        QFont font;
        font.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font.setPointSize(6);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        verticalLayout_7 = new QVBoxLayout(widget);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        headBtn = new QPushButton(widget);
        headBtn->setObjectName("headBtn");
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(headBtn->sizePolicy().hasHeightForWidth());
        headBtn->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(headBtn);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\351\232\266\344\271\246")});
        font1.setPointSize(12);
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        label_4->setFont(font1);

        gridLayout->addWidget(label_4, 6, 0, 1, 1);

        lineEditAddress = new QLineEdit(widget);
        lineEditAddress->setObjectName("lineEditAddress");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223")});
        font2.setPointSize(9);
        lineEditAddress->setFont(font2);

        gridLayout->addWidget(lineEditAddress, 0, 1, 1, 1);

        lineEditPort = new QLineEdit(widget);
        lineEditPort->setObjectName("lineEditPort");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\351\232\266\344\271\246")});
        font3.setPointSize(9);
        lineEditPort->setFont(font3);

        gridLayout->addWidget(lineEditPort, 2, 1, 1, 1);

        lineEditName = new QLineEdit(widget);
        lineEditName->setObjectName("lineEditName");
        lineEditName->setFont(font3);

        gridLayout->addWidget(lineEditName, 6, 1, 1, 1);

        label = new QLabel(widget);
        label->setObjectName("label");
        label->setFont(font1);

        gridLayout->addWidget(label, 0, 0, 1, 1);


        horizontalLayout_3->addLayout(gridLayout);


        horizontalLayout_7->addLayout(horizontalLayout_3);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        backgroundBtn = new QPushButton(widget);
        backgroundBtn->setObjectName("backgroundBtn");
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Agency FB")});
        font4.setPointSize(14);
        backgroundBtn->setFont(font4);

        verticalLayout_3->addWidget(backgroundBtn);

        connectBtn = new QPushButton(widget);
        connectBtn->setObjectName("connectBtn");
        connectBtn->setFont(font4);

        verticalLayout_3->addWidget(connectBtn);


        horizontalLayout_7->addLayout(verticalLayout_3);


        verticalLayout_6->addLayout(horizontalLayout_7);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setFont(font1);

        horizontalLayout_2->addWidget(label_3);

        clientState = new QLabel(widget);
        clientState->setObjectName("clientState");
        clientState->setFont(font1);

        horizontalLayout_2->addWidget(clientState);


        verticalLayout->addLayout(horizontalLayout_2);

        chatRecord = new QTextEdit(widget);
        chatRecord->setObjectName("chatRecord");
        QFont font5;
        font5.setFamilies({QString::fromUtf8("SimSun-ExtB")});
        font5.setPointSize(9);
        chatRecord->setFont(font5);

        verticalLayout->addWidget(chatRecord);


        verticalLayout_6->addLayout(verticalLayout);


        verticalLayout_7->addLayout(verticalLayout_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lineEditSend = new QLineEdit(widget);
        lineEditSend->setObjectName("lineEditSend");

        horizontalLayout->addWidget(lineEditSend);

        sendBtn = new QPushButton(widget);
        sendBtn->setObjectName("sendBtn");
        sendBtn->setFont(font1);

        horizontalLayout->addWidget(sendBtn);


        verticalLayout_7->addLayout(horizontalLayout);


        verticalLayout_2->addWidget(widget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        headBtn->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "Port", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        lineEditPort->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Address", nullptr));
        backgroundBtn->setText(QCoreApplication::translate("MainWindow", "background", nullptr));
        connectBtn->setText(QCoreApplication::translate("MainWindow", "connect", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\350\201\212\345\244\251\350\256\260\345\275\225", nullptr));
        clientState->setText(QCoreApplication::translate("MainWindow", "\345\234\250\347\272\277\347\212\266\346\200\201\357\274\232\347\246\273\347\272\277", nullptr));
        sendBtn->setText(QCoreApplication::translate("MainWindow", "send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
