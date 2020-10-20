#ifndef TIMEMODIFYDIALOG_H
#define TIMEMODIFYDIALOG_H

#include <QDialog>
#include<QDateTime>

namespace Ui {
class TimeModifyDialog;
}

class TimeModifyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TimeModifyDialog(QDateTime taskTime,QString str,QWidget *parent = nullptr);
    ~TimeModifyDialog();
    QDateTime getTime();
    QString getDay();

private:
    Ui::TimeModifyDialog *ui;
};

#endif // TIMEMODIFYDIALOG_H
