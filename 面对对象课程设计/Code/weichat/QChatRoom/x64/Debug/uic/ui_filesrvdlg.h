/********************************************************************************
** Form generated from reading UI file 'filesrvdlg.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILESRVDLG_H
#define UI_FILESRVDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FileSrvDlg
{
public:
    QPushButton *openFilePushButton;
    QPushButton *sendFilePushButton;
    QProgressBar *sendProgressBar;
    QPushButton *srvClosePushButton;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *sfileNameLineEdit;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *sfileSizeLineEdit;
    QLineEdit *sendSizeLineEdit;
    QLabel *label_5;

    void setupUi(QDialog *FileSrvDlg)
    {
        if (FileSrvDlg->objectName().isEmpty())
            FileSrvDlg->setObjectName("FileSrvDlg");
        FileSrvDlg->resize(440, 210);
        openFilePushButton = new QPushButton(FileSrvDlg);
        openFilePushButton->setObjectName("openFilePushButton");
        openFilePushButton->setGeometry(QRect(300, 60, 31, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font.setPointSize(10);
        openFilePushButton->setFont(font);
        sendFilePushButton = new QPushButton(FileSrvDlg);
        sendFilePushButton->setObjectName("sendFilePushButton");
        sendFilePushButton->setGeometry(QRect(340, 60, 75, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font1.setPointSize(10);
        font1.setBold(true);
        sendFilePushButton->setFont(font1);
        sendProgressBar = new QProgressBar(FileSrvDlg);
        sendProgressBar->setObjectName("sendProgressBar");
        sendProgressBar->setGeometry(QRect(100, 160, 241, 23));
        sendProgressBar->setValue(0);
        srvClosePushButton = new QPushButton(FileSrvDlg);
        srvClosePushButton->setObjectName("srvClosePushButton");
        srvClosePushButton->setGeometry(QRect(340, 150, 75, 31));
        srvClosePushButton->setFont(font);
        label = new QLabel(FileSrvDlg);
        label->setObjectName("label");
        label->setGeometry(QRect(170, 15, 91, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font2.setPointSize(12);
        font2.setBold(true);
        label->setFont(font2);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(FileSrvDlg);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 60, 71, 31));
        label_2->setFont(font);
        sfileNameLineEdit = new QLineEdit(FileSrvDlg);
        sfileNameLineEdit->setObjectName("sfileNameLineEdit");
        sfileNameLineEdit->setEnabled(false);
        sfileNameLineEdit->setGeometry(QRect(100, 60, 201, 31));
        sfileNameLineEdit->setFont(font);
        sfileNameLineEdit->setAlignment(Qt::AlignCenter);
        sfileNameLineEdit->setReadOnly(true);
        label_3 = new QLabel(FileSrvDlg);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(70, 110, 51, 31));
        label_3->setFont(font);
        label_4 = new QLabel(FileSrvDlg);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(200, 110, 61, 31));
        label_4->setFont(font);
        sfileSizeLineEdit = new QLineEdit(FileSrvDlg);
        sfileSizeLineEdit->setObjectName("sfileSizeLineEdit");
        sfileSizeLineEdit->setEnabled(false);
        sfileSizeLineEdit->setGeometry(QRect(120, 110, 71, 31));
        sfileSizeLineEdit->setFont(font);
        sfileSizeLineEdit->setAlignment(Qt::AlignCenter);
        sfileSizeLineEdit->setReadOnly(true);
        sendSizeLineEdit = new QLineEdit(FileSrvDlg);
        sendSizeLineEdit->setObjectName("sendSizeLineEdit");
        sendSizeLineEdit->setEnabled(false);
        sendSizeLineEdit->setGeometry(QRect(260, 110, 71, 31));
        sendSizeLineEdit->setFont(font);
        sendSizeLineEdit->setAlignment(Qt::AlignCenter);
        sendSizeLineEdit->setReadOnly(true);
        label_5 = new QLabel(FileSrvDlg);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 160, 71, 21));
        label_5->setFont(font);

        retranslateUi(FileSrvDlg);

        QMetaObject::connectSlotsByName(FileSrvDlg);
    } // setupUi

    void retranslateUi(QDialog *FileSrvDlg)
    {
        FileSrvDlg->setWindowTitle(QCoreApplication::translate("FileSrvDlg", "\345\217\221 \351\200\201 \346\226\207 \344\273\266", nullptr));
        openFilePushButton->setText(QCoreApplication::translate("FileSrvDlg", "...", nullptr));
        sendFilePushButton->setText(QCoreApplication::translate("FileSrvDlg", "\345\217\221  \351\200\201", nullptr));
        srvClosePushButton->setText(QCoreApplication::translate("FileSrvDlg", "\345\201\234  \346\255\242", nullptr));
        label->setText(QCoreApplication::translate("FileSrvDlg", "\346\226\207 \344\273\266 \345\217\221 \351\200\201", nullptr));
        label_2->setText(QCoreApplication::translate("FileSrvDlg", "\345\217\221 \351\200\201 \346\226\207 \344\273\266", nullptr));
        label_3->setText(QCoreApplication::translate("FileSrvDlg", "\345\244\247   \345\260\217\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("FileSrvDlg", "\345\267\262 \345\217\221 \351\200\201\357\274\232", nullptr));
        sfileSizeLineEdit->setText(QString());
        sendSizeLineEdit->setText(QString());
        label_5->setText(QCoreApplication::translate("FileSrvDlg", "\350\277\233         \345\272\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileSrvDlg: public Ui_FileSrvDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILESRVDLG_H
