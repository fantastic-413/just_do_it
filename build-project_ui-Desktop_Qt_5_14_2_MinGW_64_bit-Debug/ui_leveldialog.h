/********************************************************************************
** Form generated from reading UI file 'leveldialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEVELDIALOG_H
#define UI_LEVELDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_LevelDialog
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *comboBox;
    QLabel *label;

    void setupUi(QDialog *LevelDialog)
    {
        if (LevelDialog->objectName().isEmpty())
            LevelDialog->setObjectName(QString::fromUtf8("LevelDialog"));
        LevelDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(LevelDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        comboBox = new QComboBox(LevelDialog);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(160, 110, 87, 22));
        label = new QLabel(LevelDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 110, 121, 21));

        retranslateUi(LevelDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), LevelDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LevelDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(LevelDialog);
    } // setupUi

    void retranslateUi(QDialog *LevelDialog)
    {
        LevelDialog->setWindowTitle(QCoreApplication::translate("LevelDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("LevelDialog", "\350\257\267\350\276\223\345\205\245\344\273\273\345\212\241\347\255\211\347\272\247\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LevelDialog: public Ui_LevelDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEVELDIALOG_H
