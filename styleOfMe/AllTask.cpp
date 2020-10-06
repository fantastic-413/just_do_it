//
// Created by L&S&P& on 2020/9/25.
//

#include "AllTask.h"
//添加任务 addTask()
void AllTask::addTask(Task task) {
    allTask_list.push_back(task);
    allTask_list.sort();
}
//删除任务 deleteTask(Task task)
void AllTask::deleteTask(Task task) {
    allTask_list.remove(task);
}
//复原任务  renewTask()
void AllTask::renewTask(Task task) {

}
//查询任务  searchTask()
list<Task> AllTask::searchTask(string task_name) {
    list<Task> searchTask_list;
    list<Task>::iterator it; //声明一个迭代器
    for(it = allTask_list.begin();it!=allTask_list.end();it++){
        if(it->getTaskName() == task_name)
            searchTask_list.push_back(*it);
    }
    return searchTask_list;
}
//构造函数和析构函数
AllTask::AllTask() {}

AllTask::AllTask(const list<Task> &allTaskList) : allTask_list(allTaskList) {}

AllTask::~AllTask() {

}
//Getter and Setter
const list<Task> &AllTask::getAllTaskList() const {
    return allTask_list;
}

void AllTask::setAllTaskList(const list<Task> &allTaskList) {
    allTask_list = allTaskList;
}
//打印函数
ostream &operator<<(ostream &os, const AllTask &task) {
    os << "allTask_list: " << task.allTask_list;
    return os;
}
//重载==和！=
bool AllTask::operator==(const AllTask &rhs) const {
    return allTask_list == rhs.allTask_list;
}

bool AllTask::operator!=(const AllTask &rhs) const {
    return !(rhs == *this);
}



