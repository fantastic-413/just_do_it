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
#include"showdialog.h"
#include "calendarwidget.h"

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
    //up
    connect(ui->upBtn,&QPushButton::clicked,this,&MainWindow::up);
    //down
    connect(ui->downBtn,&QPushButton::clicked,this,&MainWindow::down);
    //总任务栏
    connect(ui->actionAllTask,&QAction::triggered,this,&MainWindow::showAllTask);
    //已完成任务栏
    connect(ui->actionFinishedTask,&QAction::triggered,this,&MainWindow::showFinishedTask);
<<<<<<< HEAD
    //月视图
    connect(ui->actiony, &QAction::triggered, this, [=](){
        CalendarWidget *calendar = new CalendarWidget(nullptr);
        calendar->setFixedSize(600,400);
        calendar->show();
    });
=======
    //今天
    connect(ui->impBtn,&QPushButton::clicked,this,&MainWindow::backToToday);
>>>>>>> 13cfd61692f6f0362127d80cda83511b28f18a17
}
//析构函数
MainWindow::~MainWindow()
{
    delete ui;
}
//初始化
void MainWindow::initial(){
    setting();
    week_list<<"周一"<<"周二"<<"周三"<<"周四"<<"周五"<<"周六"<<"周日";
    tab_list<< ui->tab << ui->tab_2 << ui->tab_3 << ui->tab_4 << ui->tab_5 << ui->tab_6 << ui->tab_7;
    label_list << ui->label << ui->label_2 << ui->label_3 << ui->label_4 << ui->label_5 << ui->label_6 << ui->label_7;
    item_list << "任务名称" << "任务等级" << "任务开始时间" << "任务结束时间" << "任务标签" << "日期";
    for(int i = 0; i < 54;i++)
        for(int j = 0;j < 7; j++)
            row[i][j] = 0;
    for(int i = 0;i < 7;i++){
        QTableWidget* tableWidget = new QTableWidget (tab_list.at(i));
        list << tableWidget;
    }

    QDateTime timeOfToday = QDateTime::currentDateTime();
    int nowIndex = match(timeOfToday.toString("ddd"));
    for(int i = 0; i < 7;i++){
        list.at(i)->setFixedSize(830,700);
        //设置不可编辑
        list.at(i)->setEditTriggers(QAbstractItemView::NoEditTriggers);
        list.at(i)->setRowCount(100);
        list.at(i)->setColumnCount(6);
        for(int j = 0; j<= 5; j++){
            list.at(i)->setItem(0,j,new QTableWidgetItem(item_list.at(j)));
        }
    }
    //设置默认index
    currentWeekIndex = getWeek(timeOfToday);
    QString month = QString("%1%2").arg(weekContainer[currentWeekIndex].at(3).split("-")[0]).arg("月");
    ui->monthLabel->setText(month);
        for(int i = 0;i < 7; i++){
        label_list.at(i)->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        label_list.at(i)->setText(weekContainer[currentWeekIndex].at(i).split("-")[1]);
        if(allTask.ifExistDayTaskList(weekContainer[currentWeekIndex].at(i).toStdString())){
            showOnScreen(allTask.getDayTaskMap(weekContainer[currentWeekIndex].at(i).toStdString()),i);
        }
    }
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

void MainWindow::addTask(){
    InputDialog* dialog = new InputDialog(this);
    dialog->exec();
    Task task;

    //获取task对应的周 设置task 开始结束时间、任务等级等信息
    QString week = dialog->taskStartTime.toString("ddd");
    QDateTime startDate = dialog->taskStartTime;
    QString time_Of_Task = startDate.toString("MM-dd");
    QDateTime endDate = dialog->taskEndTime;
    QString end_time_Of_Task = endDate.toString("MM-dd");
    string startTime = dialog->taskStartTime.toString("hh:mm").toStdString();
    string endTime = dialog->taskEndTime.toString("hh:mm").toStdString();
    int weekIndex = getWeek(startDate);
    DayTask dayTask;
    if(allTask.ifExistDayTaskList(time_Of_Task.toStdString())){
        dayTask = allTask.getDayTaskMap(time_Of_Task.toStdString());
    }
    else{
        dayTask.setTimeOfToday(time_Of_Task.toStdString());
    }
    if((startDate.toMSecsSinceEpoch() - endDate.toMSecsSinceEpoch() > 0) || (time_Of_Task == end_time_Of_Task && startTime > endTime)){
        hintDialog("输入时间信息错误","Error");
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
        hintDialog("输入错误","Error");
    }
    else{
        //list中添加任务
        row[weekIndex - 1][w]++;
        dayTask.addTask(task);
        //判断第几周
        if(currentWeekIndex != weekIndex){
            if(currentWeekIndex != 0) cls();
            currentWeekIndex = weekIndex;
            QString month = QString("%1%2").arg(weekContainer[currentWeekIndex].at(3).split("-")[0]).arg("月");
            ui->monthLabel->setText(month);
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
        ui->tabWidget->setCurrentIndex(w);
    }  
}

void MainWindow::deleteTask(){
    int nowIndex = ui->tabWidget->currentIndex();
    if(nowIndex != -1 && row[currentWeekIndex - 1][nowIndex] > 0){
        int currentRow = list.at(nowIndex)->currentRow();
        //从总任务中删除任务
        QAbstractItemModel *modessl = list.at(nowIndex)->model();
        QModelIndex index_today = modessl->index(currentRow,5);
        string time_Of_Today = modessl->data(index_today).toString().toStdString();
        Task task = getData(currentRow);
        DayTask dayTask = allTask.getDayTaskMap(time_Of_Today);
        dayTask.deleteTask(task);
        list.at(nowIndex)->removeRow(row[currentWeekIndex-1][nowIndex]--);
        showOnScreen(dayTask,nowIndex);
    }
    else if(nowIndex == -1){
        hintDialog("输入错误","Error");
    }
    else {
        hintDialog("任务栏为空，请先设置任务","Error");
    }
}

void MainWindow::finished(int row1,int col){
    if(row1 == 0 || col == 5 || row1 > row[currentWeekIndex - 1][ui->tabWidget->currentIndex()]) return;
    QMessageBox* remind_Dialog = new QMessageBox(this);
    remind_Dialog->setWindowTitle("确定Dialog");
    remind_Dialog->setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    remind_Dialog->button(QMessageBox::Ok)->setText("确定");
    remind_Dialog->button(QMessageBox::Cancel)->setText("取消");
    remind_Dialog->setText("您确定完成该任务？");
    int nowIndex = ui->tabWidget->currentIndex();
    int x = remind_Dialog->exec();
    if(x == QMessageBox::Ok){
        QAbstractItemModel *modessl = list.at(nowIndex)->model();
        QModelIndex index_today = modessl->index(row1,5);
        string time_Of_Today = modessl->data(index_today).toString().toStdString();
        Task task = getData(row1);
        DayTask dayTask = allTask.getDayTaskMap(time_Of_Today);
        dayTask.finishTask(task);
        list.at(nowIndex)->removeRow(row[currentWeekIndex - 1][nowIndex]--);
        showOnScreen(dayTask,nowIndex);
    }
    else {
        return;
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
        disconnect(list.at(w),&QTableWidget::cellDoubleClicked,this,&MainWindow::finished);
        connect(list.at(w),&QTableWidget::cellDoubleClicked,this,&MainWindow::finished);
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
            hintDialog("选择错误","Error");
        }
        else{
            QString label = ui->monthLabel->text();
            QAbstractItemModel *modessl = list.at(nowIndex)->model();
            QModelIndex index_today = modessl->index(currentRow,5);
            Task task = getData(currentRow);
            string taskName = task.getTaskName();
            string time_Of_Today = modessl->data(index_today).toString().toStdString();
            string modifyTime_Of_Today = time_Of_Today;
            TaskLevel level = task.getTaskLevel();
            string taskStartTime = task.getStartTime();
            string taskEndTime = task.getEndTime();
            string taskLabel = task.getTaskLabel();
            int modifyIndex = nowIndex;
            DayTask dayTask = allTask.getDayTaskMap(time_Of_Today);
            dayTask.deleteTask(task);
            QDateTime modifyTime;
            switch(currentCol){
            case 0:{
                ModifyDialog* modDialog = new ModifyDialog("任务名称",this);
                modDialog->setWindowTitle("modify");
                modDialog->move(this->width() * 0.5 - modDialog->width() * 0.5 + 380,this->height() * 0.5 - modDialog->height() * 0.5 + 160);
                if(modDialog->exec() == 1){
                    taskName = modDialog->getModifyText().toStdString();
                }
                break;
            }
            case 1:{
                LevelDialog* levelDialog = new LevelDialog(this);
                levelDialog->move(this->width() * 0.5 - levelDialog->width() * 0.5 + 380,this->height() * 0.5 - levelDialog->height() * 0.5 + 160);
                levelDialog->setWindowTitle("modify level");
                if(levelDialog->exec() == 1){
                    level = levelDialog->getLevel();
                }
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
                    hintDialog("输入时间错误","Error");
                    return;
                }
                else{
                    label = startTimeInput->getTime().toString("MM");
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
                if(taskStartTime > taskEndTime){
                    hintDialog("输入时间错误","Error");
                    return;
                }
                break;
            }
            case 4:{
                ModifyDialog* modDialog = new ModifyDialog("任务标签",this);
                modDialog->setWindowTitle("modify");
                modDialog->move(this->width() * 0.5 - modDialog->width() * 0.5 + 380,this->height() * 0.5 - modDialog->height() * 0.5 + 160);
                if(modDialog->exec() == 1){
                    taskLabel = modDialog->getModifyText().toStdString();
                }
                break;
            }
            case 5:{
                break;
            }
            }

            list.at(nowIndex)->removeRow(row[currentWeekIndex - 1][nowIndex]--);
            task = Task(taskStartTime,taskEndTime,taskName,level,taskLabel);
            if(modifyTime_Of_Today == time_Of_Today){
                row[currentWeekIndex - 1][nowIndex]++;
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
                    cls();
                    currentWeekIndex = weekIndex;
                    QString month = QString("%1%2").arg(weekContainer[currentWeekIndex].at(3).split("-")[0]).arg("月");
                    ui->monthLabel->setText(month);
                    QList<QString> l = weekContainer[currentWeekIndex];
                    for(int i = 0; i < 7; i++){
                        label_list.at(i)->setText(l.at(i).split("-")[1]);
                        if(allTask.ifExistDayTaskList(l.at(i).toStdString())){
                            showOnScreen(allTask.getDayTaskMap(l.at(i).toStdString()),i);
                        }
                    }
                }
                else{
                    row[currentWeekIndex - 1][modifyIndex]++;
                    showOnScreen(dayTask,nowIndex);
                    showOnScreen(modifyDayTask,modifyIndex);
                }
                ui->tabWidget->setCurrentIndex(modifyIndex);
            }
        }

    }
    else if(nowIndex == -1){
        hintDialog("输入错误","Error");
    }
    else {
        hintDialog("任务栏为空，请先设置任务","Error");
    }
}

