#ifndef DAYTASKDIALOG_H
#define DAYTASKDIALOG_H

#include <QMainWindow>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QModelIndex>
#include <DayTask.h>


namespace Ui {
class DayTaskDialog;
}

class DayTaskDialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit DayTaskDialog(QWidget *parent = nullptr);
    ~DayTaskDialog();
    QStringListModel *Model;
    QStandardItemModel *ItemModel;
    void init();
    list<Task> taskList;
private:
    Ui::DayTaskDialog *ui;

private slots:
    void showClick(QModelIndex index);
};

#endif
