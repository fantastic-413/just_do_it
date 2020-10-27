//
// Created by L&S&P& on 2020/9/25.
//

#include "AllTask.h"

//添加到总任务  addAllTask(Task task)
void AllTask::addAllTask(Task task) {
    allTask_list.push_back(task);
    allTask_list.sort();
}

//添加到已完成任务 addFinishedTask(Task task)
void AllTask::addFinishedTask(Task task) {
    finishedTask_list.push_back(task);
    finishedTask_list.sort();
}

//删除自总任务  deleteFromAllTask(Task task)
void AllTask::deleteFromAllTask(Task task) {
    allTask_list.remove(task);
}

//查询时间（某天）是否有对应任务集合
bool AllTask::ifExistDayTaskList(string time_of_Today) {
    return DayTask_map.count(time_of_Today);
}

//依据时间(某天)查找对应任务集合 getDayTaskMap(string time_of_Toady)
DayTask &AllTask::getDayTaskMap(string time_of_Today) {
    return DayTask_map[time_of_Today];
}

//添加每一天及对应任务map集合 setDayTaskMap(string time_of_Today,list<Task> task_listOfDay)
void AllTask::setDayTaskMap(string time_of_Today, DayTask dayTask) {
    DayTask_map[time_of_Today] = dayTask;
}

//从文件"allTask.txt"中读取allTask
AllTask AllTask::readFromFile() {
    ifstream ifs("D:\\allTask.txt", ios::in | ios::binary);
    if (!ifs.is_open()) {
        ifs.close();
        return AllTask();
    } else {
//        AllTask allTask_read;
//        ifs.read((char *)&allTask_read, sizeof(AllTask));
//        ifs.close();
//        (*this) = allTask_read;
//        return (*this);
        AllTask allTask_help;
        Task task;
        string time_of_Today;
        DayTask dayTask;
        int allTask_size;
        int finishedTask_size;
        int dayTask_map_size;
        ifs.read((char*)&allTask_size,sizeof(int));
        ifs.read((char*)&finishedTask_size,sizeof(int));
        ifs.read((char*)&dayTask_map_size,sizeof(int));
        for (int i = 1; i <= allTask_size; ++i){
            ifs.read((char*)&task,sizeof(Task));
            allTask_help.addAllTask(task);
        }

        for (int i = 1; i <= finishedTask_size; ++i){
            ifs.read((char*)&task,sizeof(Task));
            allTask_help.addFinishedTask(task);
        }
        for (int i = 1; i <= dayTask_map_size; ++i){
            ifs.read((char*)&time_of_Today,sizeof(string));
            ifs.read((char*)&dayTask,sizeof(DayTask));
            allTask_help.setDayTaskMap(time_of_Today,dayTask);
        }
        return allTask_help;
    }
}

//把allTask保存到文件"allTask.txt"中
void AllTask::saveAllTaskToFile() {
<<<<<<< HEAD
    ofstream ofs("D:\\allTask.txt", ios::out | ios::binary | ios::trunc);
    AllTask allTask_write = (*this);
    ofs.write((char*)&allTask_write,sizeof(AllTask));
    ofs.close();
=======
    ofstream ofs("D:\\just_do_it\\styleOfMe\\allTask.txt", ios::out | ios::binary | ios::trunc);
//    AllTask allTask_write = (*this);
//    ofs.write((char*)&allTask_write,sizeof(AllTask));
//    ofs.close();
    int allTask_size = allTask_list.size();
    int finishedTask_size = finishedTask_list.size();
    int dayTask_map_size = DayTask_map.size();
    ofs.write((char*)&allTask_size,sizeof(int));
    ofs.write((char*)&finishedTask_size,sizeof(int));
    ofs.write((char*)&dayTask_map_size,sizeof(int));
    for (auto task:(*this).allTask_list) {
        ofs.write((char*)&task,sizeof(Task));
    }
    for (auto task:(*this).finishedTask_list) {
        ofs.write((char*)&task,sizeof(Task));
    }
    for (auto dayTask_map:(*this).DayTask_map) {
        ofs.write((char*)&dayTask_map.first,sizeof(string));
        ofs.write((char*)&dayTask_map.second,sizeof(DayTask));
    }
>>>>>>> 0bd7cc62b40073012b46e6b4648a5b48c21d3c5b
}

//查询任务  searchTask()
list<Task> AllTask::searchTask(string task_name) {
    list<Task> searchTask_list;
    list<Task>::iterator it; //声明一个迭代器
    for (it = allTask_list.begin(); it != allTask_list.end(); it++) {
        if (it->getTaskName() == task_name)
            searchTask_list.push_back(*it);
    }
    return searchTask_list;
}

//构造函数和析构函数
AllTask::AllTask() {}

AllTask::~AllTask() {

}

AllTask::AllTask(const list<Task> &allTaskList, const list<Task> &finishedTaskList,
                 const map<string, DayTask> &dayTaskMap)
        : allTask_list(allTaskList), finishedTask_list(finishedTaskList), DayTask_map(dayTaskMap) {}

//Getter and Setter
const list<Task> &AllTask::getAllTaskList() const {
    return allTask_list;
}

void AllTask::setAllTaskList(const list<Task> &allTaskList) {
    allTask_list = allTaskList;
}

const list<Task> &AllTask::getFinishedTaskList() const {
    return finishedTask_list;
}

void AllTask::setFinishedTaskList(const list<Task> &finishedTaskList) {
    finishedTask_list = finishedTaskList;
}

//打印函数
ostream &operator<<(ostream &os, const AllTask &allTask) {
    os << "allTask_list: " << endl;
    for (auto task:allTask.allTask_list) {
        os << task << endl;
    }
    os << " finishedTask_list: " << endl;
    for (auto task:allTask.finishedTask_list) {
        os << task << endl;
    }
    os << " DayTask_map: " << endl;
    for (auto dayTask_map:allTask.DayTask_map) {
        os << dayTask_map.second << endl;
    }
    return os;
}

//重载==和！=
bool AllTask::operator==(const AllTask &rhs) const {
    return allTask_list == rhs.allTask_list &&
           finishedTask_list == rhs.finishedTask_list &&
           DayTask_map == rhs.DayTask_map;
}

bool AllTask::operator!=(const AllTask &rhs) const {
    return !(rhs == *this);
}
