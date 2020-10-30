#ifndef SHOWDIALOG_H
#define SHOWDIALOG_H

#include <QMainWindow>

namespace Ui {
class showDialog;
}

class showDialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit showDialog(int x,QWidget *parent = nullptr);
    ~showDialog();

private:
    Ui::showDialog *ui;
};

#endif // SHOWDIALOG_H
