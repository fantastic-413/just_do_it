/********************************************************************************
** Form generated from reading UI file 'daytaskdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DAYTASKDIALOG_H
#define UI_DAYTASKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DayTaskDialog
{
public:
    QWidget *centralwidget;
    QListView *listView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DayTaskDialog)
    {
        if (DayTaskDialog->objectName().isEmpty())
            DayTaskDialog->setObjectName(QString::fromUtf8("DayTaskDialog"));
        DayTaskDialog->resize(800, 600);
        centralwidget = new QWidget(DayTaskDialog);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        listView = new QListView(centralwidget);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(0, 0, 321, 341));
        DayTaskDialog->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DayTaskDialog);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        DayTaskDialog->setMenuBar(menubar);
        statusbar = new QStatusBar(DayTaskDialog);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        DayTaskDialog->setStatusBar(statusbar);

        retranslateUi(DayTaskDialog);

        QMetaObject::connectSlotsByName(DayTaskDialog);
    } // setupUi

    void retranslateUi(QMainWindow *DayTaskDialog)
    {
        DayTaskDialog->setWindowTitle(QCoreApplication::translate("DayTaskDialog", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DayTaskDialog: public Ui_DayTaskDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DAYTASKDIALOG_H
