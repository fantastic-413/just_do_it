#include "showdialog.h"
#include "ui_showdialog.h"
#include"global.h"
showDialog::showDialog(int x,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::showDialog)
{
    ui->setupUi(this);
    ui->tableWidget->setFixedSize(830,700);
    setFixedSize(830,700);
    QList<QString> item_list;
    item_list << "任务名称" << "任务等级" << "任务开始时间" << "任务结束时间" << "任务标签" << "日期";
    ui->tableWidget->setRowCount(100);
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    for(int i = 0;i < 6;i++){
        ui->tableWidget->setItem(0,i,new QTableWidgetItem(item_list.at(i)));
    }
    switch (x) {
    case 0:{ //allTaskShow
        setWindowTitle("AllTask");
        int count = 1;
        for(auto task:allTask.allTask_list){
            QString level;
            if(task.getTaskLevel() == TaskLevel::level_1) level = "一";
            else if(task.getTaskLevel() == TaskLevel::level_2) level = "二";
            else level = "三";
            ui->tableWidget->setItem(count,0,new QTableWidgetItem(QString::fromStdString(task.getTaskName())));
            ui->tableWidget->setItem(count,1,new QTableWidgetItem(level));
            ui->tableWidget->setItem(count,2,new QTableWidgetItem(QString::fromStdString(task.getStartTime())));
            ui->tableWidget->setItem(count,3,new QTableWidgetItem(QString::fromStdString(task.getEndTime())));
            ui->tableWidget->setItem(count,4,new QTableWidgetItem(QString::fromStdString(task.getTaskLabel())));
            ui->tableWidget->setItem(count,5,new QTableWidgetItem("time"));
            count ++;
        }
        break;
    }

    case 1:{ //finishedTaskShow
        setWindowTitle("FinishedTask");
        cout << "finishedTask" << endl;
        break;
    }
    }
}

showDialog::~showDialog()
{
    delete ui;
}
