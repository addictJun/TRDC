#ifndef MYCOMBOBOX_H
#define MYCOMBOBOX_H

#include <QComboBox>
#include <QMouseEvent>
#include <Qdebug>
#include"global.h"
#include"trdata.h"

class myComboBox : public QComboBox
{
    Q_OBJECT
public:
    explicit myComboBox(QWidget *parent = nullptr);

    // 重写鼠标点击事件
    void mousePressEvent(QMouseEvent *event);

signals:
    void signal(TRData::Ptr data);

private:
    void scanActivePort();

};

#endif // MYCOMBOBOX_H
