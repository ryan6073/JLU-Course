/********************************************************************************
** Form generated from reading UI file 'infodialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFODIALOG_H
#define UI_INFODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_InfoDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *lineEditAccount;
    QLabel *label_7;
    QLineEdit *lineEditPassword;
    QLabel *label_3;
    QLineEdit *lineEditName;
    QLabel *label_8;
    QLineEdit *lineEditIdentification;
    QLabel *label_4;
    QLineEdit *lineEditBirth;
    QLabel *label_5;
    QLineEdit *lineEditRegister;
    QLabel *label_6;
    QLineEdit *lineEditPlace;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonUpdate;
    QPushButton *pushButtonClose;

    void setupUi(QDialog *InfoDialog)
    {
        if (InfoDialog->objectName().isEmpty())
            InfoDialog->setObjectName("InfoDialog");
        InfoDialog->resize(300, 350);
        verticalLayout = new QVBoxLayout(InfoDialog);
        verticalLayout->setObjectName("verticalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label_2 = new QLabel(InfoDialog);
        label_2->setObjectName("label_2");
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267")});
        font.setPointSize(11);
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        lineEditAccount = new QLineEdit(InfoDialog);
        lineEditAccount->setObjectName("lineEditAccount");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223")});
        font1.setPointSize(11);
        lineEditAccount->setFont(font1);

        gridLayout->addWidget(lineEditAccount, 0, 1, 1, 1);

        label_7 = new QLabel(InfoDialog);
        label_7->setObjectName("label_7");
        label_7->setFont(font);

        gridLayout->addWidget(label_7, 1, 0, 1, 1);

        lineEditPassword = new QLineEdit(InfoDialog);
        lineEditPassword->setObjectName("lineEditPassword");
        lineEditPassword->setFont(font1);

        gridLayout->addWidget(lineEditPassword, 1, 1, 1, 1);

        label_3 = new QLabel(InfoDialog);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEditName = new QLineEdit(InfoDialog);
        lineEditName->setObjectName("lineEditName");
        lineEditName->setFont(font1);

        gridLayout->addWidget(lineEditName, 2, 1, 1, 1);

        label_8 = new QLabel(InfoDialog);
        label_8->setObjectName("label_8");
        label_8->setFont(font);

        gridLayout->addWidget(label_8, 3, 0, 1, 1);

        lineEditIdentification = new QLineEdit(InfoDialog);
        lineEditIdentification->setObjectName("lineEditIdentification");
        lineEditIdentification->setFont(font1);

        gridLayout->addWidget(lineEditIdentification, 3, 1, 1, 1);

        label_4 = new QLabel(InfoDialog);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        lineEditBirth = new QLineEdit(InfoDialog);
        lineEditBirth->setObjectName("lineEditBirth");
        lineEditBirth->setFont(font1);

        gridLayout->addWidget(lineEditBirth, 4, 1, 1, 1);

        label_5 = new QLabel(InfoDialog);
        label_5->setObjectName("label_5");
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        lineEditRegister = new QLineEdit(InfoDialog);
        lineEditRegister->setObjectName("lineEditRegister");
        lineEditRegister->setFont(font1);

        gridLayout->addWidget(lineEditRegister, 5, 1, 1, 1);

        label_6 = new QLabel(InfoDialog);
        label_6->setObjectName("label_6");
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 6, 0, 1, 1);

        lineEditPlace = new QLineEdit(InfoDialog);
        lineEditPlace->setObjectName("lineEditPlace");
        lineEditPlace->setFont(font1);

        gridLayout->addWidget(lineEditPlace, 6, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButtonUpdate = new QPushButton(InfoDialog);
        pushButtonUpdate->setObjectName("pushButtonUpdate");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267")});
        font2.setPointSize(12);
        pushButtonUpdate->setFont(font2);

        horizontalLayout->addWidget(pushButtonUpdate);

        pushButtonClose = new QPushButton(InfoDialog);
        pushButtonClose->setObjectName("pushButtonClose");
        pushButtonClose->setFont(font2);

        horizontalLayout->addWidget(pushButtonClose);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 1);

        retranslateUi(InfoDialog);

        QMetaObject::connectSlotsByName(InfoDialog);
    } // setupUi

    void retranslateUi(QDialog *InfoDialog)
    {
        InfoDialog->setWindowTitle(QCoreApplication::translate("InfoDialog", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("InfoDialog", "\350\264\246\346\210\267\347\274\226\345\217\267", nullptr));
        label_7->setText(QCoreApplication::translate("InfoDialog", "\347\231\273\345\275\225\345\257\206\347\240\201", nullptr));
        label_3->setText(QCoreApplication::translate("InfoDialog", "\350\264\246\346\210\267\346\230\265\347\247\260", nullptr));
        label_8->setText(QCoreApplication::translate("InfoDialog", "\350\272\253\344\273\275\350\257\201\345\217\267", nullptr));
        label_4->setText(QCoreApplication::translate("InfoDialog", "\345\207\272\347\224\237\346\227\266\351\227\264", nullptr));
        label_5->setText(QCoreApplication::translate("InfoDialog", "\347\224\263\350\257\267\346\227\266\351\227\264", nullptr));
        label_6->setText(QCoreApplication::translate("InfoDialog", "\346\211\200\345\234\250\345\237\216\345\270\202", nullptr));
        pushButtonUpdate->setText(QCoreApplication::translate("InfoDialog", "\346\233\264\346\226\260\344\277\241\346\201\257", nullptr));
        pushButtonClose->setText(QCoreApplication::translate("InfoDialog", "\345\217\226\346\266\210\346\233\264\346\226\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InfoDialog: public Ui_InfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFODIALOG_H
