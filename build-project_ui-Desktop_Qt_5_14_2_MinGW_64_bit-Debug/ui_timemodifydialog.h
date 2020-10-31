/********************************************************************************
** Form generated from reading UI file 'timemodifydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMEMODIFYDIALOG_H
#define UI_TIMEMODIFYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_TimeModifyDialog
{
public:
    QDialogButtonBox *buttonBox;
    QDateTimeEdit *dateTimeEdit;
    QLabel *label;

    void setupUi(QDialog *TimeModifyDialog)
    {
        if (TimeModifyDialog->objectName().isEmpty())
            TimeModifyDialog->setObjectName(QString::fromUtf8("TimeModifyDialog"));
        TimeModifyDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(TimeModifyDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        dateTimeEdit = new QDateTimeEdit(TimeModifyDialog);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(180, 110, 194, 22));
        label = new QLabel(TimeModifyDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 110, 91, 16));

        retranslateUi(TimeModifyDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), TimeModifyDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), TimeModifyDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(TimeModifyDialog);
    } // setupUi

    void retranslateUi(QDialog *TimeModifyDialog)
    {
        TimeModifyDialog->setWindowTitle(QCoreApplication::translate("TimeModifyDialog", "Dialog", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TimeModifyDialog: public Ui_TimeModifyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMEMODIFYDIALOG_H
