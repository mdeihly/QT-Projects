QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    main.cpp \
    application.cpp

HEADERS += \
    application.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../UserInterface/release/ -lUserInterface
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../UserInterface/debug/ -lUserInterface
else:unix: LIBS += -L$$OUT_PWD/../UserInterface/ -lUserInterface

INCLUDEPATH += $$PWD/../UserInterface
DEPENDPATH += $$PWD/../UserInterface

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../UserInterface/release/libUserInterface.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../UserInterface/debug/libUserInterface.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../UserInterface/release/UserInterface.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../UserInterface/debug/UserInterface.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../UserInterface/libUserInterface.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../TableModel/release/ -lTableModel
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../TableModel/debug/ -lTableModel
else:unix: LIBS += -L$$OUT_PWD/../TableModel/ -lTableModel

INCLUDEPATH += $$PWD/../TableModel
DEPENDPATH += $$PWD/../TableModel

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../TableModel/release/libTableModel.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../TableModel/debug/libTableModel.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../TableModel/release/TableModel.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../TableModel/debug/TableModel.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../TableModel/libTableModel.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../DataModel/release/ -lDataModel
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../DataModel/debug/ -lDataModel
else:unix: LIBS += -L$$OUT_PWD/../DataModel/ -lDataModel

INCLUDEPATH += $$PWD/../DataModel
DEPENDPATH += $$PWD/../DataModel

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../DataModel/release/libDataModel.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../DataModel/debug/libDataModel.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../DataModel/release/DataModel.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../DataModel/debug/DataModel.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../DataModel/libDataModel.a
