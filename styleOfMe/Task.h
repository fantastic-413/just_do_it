//
// Created by L&S&P& on 2020/9/19.
//

#ifndef STYLEOFME_TASK_H
#define STYLEOFME_TASK_H

#include <iostream>
#include<string>

using namespace std;

enum TaskLevel {
    level_1, level_2, level_3
};

class Task {
private:
    //开始时间  start_time（初始化）
    string start_time;
    //结束时间  end_time（初始化）
    string end_time;
    //任务名称  task_name
    string task_name;
    //任务等级  task_level(初始化为level1）
    TaskLevel task_level;
    //标签 task_label（初始化为null）
    string task_label;
public:
    //创建任务  setTask()
    Task setTask();

    //构造函数
    Task();

    Task(const string &startTime, const string &endTime, const string &taskName, TaskLevel taskLevel,
         const string &taskLabel);

    virtual ~Task();

    //Getter and Setter
    const string &getStartTime() const;

    void setStartTime(const string &startTime);

    const string &getEndTime() const;

    void setEndTime(const string &endTime);

    const string &getTaskName() const;

    void setTaskName(const string &taskName);

    TaskLevel getTaskLevel() const;

    void setTaskLevel(TaskLevel taskLevel);

    const string &getTaskLabel() const;

    void setTaskLabel(const string &taskLabel);

    //打印函数
    friend ostream &operator<<(ostream &os, const Task &task);
};


#endif //STYLEOFME_TASK_H
