#ifndef TIMEINPUT_H
#define TIMEINPUT_H

#include <QWidget>
#include<QTableWidget>

namespace Ui {
class TimeInput;
}

class TimeInput : public QWidget
{
    Q_OBJECT

public:
    explicit TimeInput(QWidget *parent = nullptr);
    ~TimeInput();
    QDateTime getTime();

private:
    Ui::TimeInput *ui;

};

#endif // TIMEINPUT_H
