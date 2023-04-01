QT -= gui

TEMPLATE = lib
CONFIG += staticlib

CONFIG += c++17

SOURCES += \
    tablemodel.cpp

HEADERS += \
    tablemodel.h

# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target

