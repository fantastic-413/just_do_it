#include "mainwindow.h"
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
#include<list>
#include"modifydialog.h"
#include"timemodifydialog.h"
#include<QDateTime>
#include"leveldialog.h"
#include<QPainter>
#include<QPixmap>
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
    //修改任务
    connect(ui->modBtn,&QPushButton::clicked,this,&MainWindow::modifyTask);
}
//析构函数
MainWindow::~MainWindow()
{
    delete ui;
}
//初始化
void MainWindow::initial(){
    week_list<<"周一"<<"周二"<<"周三"<<"周四"<<"周五"<<"周六"<<"周日";
    for(int i = 0; i < 5;i++)
        for(int j = 0;j < 7; j++)
            row[i][j] = 1;
    QTableWidget* tableWidget_1 = new QTableWidget(ui->tab);
    QTableWidget* tableWidget_2 = new QTableWidget(ui->tab_2);
    QTableWidget* tableWidget_3 = new QTableWidget(ui->tab_3);
    QTableWidget* tableWidget_4 = new QTableWidget(ui->tab_4);
    QTableWidget* tableWidget_5 = new QTableWidget(ui->tab_5);
    QTableWidget* tableWidget_6 = new QTableWidget(ui->tab_6);
    QTableWidget* tableWidget_7 = new QTableWidget(ui->tab_7);

    label_list << ui->label << ui->label_2 << ui->label_3 << ui->label_4 << ui->label_5 << ui->label_6 << ui->label_7;
    list << tableWidget_1 << tableWidget_2 << tableWidget_3 << tableWidget_4 << tableWidget_5 << tableWidget_6 << tableWidget_7;
    QDateTime timeOfToday = QDateTime::currentDateTime();
    QString dayOfToday = timeOfToday.toString("dd");
    int nowIndex = match(timeOfToday.toString("ddd"));
    int day = dayOfToday.toInt();
    QDateTime firstDay = timeOfToday.addDays(1 - day);
    int firstDayOfWeek = match(firstDay.toString("ddd"));
    if(firstDayOfWeek != 0){
        firstDay = firstDay.addDays(-firstDayOfWeek);
    }

    for(int i = 0; i < 5; i++){
        QList<QString> l;
        for(int j = 0;j < 7;j++){
            l << firstDay.addDays(i * 7 + j).toString("MM-dd");
        }
        weekContainer.insert(i + 1,l);
    }
    for(int i = 0; i < 7;i++){
        list.at(i)->setFixedSize(830,700);
        //设置不可编辑
        list.at(i)->setEditTriggers(QAbstractItemView::NoEditTriggers);
        list.at(i)->setRowCount(100);
        list.at(i)->setColumnCount(6);
        list.at(i)->setItem(0,0,new QTableWidgetItem("任务名称"));
        list.at(i)->setItem(0,1,new QTableWidgetItem("任务等级"));
        list.at(i)->setItem(0,2,new QTableWidgetItem("任务开始时间"));
        list.at(i)->setItem(0,3,new QTableWidgetItem("任务结束时间"));
        list.at(i)->setItem(0,4,new QTableWidgetItem("任务标签"));
        list.at(i)->setItem(0,5,new QTableWidgetItem("日期"));
    }
    //设置默认index
    setDate(day,nowIndex);
    ui->tabWidget->setCurrentIndex(nowIndex);
}


