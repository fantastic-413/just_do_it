#ifndef CALENDARWIDGET_H
#define CALENDARWIDGET_H

#include <QWidget>
#include <QCalendarWidget>

class CalendarWidget : public QCalendarWidget
{
    Q_OBJECT

public:
    explicit CalendarWidget(QWidget *parent = nullptr);
    ~CalendarWidget();
    //void paintEvent(QPaintEvent *);

protected:
    void paintCell(QPainter *painter, const QRect &rect, const QDate &date) const;

private:
    QPalette mRangePalette = QPalette(QColor(0,255,0));											//设置区间颜色
    QDate mStartDate = QDate(2020, 10,1);												//设置区间的起始时间
    QDate mEndDate = QDate(2030, 10, 30);
    void initUI();//设置区间的结束时间
    void initSetting();
    //获取当天任务数量

private slots:
    void activedCalendarWidget_slot(const QDate &date);


};
#endif

