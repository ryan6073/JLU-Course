#ifndef _STDAFX_H_
#define _STDAFX_H_

#include <QMainWindow>
#include <QTcpSocket>
#include <QHostAddress>
#include <QTime>
#include <QPainter>
#include <QFileDialog>
#include <QInputDialog>
#include <QTreeWidget>
#include <QJsonDocument>
#include <QMenu>
#include <QKeyEvent>
#include <QMessageBox>
#include <QTimer>
#include <QPlainTextEdit>

const QString buttonStyle = "QPushButton{"
    "background-color:rgba(100,225,100,30);"//背景色（也可以设置图片）
    "border-style:outset;"                  //边框样式（inset/outset）
    "border-width:3px;"                     //边框宽度像素
    "border-radius:10px;"                   //边框圆角半径像素
    "border-color:rgba(255,255,255,30);"    //边框颜色
    "font:bold 16px;"                       //字体，字体大小
    "color:rgba(0,0,0,100);"                //字体颜色
    "padding:6px;"                          //填衬
    "}"
    //鼠标悬停样式
    "QPushButton:hover{"
    "background-color:rgba(100,255,100,100);"
    "border-color:rgba(255,255,255,200);"
    "color:rgba(0,0,0,200);"
    "}"
    //鼠标按下样式
    "QPushButton:pressed{"
    "background-color:rgba(100,255,100,200);"
    "border-color:rgba(255,255,255,30);"
    "border-style:inset;"
    "color:rgba(0,0,0,100);"
    "}";

const QString lineEditStyle = "QLineEdit{"
    "border: 1px solid #A0A0A0;" /* 边框宽度为1px，颜色为#A0A0A0 */
    "border-radius: 5px;" /* 边框圆角 */
    "padding-left: 5px;" /* 文本距离左边界有3px */
    "background-color: transparent;" /* 背景颜色 */
    "selection-background-color: #A0A0A0;" /* 选中文本的背景颜色 */
    "selection-color: #F2F2F2;" /* 选中文本的颜色 */
    "font-size: 10pt;" /* 文本字体大小 */
    "}";

#endif // !_STDAFX_H_
