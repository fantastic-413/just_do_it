#include "modifydialog.h"
#include "ui_modifydialog.h"

ModifyDialog::ModifyDialog(QString str,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifyDialog)
{
    ui->setupUi(this);
    ui->label->setText(QString("请输入%1：").arg(str));
}

ModifyDialog::~ModifyDialog()
{
    delete ui;
}
QString ModifyDialog::getModifyText(){
    return ui->lineEdit->text();
}
