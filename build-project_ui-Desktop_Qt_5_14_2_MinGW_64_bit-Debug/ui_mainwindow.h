/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action111;
    QAction *actionEnglish;
    QAction *actionAllTask;
    QAction *actionFinishedTask;
    QAction *actionz;
    QAction *actiony;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QWidget *tab_3;
    QWidget *tab_4;
    QWidget *tab_5;
    QWidget *tab_6;
    QWidget *tab_7;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout;
    QPushButton *addBtn;
    QPushButton *upBtn;
    QPushButton *downBtn;
    QPushButton *impBtn;
    QPushButton *modBtn;
    QPushButton *delBtn;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *monthLabel;
    QMenuBar *menubar;
    QMenu *menu_2;
    QMenu *menu_3;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1053, 653);
        action111 = new QAction(MainWindow);
        action111->setObjectName(QString::fromUtf8("action111"));
        actionEnglish = new QAction(MainWindow);
        actionEnglish->setObjectName(QString::fromUtf8("actionEnglish"));
        actionAllTask = new QAction(MainWindow);
        actionAllTask->setObjectName(QString::fromUtf8("actionAllTask"));
        actionFinishedTask = new QAction(MainWindow);
        actionFinishedTask->setObjectName(QString::fromUtf8("actionFinishedTask"));
        actionz = new QAction(MainWindow);
        actionz->setObjectName(QString::fromUtf8("actionz"));
        actiony = new QAction(MainWindow);
        actiony->setObjectName(QString::fromUtf8("actiony"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(90, 50, 831, 571));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tab_3->setEnabled(true);
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        tabWidget->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        tabWidget->addTab(tab_7, QString());
        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(910, 180, 115, 301));
        verticalLayout = new QVBoxLayout(widget_3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        addBtn = new QPushButton(widget_3);
        addBtn->setObjectName(QString::fromUtf8("addBtn"));

        verticalLayout->addWidget(addBtn);

        upBtn = new QPushButton(widget_3);
        upBtn->setObjectName(QString::fromUtf8("upBtn"));

        verticalLayout->addWidget(upBtn);

        downBtn = new QPushButton(widget_3);
        downBtn->setObjectName(QString::fromUtf8("downBtn"));

        verticalLayout->addWidget(downBtn);

        impBtn = new QPushButton(widget_3);
        impBtn->setObjectName(QString::fromUtf8("impBtn"));

        verticalLayout->addWidget(impBtn);

        modBtn = new QPushButton(widget_3);
        modBtn->setObjectName(QString::fromUtf8("modBtn"));

        verticalLayout->addWidget(modBtn);

        delBtn = new QPushButton(widget_3);
        delBtn->setObjectName(QString::fromUtf8("delBtn"));

        verticalLayout->addWidget(delBtn);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 30, 51, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(160, 30, 51, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(230, 30, 51, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(300, 30, 51, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(370, 30, 51, 16));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(440, 30, 51, 16));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(500, 30, 51, 16));
        monthLabel = new QLabel(centralwidget);
        monthLabel->setObjectName(QString::fromUtf8("monthLabel"));
        monthLabel->setGeometry(QRect(850, 40, 72, 15));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1053, 21));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu_2->addAction(actionAllTask);
        menu_2->addAction(actionFinishedTask);
        menu_3->addAction(actiony);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\346\227\245\347\250\213\345\256\211\346\216\222", nullptr));
        action111->setText(QCoreApplication::translate("MainWindow", "\347\256\200\344\275\223\344\270\255\346\226\207", nullptr));
        actionEnglish->setText(QCoreApplication::translate("MainWindow", "English", nullptr));
        actionAllTask->setText(QCoreApplication::translate("MainWindow", "\346\200\273\344\273\273\345\212\241\346\240\217", nullptr));
        actionFinishedTask->setText(QCoreApplication::translate("MainWindow", "\345\267\262\345\256\214\346\210\220\344\273\273\345\212\241", nullptr));
        actionz->setText(QCoreApplication::translate("MainWindow", "\345\221\250\350\247\206\345\233\276", nullptr));
        actiony->setText(QCoreApplication::translate("MainWindow", "\346\234\210\350\247\206\345\233\276", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", " \345\221\250\344\270\200", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\345\221\250\344\272\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", " \345\221\250\344\270\211", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "  \345\221\250\345\233\233", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainWindow", " \345\221\250\344\272\224", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("MainWindow", " \345\221\250\345\205\255", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QCoreApplication::translate("MainWindow", "\345\221\250\346\227\245", nullptr));
        addBtn->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240", nullptr));
        upBtn->setText(QCoreApplication::translate("MainWindow", "\345\210\207\346\215\242\342\206\221", nullptr));
        downBtn->setText(QCoreApplication::translate("MainWindow", "\345\210\207\346\215\242\342\206\223", nullptr));
        impBtn->setText(QCoreApplication::translate("MainWindow", "\344\273\212\345\244\251", nullptr));
        modBtn->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271", nullptr));
        delBtn->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        monthLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\350\247\206\345\233\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
