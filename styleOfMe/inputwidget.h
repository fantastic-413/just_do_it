#ifndef INPUTWIDGET_H
#define INPUTWIDGET_H

#include <QWidget>

namespace Ui {
class InputWidget;
}

class InputWidget : public QWidget
{
    Q_OBJECT

public:
    explicit InputWidget(QWidget *parent = nullptr);
    ~InputWidget();

private:
    Ui::InputWidget *ui;
};

#endif // INPUTWIDGET_H
