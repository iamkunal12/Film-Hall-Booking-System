QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminlogin.cpp \
    main.cpp \
    login.cpp \
    moviemanager.cpp \
    seats1.cpp \
    seats2.cpp \
    seats3.cpp \
    seats4.cpp \
    secondpageadmin.cpp \
    secondpageuser.cpp \

HEADERS += \
    adminlogin.h \
    login.h \
    moviemanager.h \
    seats1.h \
    seats2.h \
    seats3.h \
    seats4.h \
    secondpageadmin.h \
    secondpageuser.h \

FORMS += \
    adminlogin.ui \
    login.ui \
    seats1.ui \
    seats2.ui \
    seats3.ui \
    seats4.ui \
    secondpageadmin.ui \
    secondpageuser.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    background.qrc
