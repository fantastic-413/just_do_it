#include "calendarwidget.h"
#include <QPainter>
#include <QDebug>
#include <QCalendarWidget>
#include <QMenu>
#include <QToolButton>
#include <QTextCharFormat>
#include <QPalette>
#include <daytaskdialog.h>
#include "AllTask.h"
#include "global.h"
#include <string>

CalendarWidget::CalendarWidget(QWidget *parent) : QCalendarWidget(parent)
{
    qDebug() << "进入CalendarWidget";
    initUI();
    initSetting();
    setWindowTitle("月视图");

    //上面换个好看的图标
    setWindowIcon(QIcon(":/Image/arrow_left.png"));
//    connect(this, &QCalendarWidget::activated, [=](){
//        DayTaskDialog * dialog = new DayTaskDialog(this);

//        dialog->show();
//    });
}

void CalendarWidget::initUI()
{
    qDebug() << "进入initUI";
    QMenu *monthMenu = QCalendarWidget::findChild<QMenu*>();
    Q_ASSERT( nullptr != monthMenu);
    QToolButton *monthBtn = qobject_cast<QToolButton*>(monthMenu->parentWidget());
    Q_ASSERT( nullptr != monthBtn);
    //monthBtn->setMenu(nullptr);
    monthBtn->setStyleSheet("QToolButton::menu-indicator {image: none;}");
    monthBtn->resize(200, 100);

    QToolButton *prevBtn = QCalendarWidget::findChild<QToolButton*>(QLatin1String("qt_calendar_prevmonth"));
    Q_ASSERT( nullptr != prevBtn);
    QSize prevSize = prevBtn->iconSize();
    prevSize.rwidth() -= 2;
    prevSize.rheight() -= 2;
    prevBtn->setIconSize(prevSize);
    prevBtn->setIcon(QIcon(":/arrow_left.jpg"));
    prevBtn->resize(200, 100);

    QToolButton *nextBtn = QCalendarWidget::findChild<QToolButton*>(QLatin1String("qt_calendar_nextmonth"));
    Q_ASSERT( nullptr != nextBtn);
    QSize nextSize = nextBtn->iconSize();
    nextSize.rwidth() -= 2;
    nextSize.rheight() -= 2;
    nextBtn->setIconSize(nextSize);
    nextBtn->setIcon(QIcon(":/arrow_right.jpg"));
    //设置上边框底色
    //setStyleSheet("QCalendarWidget QWidget#qt_calendar_navigationbar {background-color: #696969;}");
    connect(this, &QCalendarWidget::activated,this,&CalendarWidget::activedCalendarWidget_slot);

}

void CalendarWidget::initSetting()
{
    qDebug() << "进入initSetting";
    setLocale(QLocale(QLocale::Chinese));
    setSelectionMode(QCalendarWidget::SingleSelection);
    setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
    setHorizontalHeaderFormat(QCalendarWidget::SingleLetterDayNames);

    QTextCharFormat format;
    format.setForeground(QColor(255, 255, 255));
    format.setBackground(QColor(0, 0, 255));
    setHeaderTextFormat(format);
    setWeekdayTextFormat(Qt::Saturday, format);
    setWeekdayTextFormat(Qt::Sunday,   format);
    setWeekdayTextFormat(Qt::Monday,   format);
    setWeekdayTextFormat(Qt::Tuesday,  format);
    setWeekdayTextFormat(Qt::Wednesday,format);
    setWeekdayTextFormat(Qt::Thursday, format);
    setWeekdayTextFormat(Qt::Friday,   format);
}

void CalendarWidget::paintCell(QPainter *painter, const QRect &rect, const QDate &date) const
{
    painter->save();
    painter->setRenderHint(QPainter::Antialiasing);
    /* 绘制背景 */
    QString time_Of_Task = date.toString("MM-dd");
    int n = allTask.getDayTaskMap(time_Of_Task.toStdString()).getTaskList().size();

    painter->setPen(Qt::NoPen);
    switch(n){
        case 0: painter->setBrush(QColor(240, 255, 255));
        break;
        case 1:
        case 2: painter->setBrush(QColor(0, 206, 250));
        break;
        case 3:
        case 4: painter->setBrush(QColor(34, 149, 34));
        break;
        case 5:
        case 6:
        case 7: painter->setBrush(QColor(255, 165, 0));
        break;
        default:painter->setBrush(QColor(139, 0 , 0));
        break;
    }
    painter->drawRoundedRect(rect.x()+1, rect.y()+1, rect.width()-2, rect.height()-2, 3, 3);

    /* 绘制前景 */
    QFont dateFont = painter->font();
    dateFont.setPixelSize(rect.height()-10);
    painter->setFont(dateFont);
    painter->setPen(QColor(0, 0, 0));//字体颜色
    QRect dateRect = QRect(rect.x()+3, rect.y()+3, rect.width()-6, rect.height()-6);
    painter->drawText(dateRect, Qt::AlignCenter, QString::number(date.day()));

    painter->restore();
}

CalendarWidget::~CalendarWidget()

{
}

void CalendarWidget::activedCalendarWidget_slot(const QDate &date)
{
    DayTaskDialog * dialog = new DayTaskDialog(this);
    QString time_Of_Task = date.toString("MM-dd");
    dialog->taskList = allTask.getDayTaskMap(time_Of_Task.toStdString()).getTaskList();
    dialog->init();
    dialog->show();
}

