/********************************************************************************
** Form generated from reading UI file 'TRDC.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRDC_H
#define UI_TRDC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TRDCClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TRDCClass)
    {
        if (TRDCClass->objectName().isEmpty())
            TRDCClass->setObjectName(QStringLiteral("TRDCClass"));
        TRDCClass->resize(600, 400);
        menuBar = new QMenuBar(TRDCClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        TRDCClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TRDCClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TRDCClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(TRDCClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        TRDCClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(TRDCClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TRDCClass->setStatusBar(statusBar);

        retranslateUi(TRDCClass);

        QMetaObject::connectSlotsByName(TRDCClass);
    } // setupUi

    void retranslateUi(QMainWindow *TRDCClass)
    {
        TRDCClass->setWindowTitle(QApplication::translate("TRDCClass", "TRDC", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TRDCClass: public Ui_TRDCClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRDC_H
