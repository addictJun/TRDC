/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEditTime;
    QLabel *labelMS;
    QCheckBox *checkBoxPeriodicSend;
    QGroupBox *groupBoxComSet;
    QPushButton *pushButtonOpen;
    QComboBox *comboBoxComBaud;
    QGroupBox *groupBoxSendSet;
    QPushButton *pushButtonClearSend;
    QPushButton *pushButtonRdFile;
    QCheckBox *checkBoxSendHex;
    QGroupBox *groupBoxRevSet;
    QCheckBox *checkBoxRevHex;
    QCheckBox *checkBoxReVTime;
    QPushButton *pushButtonClearRev;
    QPushButton *pushButtonStopRev;
    QPushButton *pushButtonSaveRev;
    QGroupBox *groupBoxSend;
    QPlainTextEdit *TextSend;
    QPushButton *pushButtonSend;
    QGroupBox *groupBoxRev;
    QPlainTextEdit *TextRev;
    QGroupBox *groupBoxMutiSend;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(736, 580);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        MainWindow->setDockNestingEnabled(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lineEditTime = new QLineEdit(centralWidget);
        lineEditTime->setObjectName(QStringLiteral("lineEditTime"));
        lineEditTime->setGeometry(QRect(660, 370, 31, 16));
        labelMS = new QLabel(centralWidget);
        labelMS->setObjectName(QStringLiteral("labelMS"));
        labelMS->setGeometry(QRect(700, 370, 16, 16));
        checkBoxPeriodicSend = new QCheckBox(centralWidget);
        checkBoxPeriodicSend->setObjectName(QStringLiteral("checkBoxPeriodicSend"));
        checkBoxPeriodicSend->setGeometry(QRect(580, 370, 81, 16));
        checkBoxPeriodicSend->setCheckable(true);
        groupBoxComSet = new QGroupBox(centralWidget);
        groupBoxComSet->setObjectName(QStringLiteral("groupBoxComSet"));
        groupBoxComSet->setGeometry(QRect(0, 0, 171, 81));
        pushButtonOpen = new QPushButton(groupBoxComSet);
        pushButtonOpen->setObjectName(QStringLiteral("pushButtonOpen"));
        pushButtonOpen->setGeometry(QRect(90, 50, 69, 22));
        comboBoxComBaud = new QComboBox(groupBoxComSet);
        comboBoxComBaud->setObjectName(QStringLiteral("comboBoxComBaud"));
        comboBoxComBaud->setGeometry(QRect(10, 50, 69, 22));
        groupBoxSendSet = new QGroupBox(centralWidget);
        groupBoxSendSet->setObjectName(QStringLiteral("groupBoxSendSet"));
        groupBoxSendSet->setGeometry(QRect(10, 170, 161, 91));
        pushButtonClearSend = new QPushButton(groupBoxSendSet);
        pushButtonClearSend->setObjectName(QStringLiteral("pushButtonClearSend"));
        pushButtonClearSend->setGeometry(QRect(84, 50, 71, 23));
        pushButtonRdFile = new QPushButton(groupBoxSendSet);
        pushButtonRdFile->setObjectName(QStringLiteral("pushButtonRdFile"));
        pushButtonRdFile->setGeometry(QRect(84, 30, 71, 23));
        checkBoxSendHex = new QCheckBox(groupBoxSendSet);
        checkBoxSendHex->setObjectName(QStringLiteral("checkBoxSendHex"));
        checkBoxSendHex->setGeometry(QRect(10, 40, 101, 16));
        groupBoxRevSet = new QGroupBox(centralWidget);
        groupBoxRevSet->setObjectName(QStringLiteral("groupBoxRevSet"));
        groupBoxRevSet->setGeometry(QRect(10, 80, 161, 91));
        checkBoxRevHex = new QCheckBox(groupBoxRevSet);
        checkBoxRevHex->setObjectName(QStringLiteral("checkBoxRevHex"));
        checkBoxRevHex->setGeometry(QRect(10, 60, 101, 16));
        checkBoxRevHex->setCheckable(true);
        checkBoxRevHex->setChecked(false);
        checkBoxRevHex->setTristate(false);
        checkBoxReVTime = new QCheckBox(groupBoxRevSet);
        checkBoxReVTime->setObjectName(QStringLiteral("checkBoxReVTime"));
        checkBoxReVTime->setGeometry(QRect(10, 30, 95, 16));
        pushButtonClearRev = new QPushButton(groupBoxRevSet);
        pushButtonClearRev->setObjectName(QStringLiteral("pushButtonClearRev"));
        pushButtonClearRev->setGeometry(QRect(84, 60, 71, 23));
        pushButtonStopRev = new QPushButton(groupBoxRevSet);
        pushButtonStopRev->setObjectName(QStringLiteral("pushButtonStopRev"));
        pushButtonStopRev->setGeometry(QRect(84, 40, 71, 23));
        pushButtonSaveRev = new QPushButton(groupBoxRevSet);
        pushButtonSaveRev->setObjectName(QStringLiteral("pushButtonSaveRev"));
        pushButtonSaveRev->setGeometry(QRect(84, 20, 71, 23));
        groupBoxSend = new QGroupBox(centralWidget);
        groupBoxSend->setObjectName(QStringLiteral("groupBoxSend"));
        groupBoxSend->setGeometry(QRect(180, 390, 541, 141));
        TextSend = new QPlainTextEdit(groupBoxSend);
        TextSend->setObjectName(QStringLiteral("TextSend"));
        TextSend->setEnabled(true);
        TextSend->setGeometry(QRect(10, 20, 521, 111));
        pushButtonSend = new QPushButton(groupBoxSend);
        pushButtonSend->setObjectName(QStringLiteral("pushButtonSend"));
        pushButtonSend->setGeometry(QRect(460, 110, 71, 23));
        pushButtonSend->setCheckable(false);
        pushButtonSend->setChecked(false);
        pushButtonSend->setAutoDefault(false);
        groupBoxRev = new QGroupBox(centralWidget);
        groupBoxRev->setObjectName(QStringLiteral("groupBoxRev"));
        groupBoxRev->setGeometry(QRect(180, 0, 341, 361));
        TextRev = new QPlainTextEdit(groupBoxRev);
        TextRev->setObjectName(QStringLiteral("TextRev"));
        TextRev->setGeometry(QRect(10, 20, 521, 341));
        TextRev->setReadOnly(true);
        groupBoxMutiSend = new QGroupBox(centralWidget);
        groupBoxMutiSend->setObjectName(QStringLiteral("groupBoxMutiSend"));
        groupBoxMutiSend->setGeometry(QRect(10, 270, 161, 261));
        MainWindow->setCentralWidget(centralWidget);
        labelMS->raise();
        checkBoxPeriodicSend->raise();
        groupBoxComSet->raise();
        groupBoxSendSet->raise();
        groupBoxRevSet->raise();
        groupBoxSend->raise();
        groupBoxRev->raise();
        groupBoxMutiSend->raise();
        lineEditTime->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 736, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setFloatable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setSizeGripEnabled(true);
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        pushButtonSend->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "RYMCU\344\270\262\345\217\243\350\260\203\350\257\225\345\212\251\346\211\213V1.0  www.rymcu.com", Q_NULLPTR));
        lineEditTime->setText(QApplication::translate("MainWindow", "1000", Q_NULLPTR));
        labelMS->setText(QApplication::translate("MainWindow", "ms", Q_NULLPTR));
        checkBoxPeriodicSend->setText(QApplication::translate("MainWindow", "\345\221\250\346\234\237\345\217\221\351\200\201", Q_NULLPTR));
        groupBoxComSet->setTitle(QApplication::translate("MainWindow", "\344\270\262\345\217\243\350\256\276\347\275\256", Q_NULLPTR));
        pushButtonOpen->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        comboBoxComBaud->clear();
        comboBoxComBaud->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "115200", Q_NULLPTR)
        );
        groupBoxSendSet->setTitle(QApplication::translate("MainWindow", "\345\217\221\351\200\201\350\256\276\347\275\256", Q_NULLPTR));
        pushButtonClearSend->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\345\217\221\351\200\201\345\214\272", Q_NULLPTR));
        pushButtonRdFile->setText(QApplication::translate("MainWindow", "\350\257\273\345\217\226\346\226\207\344\273\266", Q_NULLPTR));
        checkBoxSendHex->setText(QApplication::translate("MainWindow", "\345\215\201\345\205\255\350\277\233\345\210\266", Q_NULLPTR));
        groupBoxRevSet->setTitle(QApplication::translate("MainWindow", "\346\216\245\346\224\266\350\256\276\347\275\256", Q_NULLPTR));
        checkBoxRevHex->setText(QApplication::translate("MainWindow", "\345\215\201\345\205\255\350\277\233\345\210\266", Q_NULLPTR));
        checkBoxReVTime->setText(QApplication::translate("MainWindow", "\346\216\245\346\224\266\346\227\266\351\227\264", Q_NULLPTR));
        pushButtonClearRev->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\346\216\245\346\224\266\345\214\272", Q_NULLPTR));
        pushButtonStopRev->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\346\230\276\347\244\272", Q_NULLPTR));
        pushButtonSaveRev->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\346\226\207\344\273\266", Q_NULLPTR));
        groupBoxSend->setTitle(QApplication::translate("MainWindow", "\345\217\221\351\200\201\345\214\272", Q_NULLPTR));
        TextSend->setPlainText(QString());
        pushButtonSend->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", Q_NULLPTR));
        groupBoxRev->setTitle(QApplication::translate("MainWindow", "\346\216\245\346\224\266\345\214\272", Q_NULLPTR));
        TextRev->setPlainText(QString());
        groupBoxMutiSend->setTitle(QApplication::translate("MainWindow", "\350\256\276\345\244\207\347\273\210\347\253\257", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
