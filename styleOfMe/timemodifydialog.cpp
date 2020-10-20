#include "timemodifydialog.h"
#include "ui_timemodifydialog.h"
#include<QDebug>

TimeModifyDialog::TimeModifyDialog(QDateTime taskTime,QString str,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TimeModifyDialog)
{
    ui->setupUi(this);
    //设置输入时间的默认值是当前时间
    ui->dateTimeEdit->setDateTime(taskTime);
    //设置输入开始/结束时间
    ui->label->setText(QString("请输入%1：").arg(str));
    //格式化时间输入栏 displayformat
    ui->dateTimeEdit->setDisplayFormat("ddd MM-dd hh:mm");
    //设置时间选择下拉框
    ui->dateTimeEdit->setCalendarPopup(true);
}

TimeModifyDialog::~TimeModifyDialog()
{
    delete ui;
}
QDateTime TimeModifyDialog::getTime(){
    return ui->dateTimeEdit->dateTime();
}
QString TimeModifyDialog::getDay(){
    return ui->dateTimeEdit->dateTime().toString("MM-dd");
}
