/********************************************************************************
** Form generated from reading UI file 'filecntdlg.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILECNTDLG_H
#define UI_FILECNTDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FileCntDlg
{
public:
    QProgressBar *recvProgressBar;
    QPushButton *cntClosePushButton;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *rfileNameLineEdit;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *rfileSizeLineEdit;
    QLineEdit *recvSizeLineEdit;
    QLabel *label_5;
    QLabel *rateLabel;

    void setupUi(QDialog *FileCntDlg)
    {
        if (FileCntDlg->objectName().isEmpty())
            FileCntDlg->setObjectName("FileCntDlg");
        FileCntDlg->resize(440, 210);
        recvProgressBar = new QProgressBar(FileCntDlg);
        recvProgressBar->setObjectName("recvProgressBar");
        recvProgressBar->setGeometry(QRect(100, 160, 241, 23));
        recvProgressBar->setValue(0);
        cntClosePushButton = new QPushButton(FileCntDlg);
        cntClosePushButton->setObjectName("cntClosePushButton");
        cntClosePushButton->setGeometry(QRect(340, 60, 75, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font.setPointSize(10);
        font.setBold(true);
        cntClosePushButton->setFont(font);
        label = new QLabel(FileCntDlg);
        label->setObjectName("label");
        label->setGeometry(QRect(170, 15, 91, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font1.setPointSize(12);
        font1.setBold(true);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(FileCntDlg);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 60, 71, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font2.setPointSize(10);
        label_2->setFont(font2);
        rfileNameLineEdit = new QLineEdit(FileCntDlg);
        rfileNameLineEdit->setObjectName("rfileNameLineEdit");
        rfileNameLineEdit->setEnabled(false);
        rfileNameLineEdit->setGeometry(QRect(100, 60, 201, 31));
        rfileNameLineEdit->setFont(font2);
        rfileNameLineEdit->setAlignment(Qt::AlignCenter);
        rfileNameLineEdit->setReadOnly(true);
        label_3 = new QLabel(FileCntDlg);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(70, 110, 51, 31));
        label_3->setFont(font2);
        label_4 = new QLabel(FileCntDlg);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(200, 110, 61, 31));
        label_4->setFont(font2);
        rfileSizeLineEdit = new QLineEdit(FileCntDlg);
        rfileSizeLineEdit->setObjectName("rfileSizeLineEdit");
        rfileSizeLineEdit->setEnabled(false);
        rfileSizeLineEdit->setGeometry(QRect(120, 110, 71, 31));
        rfileSizeLineEdit->setFont(font2);
        rfileSizeLineEdit->setAlignment(Qt::AlignCenter);
        rfileSizeLineEdit->setReadOnly(true);
        recvSizeLineEdit = new QLineEdit(FileCntDlg);
        recvSizeLineEdit->setObjectName("recvSizeLineEdit");
        recvSizeLineEdit->setEnabled(false);
        recvSizeLineEdit->setGeometry(QRect(260, 110, 71, 31));
        recvSizeLineEdit->setFont(font2);
        recvSizeLineEdit->setAlignment(Qt::AlignCenter);
        recvSizeLineEdit->setReadOnly(true);
        label_5 = new QLabel(FileCntDlg);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 160, 71, 21));
        label_5->setFont(font2);
        rateLabel = new QLabel(FileCntDlg);
        rateLabel->setObjectName("rateLabel");
        rateLabel->setGeometry(QRect(340, 160, 91, 21));
        rateLabel->setFont(font2);
        rateLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        retranslateUi(FileCntDlg);

        QMetaObject::connectSlotsByName(FileCntDlg);
    } // setupUi

    void retranslateUi(QDialog *FileCntDlg)
    {
        FileCntDlg->setWindowTitle(QCoreApplication::translate("FileCntDlg", "\346\216\245 \346\224\266 \346\226\207 \344\273\266", nullptr));
        cntClosePushButton->setText(QCoreApplication::translate("FileCntDlg", "\345\201\234  \346\255\242", nullptr));
        label->setText(QCoreApplication::translate("FileCntDlg", "\346\226\207 \344\273\266 \346\216\245 \346\224\266", nullptr));
        label_2->setText(QCoreApplication::translate("FileCntDlg", "\346\216\245 \346\224\266 \346\226\207 \344\273\266", nullptr));
        label_3->setText(QCoreApplication::translate("FileCntDlg", "\345\244\247   \345\260\217\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("FileCntDlg", "\345\267\262 \346\216\245 \346\224\266\357\274\232", nullptr));
        rfileSizeLineEdit->setText(QString());
        recvSizeLineEdit->setText(QString());
        label_5->setText(QCoreApplication::translate("FileCntDlg", "\350\277\233         \345\272\246", nullptr));
        rateLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FileCntDlg: public Ui_FileCntDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILECNTDLG_H
