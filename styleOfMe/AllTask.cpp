//
// Created by L&S&P& on 2020/9/25.
//

#include "AllTask.h"
//添加任务 addTask()
void AllTask::addTask() {

}
//删除任务 deleteTask(Task task)
void AllTask::deleteTask(Task task) {

}
//复原任务  renewTask()
void AllTask::renewTask(Task task) {

}
//查询任务  searchTask()
list<Task> AllTask::searchTask(string task_name) {
    return list<Task>();
}
//构造函数和析构函数
AllTask::AllTask() {}

AllTask::AllTask(const list<DayTask> &dayTaskList) : DayTask_list(dayTaskList) {}

AllTask::~AllTask() {

}
//Getter and Setter
const list<DayTask> &AllTask::getDayTaskList() const {
    return DayTask_list;
}

void AllTask::setDayTaskList(const list<DayTask> &dayTaskList) {
    DayTask_list = dayTaskList;
}
//打印函数
ostream &operator<<(ostream &os, const AllTask &task) {
    os << "DayTask_list: " << task.DayTask_list;
    return os;
}
//重载==和！=
bool AllTask::operator==(const AllTask &rhs) const {
    return DayTask_list == rhs.DayTask_list;
}

bool AllTask::operator!=(const AllTask &rhs) const {
    return !(rhs == *this);
}

