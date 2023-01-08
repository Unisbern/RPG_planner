QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    achievementform.cpp \
    helpwidget.cpp \
    itemeditor.cpp \
    main.cpp \
    mainwidget.cpp \
    skillsform.cpp \
    taskitem.cpp \
    tasksform.cpp \
    userwidget.cpp

HEADERS += \
    achievementform.h \
    helpwidget.h \
    itemeditor.h \
    mainwidget.h \
    skillsform.h \
    taskitem.h \
    tasksform.h \
    userwidget.h

FORMS += \
    achievementform.ui \
    helpwidget.ui \
    itemeditor.ui \
    mainwidget.ui \
    skillsform.ui \
    taskitem.ui \
    tasksform.ui \
    userwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
