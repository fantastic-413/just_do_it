#include "leveldialog.h"
#include "ui_leveldialog.h"

LevelDialog::LevelDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LevelDialog)
{
    ui->setupUi(this);
    ui->comboBox->addItem("一");
    ui->comboBox->addItem("二");
    ui->comboBox->addItem("三");
}

LevelDialog::~LevelDialog()
{
    delete ui;
}

TaskLevel LevelDialog::getLevel(){
    QString s = ui->comboBox->currentText();
    if(s == "一") return TaskLevel::level_1;
    else if(s == "二") return TaskLevel::level_2;
    else return TaskLevel::level_3;
}
