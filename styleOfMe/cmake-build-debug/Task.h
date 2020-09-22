//
// Created by L&S&P& on 2020/9/19.
//

#ifndef STYLEOFME_TASK_H
#define STYLEOFME_TASK_H

#include<string>

using namespace std;

enum TaskLevel {
    level_1, level_2, level_3
};

class Task {
private:
    //开始时间  start_time（初始化）

    //结束时间  end_time（初始化）

    //任务名称  task_name
    string task_name;
    //任务等级  task_level(初始化为level1）
    TaskLevel task_level;
    //标签 task_label（初始化为null）
    string task_label;
public:
    //创建任务  setTask()
    Task setTask();
};


#endif //STYLEOFME_TASK_H
