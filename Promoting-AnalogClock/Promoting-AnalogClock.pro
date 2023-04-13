QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

MOC_DIR     = build/moc
OBJECTS_DIR = build/obj
UI_DIR      = build/ui

CONFIG += c++17

SOURCES += \
    analogclock.cpp \
    main.cpp \
    maindialog.cpp

HEADERS += \
    analogclock.h \
    maindialog.h

FORMS += \
    maindialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
