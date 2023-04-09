QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_divideexampletest.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../ApplicationLib/release/ -lApplicationLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../ApplicationLib/debug/ -lApplicationLib
else:unix: LIBS += -L$$OUT_PWD/../ApplicationLib/ -lApplicationLib

INCLUDEPATH += $$PWD/../ApplicationLib
DEPENDPATH += $$PWD/../ApplicationLib
