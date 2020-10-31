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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DayTaskDialog
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QListView *listView;

    void setupUi(QMainWindow *DayTaskDialog)
    {
        if (DayTaskDialog->objectName().isEmpty())
            DayTaskDialog->setObjectName(QString::fromUtf8("DayTaskDialog"));
        DayTaskDialog->resize(300, 425);
        DayTaskDialog->setMinimumSize(QSize(300, 425));
        DayTaskDialog->setMaximumSize(QSize(300, 425));
        centralwidget = new QWidget(DayTaskDialog);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(3, 0));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listView = new QListView(centralwidget);
        listView->setObjectName(QString::fromUtf8("listView"));

        verticalLayout->addWidget(listView);

        DayTaskDialog->setCentralWidget(centralwidget);

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
