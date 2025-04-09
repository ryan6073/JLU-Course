/********************************************************************************
** Form generated from reading UI file 'QChatRoom.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QCHATROOM_H
#define UI_QCHATROOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QChatRoomClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QChatRoomClass)
    {
        if (QChatRoomClass->objectName().isEmpty())
            QChatRoomClass->setObjectName("QChatRoomClass");
        QChatRoomClass->resize(600, 400);
        menuBar = new QMenuBar(QChatRoomClass);
        menuBar->setObjectName("menuBar");
        QChatRoomClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QChatRoomClass);
        mainToolBar->setObjectName("mainToolBar");
        QChatRoomClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QChatRoomClass);
        centralWidget->setObjectName("centralWidget");
        QChatRoomClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QChatRoomClass);
        statusBar->setObjectName("statusBar");
        QChatRoomClass->setStatusBar(statusBar);

        retranslateUi(QChatRoomClass);

        QMetaObject::connectSlotsByName(QChatRoomClass);
    } // setupUi

    void retranslateUi(QMainWindow *QChatRoomClass)
    {
        QChatRoomClass->setWindowTitle(QCoreApplication::translate("QChatRoomClass", "QChatRoom", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QChatRoomClass: public Ui_QChatRoomClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QCHATROOM_H
