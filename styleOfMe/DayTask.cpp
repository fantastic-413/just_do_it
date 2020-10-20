//
// Created by L&S&P& on 2020/9/25.
//

#include "DayTask.h"
#include "global.h"

//添加任务 addTask()
void DayTask::addTask(Task task) {
    task_label_list.push_back(task.getTaskLabel());
    task_list.push_back(task);
    task_list.sort();
    allTask.addAllTask(task);
    allTask.setDayTaskMap(time_of_Today, *this);
}

//删除任务 deleteTask()
void DayTask::deleteTask(Task task) {
    task_label_list.remove(task.getTaskLabel());
    task_list.remove(task);
    allTask.deleteFromAllTask(task);
    allTask.setDayTaskMap(time_of_Today, *this);
}

//完成任务  finishTask()
void DayTask::finishTask(Task task) {
    task_label_list.remove(task.getTaskLabel());
    task_list.remove(task);
    allTask.addFinishedTask(task);
    allTask.setDayTaskMap(time_of_Today, *this);
}

//构造函数和析构函数
DayTask::DayTask() {}

DayTask::DayTask(const string &timeOfToday, const list<string> &taskLabelList, const list<Task> &taskList)
        : time_of_Today(timeOfToday), task_label_list(taskLabelList), task_list(taskList) {}

DayTask::~DayTask() {

}

//Getter and Setter
const string &DayTask::getTimeOfToday() const {
    return time_of_Today;
}

void DayTask::setTimeOfToday(const string &timeOfToday) {
    time_of_Today = timeOfToday;
}

const list<string> &DayTask::getTaskLabelList() const {
    return task_label_list;
}

void DayTask::setTaskLabelList(const list<string> &taskLabelList) {
    task_label_list = taskLabelList;
}

const list<Task> &DayTask::getTaskList() const {
    return task_list;
}

void DayTask::setTaskList(const list<Task> &taskList) {
    task_list = taskList;
}

//打印函数
ostream &operator<<(ostream &os, const DayTask &dayTask) {
    os << "time_of_Today: " << dayTask.time_of_Today << endl << " task_label_list: " << endl;
    for (auto task_label:dayTask.task_label_list) {
        cout << task_label << endl;
    }
    cout << " task_list: " << endl;
    for (auto task:dayTask.task_list) {
        cout << task << endl;
    }
    return os;
}

//重载==和！=
bool DayTask::operator==(const DayTask &rhs) const {
    return time_of_Today == rhs.time_of_Today &&
           task_label_list == rhs.task_label_list &&
           task_list == rhs.task_list;
}

bool DayTask::operator!=(const DayTask &rhs) const {
    return !(rhs == *this);
}



