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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
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
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *clientState;
    QToolBox *toolBox;
    QWidget *page;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QTreeWidget *treeWidget;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEditFriendSend;
    QPushButton *pushButtonFriendSend;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QTextEdit *chatRecord;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEditGroupSend;
    QPushButton *pushButtonGroupSend;

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
        verticalLayout_7 = new QVBoxLayout(centralwidget);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        headBtn = new QPushButton(centralwidget);
        headBtn->setObjectName("headBtn");
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(headBtn->sizePolicy().hasHeightForWidth());
        headBtn->setSizePolicy(sizePolicy);
        headBtn->setContextMenuPolicy(Qt::CustomContextMenu);

        horizontalLayout_3->addWidget(headBtn);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\351\232\266\344\271\246")});
        font1.setPointSize(12);
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setFont(font1);

        gridLayout->addWidget(label_4, 6, 0, 1, 1);

        lineEditAddress = new QLineEdit(centralwidget);
        lineEditAddress->setObjectName("lineEditAddress");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223")});
        font2.setPointSize(9);
        lineEditAddress->setFont(font2);

        gridLayout->addWidget(lineEditAddress, 0, 1, 1, 1);

        lineEditPort = new QLineEdit(centralwidget);
        lineEditPort->setObjectName("lineEditPort");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\351\232\266\344\271\246")});
        font3.setPointSize(9);
        lineEditPort->setFont(font3);

        gridLayout->addWidget(lineEditPort, 2, 1, 1, 1);

        lineEditName = new QLineEdit(centralwidget);
        lineEditName->setObjectName("lineEditName");
        lineEditName->setFont(font3);

        gridLayout->addWidget(lineEditName, 6, 1, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setFont(font1);

        gridLayout->addWidget(label, 0, 0, 1, 1);


        horizontalLayout_3->addLayout(gridLayout);


        horizontalLayout_7->addLayout(horizontalLayout_3);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        backgroundBtn = new QPushButton(centralwidget);
        backgroundBtn->setObjectName("backgroundBtn");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(backgroundBtn->sizePolicy().hasHeightForWidth());
        backgroundBtn->setSizePolicy(sizePolicy1);
        QFont font4;
        font4.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\351\232\266\344\271\246")});
        font4.setPointSize(10);
        backgroundBtn->setFont(font4);

        verticalLayout_3->addWidget(backgroundBtn);

        connectBtn = new QPushButton(centralwidget);
        connectBtn->setObjectName("connectBtn");
        sizePolicy1.setHeightForWidth(connectBtn->sizePolicy().hasHeightForWidth());
        connectBtn->setSizePolicy(sizePolicy1);
        connectBtn->setFont(font4);

        verticalLayout_3->addWidget(connectBtn);


        horizontalLayout_7->addLayout(verticalLayout_3);


        verticalLayout_6->addLayout(horizontalLayout_7);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        clientState = new QLabel(centralwidget);
        clientState->setObjectName("clientState");
        clientState->setFont(font1);

        horizontalLayout_2->addWidget(clientState);


        verticalLayout_6->addLayout(horizontalLayout_2);

        toolBox = new QToolBox(centralwidget);
        toolBox->setObjectName("toolBox");
        page = new QWidget();
        page->setObjectName("page");
        page->setGeometry(QRect(0, 0, 330, 420));
        verticalLayout_5 = new QVBoxLayout(page);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        treeWidget = new QTreeWidget(page);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("\345\245\275\345\217\213\350\264\246\345\217\267"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName("treeWidget");
        QFont font5;
        font5.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223")});
        font5.setPointSize(12);
        treeWidget->setFont(font5);
        treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);
        treeWidget->setRootIsDecorated(false);
        treeWidget->setUniformRowHeights(true);

        verticalLayout_2->addWidget(treeWidget);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        lineEditFriendSend = new QLineEdit(page);
        lineEditFriendSend->setObjectName("lineEditFriendSend");

        horizontalLayout_4->addWidget(lineEditFriendSend);

        pushButtonFriendSend = new QPushButton(page);
        pushButtonFriendSend->setObjectName("pushButtonFriendSend");
        pushButtonFriendSend->setFont(font1);

        horizontalLayout_4->addWidget(pushButtonFriendSend);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout_5->addLayout(verticalLayout_2);

        toolBox->addItem(page, QString::fromUtf8("\345\245\275\345\217\213\345\210\227\350\241\250"));
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        page_2->setGeometry(QRect(0, 0, 330, 420));
        verticalLayout_4 = new QVBoxLayout(page_2);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        chatRecord = new QTextEdit(page_2);
        chatRecord->setObjectName("chatRecord");
        QFont font6;
        font6.setFamilies({QString::fromUtf8("SimSun-ExtB")});
        font6.setPointSize(9);
        chatRecord->setFont(font6);

        verticalLayout->addWidget(chatRecord);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lineEditGroupSend = new QLineEdit(page_2);
        lineEditGroupSend->setObjectName("lineEditGroupSend");

        horizontalLayout->addWidget(lineEditGroupSend);

        pushButtonGroupSend = new QPushButton(page_2);
        pushButtonGroupSend->setObjectName("pushButtonGroupSend");
        pushButtonGroupSend->setFont(font1);

        horizontalLayout->addWidget(pushButtonGroupSend);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_4->addLayout(verticalLayout);

        toolBox->addItem(page_2, QString::fromUtf8("\347\276\244\350\201\212\345\244\251\345\256\244"));

        verticalLayout_6->addWidget(toolBox);


        verticalLayout_7->addLayout(verticalLayout_6);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        toolBox->setCurrentIndex(0);


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
        clientState->setText(QCoreApplication::translate("MainWindow", "\345\234\250\347\272\277\347\212\266\346\200\201\357\274\232\347\246\273\347\272\277", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("MainWindow", "\346\234\200\346\226\260\346\266\210\346\201\257", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("MainWindow", "\345\245\275\345\217\213\345\244\207\346\263\250", nullptr));
        pushButtonFriendSend->setText(QCoreApplication::translate("MainWindow", "send", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("MainWindow", "\345\245\275\345\217\213\345\210\227\350\241\250", nullptr));
        pushButtonGroupSend->setText(QCoreApplication::translate("MainWindow", "send", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("MainWindow", "\347\276\244\350\201\212\345\244\251\345\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
