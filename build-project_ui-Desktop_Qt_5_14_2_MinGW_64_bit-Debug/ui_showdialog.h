/********************************************************************************
** Form generated from reading UI file 'showdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWDIALOG_H
#define UI_SHOWDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_showDialog
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *showDialog)
    {
        if (showDialog->objectName().isEmpty())
            showDialog->setObjectName(QString::fromUtf8("showDialog"));
        showDialog->resize(800, 600);
        centralwidget = new QWidget(showDialog);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, -30, 621, 421));
        showDialog->setCentralWidget(centralwidget);
        menubar = new QMenuBar(showDialog);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        showDialog->setMenuBar(menubar);
        statusbar = new QStatusBar(showDialog);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        showDialog->setStatusBar(statusbar);

        retranslateUi(showDialog);

        QMetaObject::connectSlotsByName(showDialog);
    } // setupUi

    void retranslateUi(QMainWindow *showDialog)
    {
        showDialog->setWindowTitle(QCoreApplication::translate("showDialog", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class showDialog: public Ui_showDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWDIALOG_H
