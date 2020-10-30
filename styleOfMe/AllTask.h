//
// Created by L&S&P& on 2020/9/25.
//

#ifndef STYLEOFME_ALLTASK_H
#define STYLEOFME_ALLTASK_H
#include<iostream>
#include <list>
#include <map>
#include "DayTask.h"
#include <fstream>

using namespace std;

class AllTask {
private:
    //总任务集合  <Task> allTask_list
    list<Task> allTask_list;
    //已完成任务集合 <Task> finishedTask_list
    list<Task> finishedTask_list;
    //每一天对应任务map集合 <time_of_Today,list<Task>> DayTask_map
    map<string,DayTask> DayTask_map;
public:
    //添加到总任务  addAllTask(Task task)
    void addAllTask(Task task);
    //添加到已完成任务 addFinishedTask(Task task)
    void addFinishedTask(Task task);
    //删除自总任务  deleteFromAllTask(Task task)
    void deleteFromAllTask(Task task);
    //查询时间（某天）是否有对应日任务集合
    bool ifExistDayTaskList(string time_of_Today);
    //依据时间(某天)查找对应日任务集合 getDayTaskMap(string time_of_Toady)
    DayTask &getDayTaskMap(string time_of_Today);
    //添加每一天及对应日任务map集合 setDayTaskMap(string time_of_Today,list<Task> task_listOfDay)
    void setDayTaskMap(string time_of_Today,DayTask dayTask);
    //从文件中读取allTask
    AllTask readFromFile();
    //把allTask保存到文件"allTask.txt"中
    void saveAllTaskToFile();
    //查询任务  searchTask()
    list<Task> searchTask(string task_name);
    //构造函数和析构函数
    AllTask();

    AllTask(const list<Task> &allTaskList, const list<Task> &finishedTaskList, const map<string,DayTask> &dayTaskMap);

    friend class showDialog;
    virtual ~AllTask();
    //Getter and Setter


    const list<Task> &getAllTaskList() const;

    void setAllTaskList(const list<Task> &allTaskList);

    const list<Task> &getFinishedTaskList() const;

    void setFinishedTaskList(const list<Task> &finishedTaskList);
    //打印函数
    friend ostream &operator<<(ostream &os, const AllTask &allTask);
    //重载==和！=
    bool operator==(const AllTask &rhs) const;
    bool operator!=(const AllTask &rhs) const;
};


#endif //STYLEOFME_ALLTASK_H
