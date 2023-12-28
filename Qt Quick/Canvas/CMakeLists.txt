cmake_minimum_required(VERSION 3.16)

project(Canvas VERSION 0.1 LANGUAGES CXX)

# List all QML files explicitly
set(QML_FILES
    qml/main.qml
    qml/CircularProgressBar.qml
    qml/CustomSlider.qml
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

qt_add_executable(appCanvas
    main.cpp
)

qt_add_qml_module(appCanvas
    URI Canvas
    VERSION 1.0
    QML_FILES ${QML_FILES}
)

set_target_properties(appCanvas PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appCanvas
    PRIVATE Qt6::Quick)

install(TARGETS appCanvas
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
