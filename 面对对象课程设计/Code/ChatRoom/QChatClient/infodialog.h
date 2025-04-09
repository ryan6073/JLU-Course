#ifndef INFODIALOG_H
#define INFODIALOG_H

#include <QDialog>
#include <QPainter>
#include "stdafx.h"

namespace Ui {
class InfoDialog;
}

class InfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InfoDialog(QWidget *parent = nullptr);
    ~InfoDialog();
    void paintEvent(QPaintEvent* event);

    void setInfo(QString number, QString password, QString name, QString identification, QString birth, QString date, QString place);

signals:
    void updateInfo(QString number, QString password, QString name, QString identification, QString birth, QString date, QString place);

private slots:
    void on_pushButtonUpdate_clicked();

    void on_pushButtonClose_clicked();

private:
    Ui::InfoDialog *ui;
};

#endif // INFODIALOG_H
