QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cartuchos.cpp \
    cerveza.cpp \
    cigarros.cpp \
    decisiondealerdialog.cpp \
    decisiondialog.cpp \
    disparodialog.cpp \
    esposas.cpp \
    gameoverwindow.cpp \
    initdialog.cpp \
    inventario.cpp \
    item.cpp \
    itemdialog.cpp \
    lupa.cpp \
    main.cpp \
    mainwindow.cpp \
    persona.cpp \
    sierra.cpp \
    utils.cpp \
    winround.cpp

HEADERS += \
    cartuchos.h \
    cerveza.h \
    cigarros.h \
    decisiondealerdialog.h \
    decisiondialog.h \
    disparodialog.h \
    esposas.h \
    gameoverwindow.h \
    initdialog.h \
    inventario.h \
    item.h \
    itemdialog.h \
    lupa.h \
    mainwindow.h \
    persona.h \
    sierra.h \
    utils.h \
    winround.h

FORMS += \
    decisiondealerdialog.ui \
    decisiondialog.ui \
    disparodialog.ui \
    gameoverwindow.ui \
    initdialog.ui \
    itemdialog.ui \
    mainwindow.ui \
    winround.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imagenes.qrc
