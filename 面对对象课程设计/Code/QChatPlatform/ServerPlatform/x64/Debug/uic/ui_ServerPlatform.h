/********************************************************************************
** Form generated from reading UI file 'ServerPlatform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERPLATFORM_H
#define UI_SERVERPLATFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerPlatformClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ServerPlatformClass)
    {
        if (ServerPlatformClass->objectName().isEmpty())
            ServerPlatformClass->setObjectName(QString::fromUtf8("ServerPlatformClass"));
        ServerPlatformClass->resize(600, 400);
        menuBar = new QMenuBar(ServerPlatformClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        ServerPlatformClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ServerPlatformClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ServerPlatformClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(ServerPlatformClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        ServerPlatformClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ServerPlatformClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ServerPlatformClass->setStatusBar(statusBar);

        retranslateUi(ServerPlatformClass);

        QMetaObject::connectSlotsByName(ServerPlatformClass);
    } // setupUi

    void retranslateUi(QMainWindow *ServerPlatformClass)
    {
        ServerPlatformClass->setWindowTitle(QApplication::translate("ServerPlatformClass", "ServerPlatform", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ServerPlatformClass: public Ui_ServerPlatformClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERPLATFORM_H
