#include "mycombobox.h"

myComboBox::myComboBox(QWidget *parent) : QComboBox(parent)
{
    // 扫描可用串口
    scanActivePort();
}

// 扫描可用串口
void myComboBox::scanActivePort()
{
    qDebug() << "name:scanActivePort";
    qDebug() << "canshu:" << endl;
}

// 重写鼠标点击事件
void myComboBox::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        // 扫描可用串口
        scanActivePort();
        // 弹出下拉框
        showPopup();
    }
}
