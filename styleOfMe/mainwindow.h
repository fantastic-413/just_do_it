#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTableWidget>
#include"AllTask.h"
#include<QLabel>
#include"global.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initial();
    int match(QString str);
    QList<QTableWidget*> list;
    QList<QLabel*> label_list;
    QList<QString> week_list;
    void addTask();
    void deleteTask();
    void showOnScreen(DayTask dayTask,int w);
    void modifyTask();
    void paintEvent(QPaintEvent* );
private:
    int row[7] = {1,1,1,1,1,1,1};
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
