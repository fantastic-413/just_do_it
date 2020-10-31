/********************************************************************************
** Form generated from reading UI file 'modifydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFYDIALOG_H
#define UI_MODIFYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModifyDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QDialog *ModifyDialog)
    {
        if (ModifyDialog->objectName().isEmpty())
            ModifyDialog->setObjectName(QString::fromUtf8("ModifyDialog"));
        ModifyDialog->resize(394, 301);
        buttonBox = new QDialogButtonBox(ModifyDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(ModifyDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 120, 311, 41));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        retranslateUi(ModifyDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ModifyDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ModifyDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ModifyDialog);
    } // setupUi

    void retranslateUi(QDialog *ModifyDialog)
    {
        ModifyDialog->setWindowTitle(QCoreApplication::translate("ModifyDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ModifyDialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModifyDialog: public Ui_ModifyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYDIALOG_H