//返回任务对应周的index
int MainWindow::match(QString str){
    if(str == "周一") return 0;
    else if(str == "周二") return 1;
    else if(str == "周三") return 2;
    else if(str == "周四") return 3;
    else if(str == "周五") return 4;
    else if(str == "周六") return 5;
    else if(str == "周日") return 6;
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
    QDateTime startDate = dialog->taskStartTime;
    int weekIndex = getWeek(startDate);
    qDebug() << weekIndex << endl;
    DayTask dayTask;
    if(allTask.ifExistDayTaskList(time_Of_Task.toStdString())){
        dayTask = allTask.getDayTaskMap(time_Of_Task.toStdString());
    }
    else{
        dayTask.setTimeOfToday(time_Of_Task.toStdString());
    }
    string startTime = dialog->taskStartTime.toString("hh:mm").toStdString();
    string endTime = dialog->taskEndTime.toString("hh:mm").toStdString();
    if(startTime > endTime){
        QMessageBox* remind_Dialog = new QMessageBox(this);
        remind_Dialog->setText("输入时间信息错误");
        remind_Dialog->exec();
        return;
    }
    else{
        task.setStartTime(startTime);
        task.setEndTime(endTime);
        task.setTaskName(dialog->taskName.toStdString());
        task.setTaskLabel(dialog->taskLabel.toStdString());
        if(dialog->taskLevel == "一") task.setTaskLevel(TaskLevel::level_1);
        else if(dialog->taskLevel == "二") task.setTaskLevel(TaskLevel::level_2);
        else task.setTaskLevel(TaskLevel::level_3);
    }
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
        row[weekIndex - 1][w]++;
        dayTask.addTask(task);
        //判断第几周
        if(currentWeekIndex != weekIndex){
            currentWeekIndex = weekIndex;
            cls();
            for(int i = 1;i <=7; i++){
                //设置label上的日
                label_list.at(i - 1)->setText(weekContainer[currentWeekIndex].at(i - 1).split("-")[1]);
                if(allTask.ifExistDayTaskList(weekContainer[currentWeekIndex].at(i - 1).toStdString())){
                    showOnScreen(allTask.getDayTaskMap(weekContainer[currentWeekIndex].at(i - 1).toStdString()),i - 1);
                }
            }
        }
        else{
            currentWeekIndex = weekIndex;
            showOnScreen(dayTask,w);
        }
    }
}

