//
// Created by L&S&P& on 2020/9/25.
//

#ifndef STYLEOFME_DAYTASK_H
#define STYLEOFME_DAYTASK_H

#include<iostream>
#include<string>
#include <list>
#include "Task.h"

using namespace std;


class DayTask {
private:
    //当天时间  time_Of_Today
    string time_of_Today;
    //任务标签集合  <label> task_label_list
    list<string> task_label_list;
    //任务集合  <Task> task_list
    list<Task> task_list;
public:
    //添加任务 addTask()
    void addTask(Task task);
    //删除任务 deleteTask(Task task)
    void deleteTask(Task task);
    //完成任务  finishTask()
    void finishTask(Task task);
    //构造函数与析构函数
    DayTask();

    DayTask(const string &timeOfToday, const list<string> &taskLabelList, const list<Task> &taskList);

    virtual ~DayTask();
    //Getter and Setter
    const string &getTimeOfToday() const;

    void setTimeOfToday(const string &timeOfToday);

    const list<string> &getTaskLabelList() const;

    void setTaskLabelList(const list<string> &taskLabelList);

    const list<Task> &getTaskList() const;

    void setTaskList(const list<Task> &taskList);
    //打印函数
    friend ostream &operator<<(ostream &os, const DayTask &dayTask);
    //重载==和！=
    bool operator==(const DayTask &rhs) const;

    bool operator!=(const DayTask &rhs) const;
};


#endif //STYLEOFME_DAYTASK_H
