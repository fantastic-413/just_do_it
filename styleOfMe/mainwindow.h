﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTableWidget>
#include"AllTask.h"
#include<QLabel>
#include<QMap>
#include"global.h"
#include<QDateTime>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initial();
    int getWeek(QDateTime timeOfToday);
    int match(QString str);
    int currentWeekIndex = 0;
    QList<QTableWidget*> list;//下标从0开始
    QList<QLabel*> label_list;//下标从0开始
    QList<QString> week_list;//下标从0开始
    QList<QWidget*> tab_list;
    QList<QString> item_list;
    void addTask();
    void deleteTask();
    void showOnScreen(DayTask dayTask,int w);
    void modifyTask();
    void setDate(int day,int index);
    void paintEvent(QPaintEvent* );
    void cls();
    void finished(int row,int col);
    int row[54][7];
    void hintDialog(QString s1,QString s2 = "");
    Task getData(int currentRow);
    void up();
    void down();
    void showAllTask();
    void showFinishedTask();
    void setting();
    void backToToday();
    void ring();
private:
    QDateTime firstDay;
    QMap<int,QList<QString>> weekContainer; //下标从1开始
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
