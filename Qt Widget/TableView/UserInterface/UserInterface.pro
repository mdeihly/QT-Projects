QT += gui \
    widgets

TEMPLATE = lib
CONFIG += staticlib

CONFIG += c++17

SOURCES += \
    Delegates/DescriptionDelegate.cpp \
    Delegates/SpinBoxDelegate.cpp \
    Delegates/datetimedelegate.cpp \
    Delegates/titledelegate.cpp \
    ModelView/modelviewwidget.cpp \
    userinterface.cpp

HEADERS += \
    Delegates/DescriptionDelegate.h \
    Delegates/SpinBoxDelegate.h \
    Delegates/datetimedelegate.h \
    Delegates/titledelegate.h \
    ModelView/modelviewwidget.h \
    userinterface.h

# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target



#LIBS += PATH_TO_LIB_DIR/libLIBNAME.a
