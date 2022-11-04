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
    void SetComboBoxNo(const QStringList &list); //���ô���
    void SetCloseSerial();  //�޸�Ϊ�رմ���
    void SetOpenSerial();  //�޸�Ϊ�򿪴���
    void SetStopRev();  //����ֹͣ��ʾ
    void SetStartRev();  //���ü�����ʾ

private slots:
    void ScanActivePort(TRData::Ptr data); //ɨ�贮��
    void sTimeUpdate(); //ʱ�����
    void on_pushButtonOpen_clicked(); //�򿪴���
    void on_checkBoxPeriodicSend_stateChanged(int arg1); //���ڷ���
    void on_checkBoxReVTime_stateChanged(int arg1); //��ʾ����ʱ��
    void on_pushButtonSend_clicked(); //���Ͱ�ť
    void on_pushButtonClearRev_clicked(); //��ս�������ť
    void on_pushButtonClearSend_clicked(); //��շ�������ť
    void on_pushButtonStopRev_clicked(); //ֹͣ��ʾ
    void on_pushButtonRdFile_clicked(); //��ȡ�ļ�������ʾ���ʹ���
    void on_pushButtonSaveRev_clicked(); //�����ļ���ť�ۺ���

private:
    void Init();    //��ʼ��
    void SignalSlotInit(); //�ź���۳�ʼ��
    void RefreshDPI(); //��ȡ���ű���
    void TimeInit(); // ��ʼ����ʱ��
    void ChangeObjectSize(const QObject& o, double objectRate); //������С
    void ButtonState(const bool& flag); //��ť״̬
    void AddStatusBar();  //��ӵײ�״̬��
    void AddScanPort();  //���ɨ�贮��
    void ShowTime(); //ʱ����ʾ
    void SetNumOnLabel(QLabel* lbl, QString strS, long num); //����labelֵ
    void OpenSerial(); //�򿪴���
    void CloseSerial(); //�رմ���
    bool openTextByIODevice(const QString& aFileName); //��ȡ�ļ�
    QString byteArrayToUnicode(const QByteArray& array); //����ת��
    bool saveTextByIODevice(const QString& aFileName); //�����豸�ļ�

signals:
    void signal(const TRData::Ptr data);


private:
    Ui::MainWindow ui;
    myComboBox* comboBoxNo=NULL;

    //�±�״̬��
    QLabel* qlbSendSum, * qlbRevSum;//���ͽ�������label����
    QLabel* currentTimeLabel; //ϵͳʱ����ʾ��ǩ
    QLabel* qlbLinkSource;//Դ�����ӱ�ǩ����
    long ComSendSum, ComRevSum;//���ͺͽ�������ͳ�Ʊ���
    QTimer* PriecSendTimer=NULL;//���ڷ��Ͷ�ʱ�����Ͷ��е�ѭ�����͹���
};
