﻿#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inputdialog.h"
#include"timeinput.h"
#include<QDialog>
#include<QAction>
#include<QDebug>
#include<QString>
#include<QList>
#include<QTableWidget>
#include<QMessageBox>
#include"Task.h"
#include"DayTask.h"
#include"global.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //初始化
    initial();

    //添加任务
    connect(ui->addBtn,&QPushButton::clicked,this,&MainWindow::addTask);
    //删除任务
    connect(ui->delBtn,&QPushButton::clicked,this,&MainWindow::deleteTask);
}
//析构函数
MainWindow::~MainWindow()
{
    delete ui;
}
//初始化
void MainWindow::initial(){
    QTableWidget* tableWidget_1 = new QTableWidget(ui->tab);
    QTableWidget* tableWidget_2 = new QTableWidget(ui->tab_2);
    QTableWidget* tableWidget_3 = new QTableWidget(ui->tab_3);
    QTableWidget* tableWidget_4 = new QTableWidget(ui->tab_4);
    QTableWidget* tableWidget_5 = new QTableWidget(ui->tab_5);
    QTableWidget* tableWidget_6 = new QTableWidget(ui->tab_6);
    QTableWidget* tableWidget_7 = new QTableWidget(ui->tab_7);

  //  label_list << ui->label << ui->label_2 << ui->label_3 << ui->label_4 << ui->label_5 << ui->label_6 << ui->label_7;
    list << tableWidget_1 << tableWidget_2 << tableWidget_3 << tableWidget_4 << tableWidget_5 << tableWidget_6 << tableWidget_7;
    for(int i = 0; i < 7;i++){
        list.at(i)->setFixedSize(700,600);
        //设置不可编辑
        list.at(i)->setEditTriggers(QAbstractItemView::NoEditTriggers);
        list.at(i)->setRowCount(100);
        list.at(i)->setColumnCount(5);
        list.at(i)->setItem(0,0,new QTableWidgetItem("任务名称"));
        list.at(i)->setItem(0,1,new QTableWidgetItem("任务等级"));
        list.at(i)->setItem(0,2,new QTableWidgetItem("任务开始时间"));
        list.at(i)->setItem(0,3,new QTableWidgetItem("任务结束时间"));
        list.at(i)->setItem(0,4,new QTableWidgetItem("任务标签"));
    }

}


//返回任务对应周的index
int MainWindow::match(QString str){
    if(str == "周一") return 0;
    else if(str == "周二") return 1;
    else if(str == "周三") return 2;
    else if(str == "周四") return 3;
    else if(str == "周五") return 4;
    else if(str == "周六") return 5;
    else if(str == "周日") return 7;
    else return -1;
}


//添加任务
void MainWindow::addTask(){
    InputDialog* dialog = new InputDialog(this);
    dialog->exec();
    Task task;

    //获取task对应的周 设置task 开始结束时间、任务等级等信息
    QString week = dialog->taskStartTime.toString("ddd");
    QString time_Of_Task = dialog->taskStartTime.toString("MM-dd");
    DayTask dayTask;
    if(allTask.ifExistDayTaskList(time_Of_Task.toStdString())){
        dayTask = allTask.getDayTaskMap(time_Of_Task.toStdString());
    }
    else{
        dayTask.setTimeOfToday(time_Of_Task.toStdString());
    }
    task.setStartTime(dialog->taskStartTime.toString("hh:mm").toStdString());
    task.setEndTime(dialog->taskEndTime.toString("hh:mm").toStdString());
    task.setTaskName(dialog->taskName.toStdString());
    task.setTaskLabel(dialog->taskLabel.toStdString());
    if(dialog->taskLevel == "一") task.setTaskLevel(TaskLevel::level_1);
    else if(dialog->taskLevel == "二") task.setTaskLevel(TaskLevel::level_2);
    else task.setTaskLevel(TaskLevel::level_3);

    //设置对应的widget界面
    int w = match(week);
    ui->tabWidget->setCurrentIndex(w);

    //添加任务操作
    if(w == -1){
        QMessageBox* remind_Dialog = new QMessageBox(this);
        remind_Dialog->setText("输入错误");
        remind_Dialog->exec();
    }
    else{
        //list中添加任务
        dayTask.addTask(task);
        int current_Row = 1;
        for(auto it:dayTask.getTaskList()){
            QString level;
            if(it.getTaskLevel() == TaskLevel::level_1) level = "一";
            else if(it.getTaskLevel() == TaskLevel::level_2) level = "二";
            else level = "三";
            list.at(w)->setItem(current_Row,0,new QTableWidgetItem(QString::fromStdString(it.getTaskName())));
            list.at(w)->setItem(current_Row,1,new QTableWidgetItem(level));
            list.at(w)->setItem(current_Row,2,new QTableWidgetItem(QString::fromStdString(it.getStartTime())));
            list.at(w)->setItem(current_Row,3,new QTableWidgetItem(QString::fromStdString(it.getEndTime())));
            list.at(w) ->setItem(current_Row,4,new QTableWidgetItem(QString::fromStdString((it.getTaskLabel()))));
            current_Row++;
        }
        row[w] = current_Row;
    }
}

void MainWindow::deleteTask(){
    int nowIndex = ui->tabWidget->currentIndex();
    if(nowIndex != -1 && row[nowIndex] > 0){
        int currentRow = list.at(nowIndex)->currentRow();
        list.at(nowIndex)->removeRow(currentRow);
        row[nowIndex]--;

        //从总任务中删除任务
        QAbstractItemModel *modessl = list.at(nowIndex)->model();
        QModelIndex index_Name = modessl->index(currentRow,0);
        QModelIndex index_Level = modessl->index(currentRow,1);
        QModelIndex index_StartTime = modessl->index(currentRow,2);
        QModelIndex index_EndTime = modessl->index(currentRow,3);
        QModelIndex index_Label = modessl->index(currentRow,4);
        string taskName = modessl->data(index_Name).toString().toStdString();
        string taskLevel = modessl->data(index_Level).toString().toStdString();
        TaskLevel level;
        if(taskLevel == "一")  level = TaskLevel::level_1;
        else if(taskLevel == "二")  level = TaskLevel::level_2;
        else level = TaskLevel::level_3;
        string taskStartTime = modessl->data(index_StartTime).toString().toStdString();
        string taskEndTime = modessl->data(index_EndTime).toString().toStdString();
        string taskLabel = modessl->data(index_Label).toString().toStdString();
        Task task(taskStartTime,taskEndTime,taskName,level,taskLabel);

    }
    else if(nowIndex == -1){
        QMessageBox* remind_Dialog = new QMessageBox(this);
        remind_Dialog->setWindowTitle("Error");
        remind_Dialog->setText("输入错误");
        remind_Dialog->exec();
    }
    else {
        QMessageBox* remind_Dialog = new QMessageBox(this);
        remind_Dialog->setWindowTitle("Error");
        remind_Dialog->setText("任务栏为空，请先设置任务");
        remind_Dialog->exec();
    }
}
