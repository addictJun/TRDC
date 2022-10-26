#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TRDC.h"

class TRDC : public QMainWindow
{
    Q_OBJECT

public:
    TRDC(QWidget *parent = nullptr);
    ~TRDC();

private:
    Ui::TRDCClass ui;
};
