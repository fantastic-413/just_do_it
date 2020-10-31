QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AllTask.cpp \
    DayTask.cpp \
    Task.cpp \
    calendarwidget.cpp \
    daytaskdialog.cpp \
    global.cpp \
    inputdialog.cpp \
    leveldialog.cpp \
    main.cpp \
    mainwindow.cpp \
    modifydialog.cpp \
    showdialog.cpp \
    timeinput.cpp \
    timemodifydialog.cpp

HEADERS += \
    AllTask.h \
    DayTask.h \
    Task.h \
    calendarwidget.h \
    daytaskdialog.h \
    global.h \
    inputdialog.h \
    leveldialog.h \
    mainwindow.h \
    modifydialog.h \
    showdialog.h \
    timeinput.h \
    timemodifydialog.h

FORMS += \
    daytaskdialog.ui \
    inputdialog.ui \
    leveldialog.ui \
    mainwindow.ui \
    modifydialog.ui \
    showdialog.ui \
    timeinput.ui \
    timemodifydialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
	res.qrc
