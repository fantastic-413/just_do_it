#include "daytaskdialog.h"
#include "ui_daytaskdialog.h"
#include <QMessageBox>
#include <QString>
#include <QDebug>


DayTaskDialog::DayTaskDialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DayTaskDialog)
{
    ui->setupUi(this);
    //init();
}

void DayTaskDialog::init()
{

    QStringList strList;
    QString taskName;

    for(auto task : taskList){
        taskName = QString::fromStdString(task.getTaskName());
        strList.append(taskName);

    }
    Model = new QStringListModel(strList);
    ui->listView->setModel(Model);

    ItemModel = new QStandardItemModel(this);

//    QStringList strList;
//    strList.append("A");
//    strList.append("B");

//    strList.append("C");
//    strList.append("D");
//    strList.append("E");
//    strList.append("F");
//    strList.append("G");

    int nCount = strList.size();
    for(int i = 0; i < nCount; i++)
    {
        QString string = static_cast<QString>(strList.at(i));
        QStandardItem *item = new QStandardItem(string);
        ItemModel->appendRow(item);
    }
    ui->listView->setModel(ItemModel);
    ui->listView->setFixedSize(200,300);

    connect(ui->listView,SIGNAL(clicked(QModelIndex)),this,SLOT(showClick(QModelIndex)));
}

void DayTaskDialog::showClick(QModelIndex index)
{
    QString strTemp;
    strTemp = index.data().toString();

    QMessageBox msg;
    msg.setText(strTemp);
    msg.exec();


}
DayTaskDialog::~DayTaskDialog()
{
    delete ui;
}
