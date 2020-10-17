#ifndef LEVELDIALOG_H
#define LEVELDIALOG_H

#include <QDialog>
#include"Task.h"

namespace Ui {
class LevelDialog;
}

class LevelDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LevelDialog(QWidget *parent = nullptr);
    ~LevelDialog();
    TaskLevel getLevel();


private:
    Ui::LevelDialog *ui;
};

#endif // LEVELDIALOG_H