void MainWindow::deleteTask(){
    int nowIndex = ui->tabWidget->currentIndex();
    if(nowIndex != -1 && row[currentWeekIndex - 1][nowIndex] > 0){
        int currentRow = list.at(nowIndex)->currentRow();
        //从总任务中删除任务
        QAbstractItemModel *modessl = list.at(nowIndex)->model();
        QModelIndex index_Name = modessl->index(currentRow,0);
        QModelIndex index_Level = modessl->index(currentRow,1);
        QModelIndex index_StartTime = modessl->index(currentRow,2);
        QModelIndex index_EndTime = modessl->index(currentRow,3);
        QModelIndex index_Label = modessl->index(currentRow,4);
        QModelIndex index_today = modessl->index(currentRow,5);
        string taskName = modessl->data(index_Name).toString().toStdString();
        string taskLevel = modessl->data(index_Level).toString().toStdString();
        string time_Of_Today = modessl->data(index_today).toString().toStdString();
        TaskLevel level;
        if(taskLevel == "一")  level = TaskLevel::level_1;
        else if(taskLevel == "二")  level = TaskLevel::level_2;
        else level = TaskLevel::level_3;
        string taskStartTime = modessl->data(index_StartTime).toString().toStdString();
        string taskEndTime = modessl->data(index_EndTime).toString().toStdString();
        string taskLabel = modessl->data(index_Label).toString().toStdString();
        Task task(taskStartTime,taskEndTime,taskName,level,taskLabel);
        DayTask dayTask = allTask.getDayTaskMap(time_Of_Today);
        dayTask.deleteTask(task);
        showOnScreen(dayTask,nowIndex);
        list.at(nowIndex)->removeRow(row[currentWeekIndex-1][nowIndex]--);
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

void MainWindow::showOnScreen(DayTask dayTask,int w){
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
        list.at(w)->setItem(current_Row,4,new QTableWidgetItem(QString::fromStdString((it.getTaskLabel()))));
        list.at(w)->setItem(current_Row,5,new QTableWidgetItem(QString::fromStdString(dayTask.getTimeOfToday())));
        current_Row++;
    }
    row[currentWeekIndex - 1][w] = current_Row - 1;
}

void MainWindow::cls(){
    for(int i = 0;i < 7; i++){
        for(int j = 1;j <= row[currentWeekIndex - 1][i]; j++)
            for(int k = 0; k <= 5;k++)
                list.at(i)->setItem(j,k,new QTableWidgetItem(""));
    }
}
void MainWindow::modifyTask(){
    int nowIndex = ui->tabWidget->currentIndex();
    if(nowIndex != -1 && row[currentWeekIndex - 1][nowIndex] > 0){
        int currentRow = list.at(nowIndex)->currentRow();
        int currentCol = list.at(nowIndex)->currentColumn();
        if(currentRow == 0 || currentRow > row[currentWeekIndex - 1][nowIndex]){
            QMessageBox* remind_Dialog = new QMessageBox(this);
            remind_Dialog->setWindowTitle("Error");
            remind_Dialog->setText("选择错误");
            remind_Dialog->exec();
        }
        else{
            QAbstractItemModel *modessl = list.at(nowIndex)->model();
            QModelIndex index_Name = modessl->index(currentRow,0);
            QModelIndex index_Level = modessl->index(currentRow,1);
            QModelIndex index_StartTime = modessl->index(currentRow,2);
            QModelIndex index_EndTime = modessl->index(currentRow,3);
            QModelIndex index_Label = modessl->index(currentRow,4);
            QModelIndex index_today = modessl->index(currentRow,5);
            string taskName = modessl->data(index_Name).toString().toStdString();
            string taskLevel = modessl->data(index_Level).toString().toStdString();
            string time_Of_Today = modessl->data(index_today).toString().toStdString();
            string modifyTime_Of_Today = time_Of_Today;
            int modifyIndex = nowIndex;
            TaskLevel level;
            if(taskLevel == "一")  level = TaskLevel::level_1;
            else if(taskLevel == "二")  level = TaskLevel::level_2;
            else level = TaskLevel::level_3;
            string taskStartTime = modessl->data(index_StartTime).toString().toStdString();
            string taskEndTime = modessl->data(index_EndTime).toString().toStdString();
            string taskLabel = modessl->data(index_Label).toString().toStdString();
            DayTask dayTask = allTask.getDayTaskMap(time_Of_Today);
            dayTask.deleteTask(Task(taskStartTime,taskEndTime,taskName,level,taskLabel));
            QDateTime modifyTime;
            switch(currentCol){
            case 0:{
                ModifyDialog* modDialog = new ModifyDialog("任务名称",this);
                modDialog->setWindowTitle("modify");
                modDialog->move(this->width() * 0.5 - modDialog->width() * 0.5 + 380,this->height() * 0.5 - modDialog->height() * 0.5 + 160);
                modDialog->exec();
                taskName = modDialog->getModifyText().toStdString();
                break;
            }
            case 1:{
                LevelDialog* levelDialog = new LevelDialog(this);
                levelDialog->move(this->width() * 0.5 - levelDialog->width() * 0.5 + 380,this->height() * 0.5 - levelDialog->height() * 0.5 + 160);
                levelDialog->setWindowTitle("modify level");
                levelDialog->exec();
                level = levelDialog->getLevel();
                break;
            }
            case 2:{
                QString s = QString("%1 2020-%2 %3").arg(week_list.at(nowIndex)).arg(modessl->data(index_today).toString()).arg(QString::fromStdString(taskStartTime));
                TimeModifyDialog* startTimeInput = new TimeModifyDialog(QDateTime::fromString(s,"ddd yyyy-MM-dd hh:mm"),"开始时间",this);
                startTimeInput->move(this->width() * 0.5 - startTimeInput->width() * 0.5 + 380,this->height() * 0.5 + 160 - startTimeInput->height() * 0.5);
                startTimeInput->exec();
                taskStartTime = startTimeInput->getTime().toString("hh:mm").toStdString();
                modifyIndex = MainWindow::match(startTimeInput->getTime().toString("ddd"));
                modifyTime_Of_Today = startTimeInput->getDay().toStdString();
                modifyTime = startTimeInput->getTime();
                if(taskStartTime > taskEndTime){
                    QMessageBox* remind_Dialog = new QMessageBox(this);
                    remind_Dialog->setText("输入时间信息错误！");
                    remind_Dialog->exec();
                    return;
                }
                break;
            }
            case 3:
            {
                QString s = QString("%1 2020-%2 %3").arg(week_list.at(nowIndex)).arg(modessl->data(index_today).toString()).arg(QString::fromStdString(taskEndTime));
                TimeModifyDialog* endTimeInput = new TimeModifyDialog(QDateTime::fromString(s,"ddd yyyy-MM-dd hh:mm"),"结束时间",this);
                endTimeInput->move(this->width() * 0.5 - endTimeInput->width() * 0.5 + 380,this->height() * 0.5 + 160 - endTimeInput->height() * 0.5);
                endTimeInput->exec();
                taskEndTime = endTimeInput->getTime().toString("hh:mm").toStdString();
                modifyIndex = MainWindow::match(endTimeInput->getTime().toString("ddd"));
                modifyTime_Of_Today = endTimeInput->getDay().toStdString();
                if(taskStartTime > taskEndTime){
                    QMessageBox* remind_Dialog = new QMessageBox(this);
                    remind_Dialog->setText("输入时间信息错误！");
                    remind_Dialog->exec();
                    return;
                }
                break;
            }
            case 4:{
                ModifyDialog* modDialog = new ModifyDialog("任务标签",this);
                modDialog->setWindowTitle("modify");
                modDialog->move(this->width() * 0.5 - modDialog->width() * 0.5 + 380,this->height() * 0.5 - modDialog->height() * 0.5 + 160);
                modDialog->exec();
                taskLabel = modDialog->getModifyText().toStdString();
                break;
            }
            }
            list.at(nowIndex)->removeRow(currentRow);
            row[currentWeekIndex - 1][nowIndex]--;
            Task task(taskStartTime,taskEndTime,taskName,level,taskLabel);

            if(modifyTime_Of_Today == time_Of_Today){
                dayTask.addTask(task);
                showOnScreen(dayTask,nowIndex);
            }
            else{
                DayTask modifyDayTask;
                if(!allTask.ifExistDayTaskList(modifyTime_Of_Today)){
                    modifyDayTask.setTimeOfToday(modifyTime_Of_Today);
                    allTask.setDayTaskMap(modifyTime_Of_Today,modifyDayTask);
                }
                else{
                    modifyDayTask = allTask.getDayTaskMap(modifyTime_Of_Today);
                }
                modifyDayTask.addTask(task);
                int weekIndex = getWeek(modifyTime);
                if(weekIndex != currentWeekIndex){
                    currentWeekIndex = weekIndex;
                    cls();
                    QList<QString> l = weekContainer[currentWeekIndex];
                    for(int i = 0; i < 7; i++){
                        label_list.at(i)->setText(l.at(i).split("-")[1]);
                        if(allTask.ifExistDayTaskList(l.at(i).toStdString())){
                            showOnScreen(allTask.getDayTaskMap(l.at(i).toStdString()),i);
                        }
                    }
                }
                else{
                    showOnScreen(dayTask,nowIndex);
                    showOnScreen(modifyDayTask,modifyIndex);
                    row[currentWeekIndex - 1][modifyIndex]++;
                }
            }
        }

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

void MainWindow::paintEvent(QPaintEvent* ){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/uiBackground.jpg");
    pix = pix.scaled(900,700);
    painter.drawPixmap(list.at(1)->x(),list.at(1)->y(),pix);
}

void MainWindow::setDate(int day, int index){
    for(int i = 0; i < 7;i++){
        label_list.at(i)->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        QString s = QString::number(day - index + i);
        label_list.at(i)->setText(s);
    }
}

int MainWindow::getWeek(QDateTime timeOfToday){
    QString s = timeOfToday.toString("MM-dd");
    int week = 1;
    for(;week <= 5; week++){
        QList<QString> ql = weekContainer[week];
        for(int i = 0; i < 7 ;i++){
            if(ql.at(i) == s)
            {
                return week;
            }
        }
    }
    return 0;
}
