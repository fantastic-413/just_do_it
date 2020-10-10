#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H
#include<QDateTime>
#include <QDialog>

namespace Ui {
class InputDialog;
}

class InputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputDialog(QWidget *parent = nullptr);
    ~InputDialog();
    QString taskName;
    QDateTime taskStartTime;
    QDateTime taskEndTime;
    QString taskLevel;
    QString taskLabel;

private:
    Ui::InputDialog *ui;
};

#endif // INPUTDIALOG_H
