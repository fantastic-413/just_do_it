#include "timeinput.h"
#include "ui_timeinput.h"

TimeInput::TimeInput(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TimeInput)
{
    ui->setupUi(this);
    //获取当前time currentDateTime
    QDateTime time = QDateTime::currentDateTime();
    //设置输入时间的默认值是当前时间
    ui->dateTimeEdit->setDateTime(time);
    //格式化时间输入栏 displayformat
    ui->dateTimeEdit->setDisplayFormat("ddd MM-dd hh:mm");
    //设置时间选择下拉框
    ui->dateTimeEdit->setCalendarPopup(true);
}

TimeInput::~TimeInput()
{
    delete ui;
}

QDateTime TimeInput::getTime(){
    return ui->dateTimeEdit->dateTime();
}
