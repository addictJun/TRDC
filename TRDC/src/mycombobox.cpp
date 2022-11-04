#include "mycombobox.h"

myComboBox::myComboBox(QWidget *parent) : QComboBox(parent){
    // 扫描可用串口
    scanActivePort();
}

// 扫描可用串口
void myComboBox::scanActivePort(){
    TRData::Ptr p_data(new TRData(S_SCAN_SERIAL));
    emit signal(p_data);
}

// 重写鼠标点击事件
void myComboBox::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        // 扫描可用串口
        scanActivePort();
    }
}
