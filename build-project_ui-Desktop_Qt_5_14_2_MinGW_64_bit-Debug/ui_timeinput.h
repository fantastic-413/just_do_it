/********************************************************************************
** Form generated from reading UI file 'timeinput.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMEINPUT_H
#define UI_TIMEINPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TimeInput
{
public:
    QVBoxLayout *verticalLayout;
    QDateTimeEdit *dateTimeEdit;

    void setupUi(QWidget *TimeInput)
    {
        if (TimeInput->objectName().isEmpty())
            TimeInput->setObjectName(QString::fromUtf8("TimeInput"));
        TimeInput->resize(243, 107);
        TimeInput->setContextMenuPolicy(Qt::DefaultContextMenu);
        verticalLayout = new QVBoxLayout(TimeInput);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, -1, -1, -1);
        dateTimeEdit = new QDateTimeEdit(TimeInput);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));

        verticalLayout->addWidget(dateTimeEdit);


        retranslateUi(TimeInput);

        QMetaObject::connectSlotsByName(TimeInput);
    } // setupUi

    void retranslateUi(QWidget *TimeInput)
    {
        TimeInput->setWindowTitle(QCoreApplication::translate("TimeInput", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TimeInput: public Ui_TimeInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMEINPUT_H
