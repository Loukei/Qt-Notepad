#-------------------------------------------------
#
# Project created by QtCreator 2018-09-22T09:34:55
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = Notepad
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    findinput.cpp \
        main.cpp \
        mainwindow.cpp \
    recentfiles.cpp \
    searchwidget.cpp \
    tabwidget.cpp \
    texteditor.cpp

HEADERS += \
    findinput.h \
        mainwindow.h \
    recentfiles.h \
    searchwidget.h \
    tabwidget.h \
    texteditor.h

FORMS += \
        mainwindow.ui \
    searchwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    notepad.qrc

# add windows desktop icon
RC_ICONS = Images/notepad-icon.ico
