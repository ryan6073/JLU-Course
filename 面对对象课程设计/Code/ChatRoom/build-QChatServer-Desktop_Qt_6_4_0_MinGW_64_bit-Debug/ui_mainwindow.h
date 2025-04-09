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
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLineEdit *lineEditPort;
    QLineEdit *lineEditAddress;
    QLabel *label_2;
    QLabel *label;
    QPushButton *listenBtn;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QTextEdit *chatRecord;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEditSend;
    QPushButton *sendBtn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(350, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        lineEditPort = new QLineEdit(widget);
        lineEditPort->setObjectName("lineEditPort");
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\351\232\266\344\271\246")});
        lineEditPort->setFont(font);

        gridLayout->addWidget(lineEditPort, 1, 1, 1, 1);

        lineEditAddress = new QLineEdit(widget);
        lineEditAddress->setObjectName("lineEditAddress");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\351\232\266\344\271\246")});
        font1.setPointSize(9);
        lineEditAddress->setFont(font1);

        gridLayout->addWidget(lineEditAddress, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Maiandra GD")});
        font2.setPointSize(12);
        label_2->setFont(font2);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(widget);
        label->setObjectName("label");
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setFont(font2);

        gridLayout->addWidget(label, 0, 0, 1, 1);


        horizontalLayout_2->addWidget(widget);

        listenBtn = new QPushButton(centralwidget);
        listenBtn->setObjectName("listenBtn");
        listenBtn->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listenBtn->sizePolicy().hasHeightForWidth());
        listenBtn->setSizePolicy(sizePolicy1);
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Maiandra GD")});
        font3.setPointSize(16);
        font3.setUnderline(false);
        listenBtn->setFont(font3);

        horizontalLayout_2->addWidget(listenBtn);


        verticalLayout_2->addLayout(horizontalLayout_2);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setObjectName("verticalLayout");
        label_3 = new QLabel(widget_2);
        label_3->setObjectName("label_3");
        QFont font4;
        font4.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\351\232\266\344\271\246")});
        font4.setPointSize(12);
        label_3->setFont(font4);

        verticalLayout->addWidget(label_3);

        chatRecord = new QTextEdit(widget_2);
        chatRecord->setObjectName("chatRecord");

        verticalLayout->addWidget(chatRecord);


        verticalLayout_2->addWidget(widget_2);

        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName("widget_3");
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setObjectName("horizontalLayout");
        lineEditSend = new QLineEdit(widget_3);
        lineEditSend->setObjectName("lineEditSend");

        horizontalLayout->addWidget(lineEditSend);

        sendBtn = new QPushButton(widget_3);
        sendBtn->setObjectName("sendBtn");
        sendBtn->setFont(font4);

        horizontalLayout->addWidget(sendBtn);


        verticalLayout_2->addWidget(widget_3);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Port", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Address", nullptr));
        listenBtn->setText(QCoreApplication::translate("MainWindow", "listen", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\234\215\345\212\241\345\231\250\350\256\260\345\275\225", nullptr));
        sendBtn->setText(QCoreApplication::translate("MainWindow", "send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
