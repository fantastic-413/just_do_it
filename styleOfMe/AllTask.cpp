﻿//
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
DayTask &AllTask::getDayTaskMap(string time_of_Today) {  //"10-13"
    return DayTask_map[time_of_Today];
}

//添加每一天及对应任务map集合 setDayTaskMap(string time_of_Today,list<Task> task_listOfDay)
void AllTask::setDayTaskMap(string time_of_Today, DayTask dayTask) {
    DayTask_map[time_of_Today] = dayTask;
}

//从文件"allTask.txt"中读取allTask
AllTask AllTask::readFromFile() {
    ifstream ifs("D:\\allTask.txt", ios::binary | ios::in);
    if (!ifs.is_open()) {
        ifs.close();
        return AllTask();
    } else {
        AllTask allTask_help;
        DayTask dayTask;
        Task task;
//        char* time_of_Today = new char[10];
        string time_of_Today;
        string start_time;
        string end_time;
        string task_name;
        TaskLevel task_level;
        int level;
        string task_label;
        int start_time_size;
        int end_time_size;
        int task_name_size;
        int task_label_size;
        int time_of_Today_size;
        //读取总任务类
        //1.读取总任务类里各成员变量个数
        //a.读取总任务个数
        int allTask_size;
        //b.读取已完成任务个数
        int finishedTask_size;
        //c.读取日任务个数
        int dayTask_map_size;
        ifs.read((char*)&allTask_size,sizeof(int));
        cout<<allTask_size<<endl;
        ifs.read((char*)&finishedTask_size,sizeof(int));
        cout<<finishedTask_size<<endl;
        ifs.read((char*)&dayTask_map_size,sizeof(int));
        cout<<dayTask_map_size<<endl;
        //2.逐个读取总任务并加入集合
        for (int i = 1; i <= allTask_size; ++i){
            ifs.read((char*)&start_time_size,sizeof(int));
            cout<<start_time_size<<endl;
            ifs.read((char*)&end_time_size,sizeof(int));
            cout<<end_time_size<<endl;
            ifs.read((char*)&task_name_size,sizeof(int));
            cout<<task_name_size<<endl;
            ifs.read((char*)&task_label_size,sizeof(int));
            cout<<task_label_size<<endl;
            ifs.read((char*)&start_time,start_time_size);
            start_time = (string)start_time;
            cout<<start_time<<endl;
            ifs.read((char*)&end_time,end_time_size);
            end_time = (string)end_time;
            cout<<end_time<<endl;
            ifs.read((char*)&task_name,task_name_size);
            task_name = (string)task_name;
            cout<<task_name<<endl;
            ifs.read((char*)&level,sizeof(int));
            cout<<level<<endl;
            if(level==1)
                task_level=TaskLevel::level_1;
            else
                task_level = (level==2)?TaskLevel::level_2:TaskLevel::level_3;
            ifs.read((char*)&task_label,task_label_size);
            cout<<task_label<<endl;
            Task task(start_time,end_time,task_name,task_level,task_label);
            allTask_help.addAllTask(task);
            cout<<"*"<<task<<"*";
        }
        //3.逐个读取已完成任务并加入集合
        for (int i = 1; i <= finishedTask_size; ++i){
            ifs.read((char*)&start_time_size,sizeof(int));
            cout<<start_time_size<<endl;
            ifs.read((char*)&end_time_size,sizeof(int));
            cout<<end_time_size<<endl;
            ifs.read((char*)&task_name_size,sizeof(int));
            cout<<task_name_size<<endl;
            ifs.read((char*)&task_label_size,sizeof(int));
            cout<<task_label_size<<endl;
            ifs.read((char*)&start_time,start_time_size);
            start_time = (string)start_time;
            cout<<start_time<<endl;
            ifs.read((char*)&end_time,end_time_size);
            end_time = (string)end_time;
            cout<<end_time<<endl;
            ifs.read((char*)&task_name,task_name_size);
            task_name = (string)task_name;
            cout<<task_name<<endl;
            ifs.read((char*)&level,sizeof(int));
            cout<<level<<endl;
            if(level==1)
                task_level=TaskLevel::level_1;
            else
                task_level = (level==2)?TaskLevel::level_2:TaskLevel::level_3;
            ifs.read((char*)&task_label,task_label_size);
            cout<<task_label<<endl;
            Task task(start_time,end_time,task_name,task_level,task_label);
            cout<<"*"<<task<<"*";
            allTask_help.addFinishedTask(task);
        }
        //4.逐个读取日任务类并加入map集合
        for (int i = 1; i <= dayTask_map_size; ++i){
            ifs.read((char*)&time_of_Today_size,sizeof(int));
            ifs.read((char*)&time_of_Today,time_of_Today_size);
            time_of_Today = (string)time_of_Today;
            cout<<"*"<<time_of_Today<<"*";
            //读取日任务类
            //1.给日任务类赋时间
            dayTask.setTimeOfToday(time_of_Today);
            //2.读取日任务类里任务个数
            int task_size;
            ifs.read((char*)&task_size,sizeof(int));
            cout<<task_size<<endl;
            //3.逐个读取任务赋给日任务类
            for (int i = 1; i <= task_size; ++i){
                ifs.read((char*)&start_time_size,sizeof(int));
                cout<<start_time_size<<endl;
                ifs.read((char*)&end_time_size,sizeof(int));
                cout<<end_time_size<<endl;
                ifs.read((char*)&task_name_size,sizeof(int));
                cout<<task_name_size<<endl;
                ifs.read((char*)&task_label_size,sizeof(int));
                cout<<task_label_size<<endl;
                ifs.read((char*)&start_time,start_time_size);
                start_time = (string)start_time;
                cout<<start_time<<endl;
                ifs.read((char*)&end_time,end_time_size);
                end_time = (string)end_time;
                cout<<end_time<<endl;
                ifs.read((char*)&task_name,task_name_size);
                task_name = (string)task_name;
                cout<<task_name<<endl;
                ifs.read((char*)&level,sizeof(int));
                cout<<level<<endl;
                if(level==1)
                    task_level=TaskLevel::level_1;
                else
                    task_level = (level==2)?TaskLevel::level_2:TaskLevel::level_3;
                ifs.read((char*)&task_label,task_label_size);
                cout<<task_label<<endl;
                Task task(start_time,end_time,task_name,task_level,task_label);
                cout<<"*"<<task<<"*";
                dayTask.justAddTask(task);
            }
            allTask_help.setDayTaskMap(time_of_Today,dayTask);
        }
        ifs.close();
        return allTask_help;
    }
}
//把allTask保存到文件"allTask.txt"中
void AllTask::saveAllTaskToFile() {
    ofstream ofs("D:\\allTask.txt", ios::out | ios::binary | ios::trunc);
    //写入总任务类
    //1.写入总任务类里各成员变量个数，方便读取
    //a.写入总任务个数
    int allTask_size = allTask_list.size();
    //b.写入已完成任务个数
    int finishedTask_size = finishedTask_list.size();
    //c.写入日任务类个数
    int dayTask_map_size = DayTask_map.size();
    ofs.write((char*)&allTask_size,sizeof(int));
    ofs.write((char*)&finishedTask_size,sizeof(int));
    ofs.write((char*)&dayTask_map_size,sizeof(int));
    //2.逐个写入总任务集合中任务
    for (auto task:(*this).allTask_list) {
        int start_time_size=sizeof(task.getStartTime());
        int end_time_size=sizeof(task.getEndTime());
        int task_name_size=sizeof(task.getTaskName());
        int task_label_size=sizeof(task.getTaskLabel());
        ofs.write((char*)&start_time_size,sizeof(int));
        ofs.write((char*)&end_time_size,sizeof(int));
        ofs.write((char*)&task_name_size,sizeof(int));
        ofs.write((char*)&task_label_size,sizeof(int));
        ofs.write((char*)&task.getStartTime(),sizeof(task.getStartTime()));
        ofs.write((char*)&task.getEndTime(),sizeof(task.getEndTime()));
        ofs.write((char*)&task.getTaskName(),sizeof(task.getTaskName()));
        int level;
        if(task.getTaskLevel()==TaskLevel::level_1)
            level = 1;
        else
            level = (task.getTaskLevel()==TaskLevel::level_2)?2:3;
        ofs.write((char*)&level,sizeof(int));
        ofs.write((char*)&task.getTaskLabel(),sizeof(task.getTaskLabel()));
    }
    //3.逐个写入已完成任务集合中任务
    for (auto task:(*this).finishedTask_list) {
        int start_time_size=sizeof(task.getStartTime());
        int end_time_size=sizeof(task.getEndTime());
        int task_name_size=sizeof(task.getTaskName());
        int task_label_size=sizeof(task.getTaskLabel());
        ofs.write((char*)&start_time_size,sizeof(int));
        ofs.write((char*)&end_time_size,sizeof(int));
        ofs.write((char*)&task_name_size,sizeof(int));
        ofs.write((char*)&task_label_size,sizeof(int));
        ofs.write((char*)&task.getStartTime(),sizeof(task.getStartTime()));
        ofs.write((char*)&task.getEndTime(),sizeof(task.getEndTime()));
        ofs.write((char*)&task.getTaskName(),sizeof(task.getTaskName()));
        int level;
        if(task.getTaskLevel()==TaskLevel::level_1)
            level = 1;
        else
            level = (task.getTaskLevel()==TaskLevel::level_2)?2:3;
        ofs.write((char*)&level,sizeof(int));
        ofs.write((char*)&task.getTaskLabel(),sizeof(task.getTaskLabel()));
    }
    //4.逐个写入日任务类map集合中日期与日任务类
    for (auto dayTask_map:(*this).DayTask_map) {
//        char* time_of_Today = new char[10];
//        dayTask_map.first.copy(time_of_Today,10);
//        cout<<"*"<<time_of_Today<<"*";
        string time_of_Today = dayTask_map.first;
        int time_of_Today_size = sizeof (time_of_Today);
        ofs.write((char*)&time_of_Today_size,sizeof(int));
        ofs.write((char*)&time_of_Today,sizeof(time_of_Today));
        //写入日任务类
        //1.写入日任务类里任务个数，方便读取任务
        int task_size = dayTask_map.second.getTaskList().size();
        ofs.write((char*)&task_size,sizeof(int));
        //2.逐个写入日任务类里任务
        for (auto task:dayTask_map.second.getTaskList()) {
            int start_time_size=sizeof(task.getStartTime());
            int end_time_size=sizeof(task.getEndTime());
            int task_name_size=sizeof(task.getTaskName());
            int task_label_size=sizeof(task.getTaskLabel());
            ofs.write((char*)&start_time_size,sizeof(int));
            ofs.write((char*)&end_time_size,sizeof(int));
            ofs.write((char*)&task_name_size,sizeof(int));
            ofs.write((char*)&task_label_size,sizeof(int));
            ofs.write((char*)&task.getStartTime(),sizeof(task.getStartTime()));
            ofs.write((char*)&task.getEndTime(),sizeof(task.getEndTime()));
            ofs.write((char*)&task.getTaskName(),sizeof(task.getTaskName()));
            int level;
            if(task.getTaskLevel()==TaskLevel::level_1)
                level = 1;
            else
                level = (task.getTaskLevel()==TaskLevel::level_2)?2:3;
            ofs.write((char*)&level,sizeof(int));
            ofs.write((char*)&task.getTaskLabel(),sizeof(task.getTaskLabel()));
        }
    }
    ofs.close();
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
        os << task;
    }
    os << " finishedTask_list: " << endl;
    for (auto task:allTask.finishedTask_list) {
        os << task;
    }
    os << " DayTask_map: " << endl;
    for (auto dayTask_map:allTask.DayTask_map) {
        os << dayTask_map.second;
    }
    os<<endl;
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
