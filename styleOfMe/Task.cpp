//
// Created by L&S&P& on 2020/9/19.
//

#include "Task.h"

//创建任务 setTask()函数实现
Task Task::setTask() {
    Task task;
    cout << "请输入任务名称" << endl;
    cin >> task.task_name;
    cout << "请输入任务开始时间" << endl;
    cin >> task.start_time;
    cout << "请输入任务结束时间" << endl;
    cin >> task.end_time;
    cout << "请选择任务等级(level_1, level_2, level_3)" << endl;
    int level;
    cin >> level;
    if (level == 1)
        task.task_level = level_1;
    else
        task.task_level = (level == 2) ? level_2 : level_3;
    cout << "请设置任务标签" << endl;
    cin>>task.task_label;

    return task;
}

//构造函数和析构函数
Task::Task() {}

Task::Task(const string &startTime, const string &endTime, const string &taskName, TaskLevel taskLevel,
           const string &taskLabel) : start_time(startTime), end_time(endTime), task_name(taskName),
                                      task_level(taskLevel), task_label(taskLabel) {}

Task::~Task() {

}

//Getter and Setter
const string &Task::getStartTime() const {
    return start_time;
}

void Task::setStartTime(const string &startTime) {
    start_time = startTime;
}

const string &Task::getEndTime() const {
    return end_time;
}

void Task::setEndTime(const string &endTime) {
    end_time = endTime;
}

const string &Task::getTaskName() const {
    return task_name;
}

void Task::setTaskName(const string &taskName) {
    task_name = taskName;
}

TaskLevel Task::getTaskLevel() const {
    return task_level;
}

void Task::setTaskLevel(TaskLevel taskLevel) {
    task_level = taskLevel;
}

const string &Task::getTaskLabel() const {
    return task_label;
}

void Task::setTaskLabel(const string &taskLabel) {
    task_label = taskLabel;
}

//打印函数
ostream &operator<<(ostream &os, const Task &task) {
    os << "start_time: " << task.start_time << " end_time: " << task.end_time << " task_name: " << task.task_name
       << " task_level: " << task.task_level << " task_label: " << task.task_label << endl;
    return os;
}

//重载==和！=
bool Task::operator==(const Task &rhs) const {
    return start_time == rhs.start_time &&
           end_time == rhs.end_time &&
           task_name == rhs.task_name &&
           task_level == rhs.task_level &&
           task_label == rhs.task_label;
}

bool Task::operator!=(const Task &rhs) const {
    return !(rhs == *this);
}
