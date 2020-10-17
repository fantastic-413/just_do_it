#ifndef MODIFYDIALOG_H
#define MODIFYDIALOG_H

#include <QDialog>

namespace Ui {
class ModifyDialog;
}

class ModifyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ModifyDialog(QString str,QWidget *parent = nullptr);
    ~ModifyDialog();
    QString getModifyText();
    QString s;

private:
    Ui::ModifyDialog *ui;
};

#endif // MODIFYDIALOG_H
