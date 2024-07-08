QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cartuchos.cpp \
    decisiondialog.cpp \
    disparodialog.cpp \
    gameoverwindow.cpp \
    initdialog.cpp \
    inventario.cpp \
    item.cpp \
    main.cpp \
    mainwindow.cpp \
    persona.cpp \
    utils.cpp

HEADERS += \
    cartuchos.h \
    decisiondialog.h \
    disparodialog.h \
    gameoverwindow.h \
    initdialog.h \
    inventario.h \
    item.h \
    mainwindow.h \
    persona.h \
    utils.h

FORMS += \
    decisiondialog.ui \
    disparodialog.ui \
    gameoverwindow.ui \
    initdialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imagenes.qrc
