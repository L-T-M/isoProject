QT += core gui dtkwidget

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = isoCustomizer
TEMPLATE = app

SOURCES += \
        main.cpp \
    mainwindow.cpp \
    chooseiso.cpp \
    choosearchitecture.cpp \
    programsettings.cpp \
    previouspreparation.cpp \
    mediuminstall.cpp \
    laterclear.cpp \
    choosekernel.cpp \
    prepareoutput.cpp

RESOURCES +=         resources.qrc

HEADERS += \
    mainwindow.h \
    chooseiso.h \
    choosearchitecture.h \
    programsettings.h \
    previouspreparation.h \
    mediuminstall.h \
    laterclear.h \
    choosekernel.h \
    prepareoutput.h