void MainWindow::paintEvent(QPaintEvent* ){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/uiBackground.jpg");
    pix = pix.scaled(900,700);
    painter.drawPixmap(list.at(1)->x(),list.at(1)->y(),pix);
}

int MainWindow::getWeek(QDateTime timeOfToday){
    QString s = timeOfToday.toString("MM-dd");
    int week = 1;
    for(;week <= 54; week++){
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

void MainWindow::hintDialog(QString s1,QString s2){
    QMessageBox* remind_Dialog = new QMessageBox(this);
    remind_Dialog->setWindowTitle(s2);
    remind_Dialog->setText(s1);
    remind_Dialog->exec();
}

Task MainWindow::getData(int currentRow){
    int nowIndex = ui->tabWidget->currentIndex();
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
    return task;
}

void MainWindow::up(){
    if(currentWeekIndex > 1){
        cls();
        currentWeekIndex = currentWeekIndex - 1;
        QString month = QString("%1%2").arg(weekContainer[currentWeekIndex].at(3).split("-")[0]).arg("月");
        ui->monthLabel->setText(month);
        for(int i = 0;i < 7; i++){
            label_list.at(i)->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            label_list.at(i)->setText(weekContainer[currentWeekIndex].at(i).split("-")[1]);
            if(allTask.ifExistDayTaskList(weekContainer[currentWeekIndex].at(i).toStdString())){
                showOnScreen(allTask.getDayTaskMap(weekContainer[currentWeekIndex].at(i).toStdString()),i);
            }
        }

    }
    else return;
}

void MainWindow::down(){
    if(currentWeekIndex < 54){
        cls();
        currentWeekIndex = currentWeekIndex + 1;
        QString month = QString("%1%2").arg(weekContainer[currentWeekIndex].at(3).split("-")[0]).arg("月");
        ui->monthLabel->setText(month);
        for(int i = 0;i < 7; i++){
            label_list.at(i)->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            label_list.at(i)->setText(weekContainer[currentWeekIndex].at(i).split("-")[1]);
            if(allTask.ifExistDayTaskList(weekContainer[currentWeekIndex].at(i).toStdString())){
                showOnScreen(allTask.getDayTaskMap(weekContainer[currentWeekIndex].at(i).toStdString()),i);
            }
        }
    }
    else return;
}

void MainWindow::showAllTask(){
    showDialog* dialog = new showDialog(0,this);
    dialog->show();
}

void MainWindow::showFinishedTask(){
    showDialog* dialog = new showDialog(1,this);
    dialog->show();
}

void MainWindow::setting(){
    QDateTime firstDayOf2020(QDate(2020,1,1));
    firstDay = firstDayOf2020;
    int firstDayOfWeekIndex = match(firstDayOf2020.toString("ddd"));
    if(firstDayOfWeekIndex != 0){
        firstDay = firstDayOf2020.addDays(-firstDayOfWeekIndex);
    }
    for(int i = 0;i < 54;i++){
        QList<QString> l;
        for(int j = 0;j < 7;j++){
            QString s = firstDay.addDays(i * 7 + j).toString("MM-dd");
            l << s;
        }
        weekContainer.insert(i + 1,l);
    }
}

void MainWindow::backToToday(){
    cls();
    QDateTime today = QDateTime::currentDateTime();
    int todayWeekIndex = getWeek(today);
    int todayDayIndex = match(today.toString("ddd"));
    currentWeekIndex = todayWeekIndex;
    for(int i = 0;i < 7;i++){
        label_list.at(i)->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        label_list.at(i)->setText(weekContainer[currentWeekIndex].at(i).split("-")[1]);
        if(allTask.ifExistDayTaskList(weekContainer[currentWeekIndex].at(i).toStdString())){
            showOnScreen(allTask.getDayTaskMap(weekContainer[currentWeekIndex].at(i).toStdString()),i);
        }
    }
    ui->tabWidget->setCurrentIndex(todayDayIndex);
}
