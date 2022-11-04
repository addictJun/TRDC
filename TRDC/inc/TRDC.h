#pragma once

#include <QtWidgets/QMainWindow>
#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include <QTimer>
#include <QTime>
#include <QFileDialog>
#include <QFile>
#include <QTextCodec>
#include <QScreen>
#include <Qdebug>
#include "ui_mainwindow.h"
#include "mycombobox.h"
#include "global.h"
#include "trdata.h"

class TRDC : public QMainWindow
{
    Q_OBJECT

public:
    explicit TRDC(QWidget *parent = nullptr);
    ~TRDC();

public:
    void SetComboBoxNo(const QStringList &list); //设置串口
    void SetCloseSerial();  //修改为关闭串口
    void SetOpenSerial();  //修改为打开串口
    void SetStopRev();  //设置停止显示
    void SetStartRev();  //设置继续显示

private slots:
    void ScanActivePort(TRData::Ptr data); //扫描串口
    void sTimeUpdate(); //时间更新
    void on_pushButtonOpen_clicked(); //打开串口
    void on_checkBoxPeriodicSend_stateChanged(int arg1); //周期发送
    void on_checkBoxReVTime_stateChanged(int arg1); //显示接收时间
    void on_pushButtonSend_clicked(); //发送按钮
    void on_pushButtonClearRev_clicked(); //清空接收区按钮
    void on_pushButtonClearSend_clicked(); //清空发送区按钮
    void on_pushButtonStopRev_clicked(); //停止显示
    void on_pushButtonRdFile_clicked(); //读取文件，并显示发送窗口
    void on_pushButtonSaveRev_clicked(); //保存文件按钮槽函数

private:
    void Init();    //初始化
    void SignalSlotInit(); //信号与槽初始化
    void RefreshDPI(); //获取缩放比例
    void TimeInit(); // 初始化定时器
    void ChangeObjectSize(const QObject& o, double objectRate); //调整大小
    void ButtonState(const bool& flag); //按钮状态
    void AddStatusBar();  //添加底部状态栏
    void AddScanPort();  //添加扫描串口
    void ShowTime(); //时间显示
    void SetNumOnLabel(QLabel* lbl, QString strS, long num); //设置label值
    void OpenSerial(); //打开串口
    void CloseSerial(); //关闭串口
    bool openTextByIODevice(const QString& aFileName); //读取文件
    QString byteArrayToUnicode(const QByteArray& array); //编码转换
    bool saveTextByIODevice(const QString& aFileName); //保存设备文件

signals:
    void signal(const TRData::Ptr data);


private:
    Ui::MainWindow ui;
    myComboBox* comboBoxNo=NULL;

    //下标状态栏
    QLabel* qlbSendSum, * qlbRevSum;//发送接收流量label对象
    QLabel* currentTimeLabel; //系统时间显示标签
    QLabel* qlbLinkSource;//源码链接标签对象
    long ComSendSum, ComRevSum;//发送和接收流量统计变量
    QTimer* PriecSendTimer=NULL;//周期发送定时器，和多行的循环发送共用
};
