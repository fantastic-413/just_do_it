#include "inputdialog.h"
#include "ui_inputdialog.h"
#include"timeinput.h"
#include <QDebug>
#include<QComboBox>
#include<QDateTime>
InputDialog::InputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputDialog)
{
    ui->setupUi(this);
    //任务等级 一 二 三
    ui->comboBox->addItem("一");
    ui->comboBox->addItem("二");
    ui->comboBox->addItem("三");

    connect(ui->btn_1,&QPushButton::clicked,[&](){
      this->taskLevel = ui->comboBox->currentText();
      this->taskName = ui->lineEdit->text();
      this->taskStartTime = ui->widget_startTime->getTime();
      this->taskEndTime = ui->widget_endTime->getTime();
      this->taskLabel = ui->lineEdit_2->text();
      this->close();
    });

    connect(ui->btn_2,&QPushButton::clicked,[=](){
        this->close();
    });


}

InputDialog::~InputDialog()
{
    delete ui;
}
