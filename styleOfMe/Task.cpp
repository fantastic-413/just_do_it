//
// Created by L&S&P& on 2020/9/19.
//

#include "Task.h"

//创建任务 setTask()函数实现
Task Task::setTask() {

}

Task::Task() {}

Task::Task(const string &startTime, const string &endTime, const string &taskName, TaskLevel taskLevel,
           const string &taskLabel) : start_time(startTime), end_time(endTime), task_name(taskName),
                                      task_level(taskLevel), task_label(taskLabel) {}

Task::~Task() {

}

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

ostream &operator<<(ostream &os, const Task &task) {
    os << "start_time: " << task.start_time << " end_time: " << task.end_time << " task_name: " << task.task_name
       << " task_level: " << task.task_level << " task_label: " << task.task_label;
    return os;
}
