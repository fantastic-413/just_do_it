//
// Created by L&S&P& on 2020/9/25.
//

#ifndef STYLEOFME_ALLTASK_H
#define STYLEOFME_ALLTASK_H
#include<iostream>
#include <list>
#include "DayTask.h"

using namespace std;

class AllTask {
private:
    //日任务集合  <DayTask> DayTask_list
    list<DayTask> DayTask_list;
public:
    //添加任务 addTask()
    void addTask();
    //删除任务 deleteTask(Task task)
    void deleteTask(Task task);
    //复原任务  renewTask()
    void renewTask(Task task);
    //查询任务  searchTask()
    list<Task> searchTask(string task_name);
    //构造函数和析构函数
    AllTask();

    AllTask(const list<DayTask> &dayTaskList);

    virtual ~AllTask();
    //Getter and Setter
    const list<DayTask> &getDayTaskList() const;

    void setDayTaskList(const list<DayTask> &dayTaskList);
    //打印函数
    friend ostream &operator<<(ostream &os, const AllTask &task);
    //重载==和！=
    bool operator==(const AllTask &rhs) const;

    bool operator!=(const AllTask &rhs) const;
};


#endif //STYLEOFME_ALLTASK_H
