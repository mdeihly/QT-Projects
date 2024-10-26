cmake_minimum_required(VERSION 3.16)

project(Shopping-App VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

qt_add_executable(appShopping-App
    main.cpp
)

qt_add_qml_module(appShopping-App
    URI Shopping-App
    VERSION 1.0
    RESOURCES
    assets/arrow-l.svg assets/arrow-r.svg assets/cart.svg assets/pin.svg assets/share.svg assets/shop.svg
    qml/theme/qmldir
    assets/more.svg assets/image.svg assets/star.svg assets/truck.svg
    assets/products/im1.jpg assets/products/im2.jpg assets/products/im3.jpg assets/products/im4.jpg assets/products/im5.jpg assets/products/im6.jpg assets/products/im7.jpg assets/products/im8.jpg assets/products/im9.jpg assets/products/im10.jpg assets/products/im11.jpg assets/products/im12.jpg assets/products/im13.jpg assets/products/im14.jpg assets/products/im15.jpg
    assets/logo.png
    QML_FILES
    qml/main.qml
    qml/Components/IconButton.qml qml/Components/Header.qml
    qml/theme/AppTheme.qml
    qml/models/ProductsModel.qml
    qml/views/ProductsView.qml qml/views/Dashboard.qml
    qml/delegates/ProductDelegate.qml

)

set_target_properties(appShopping-App PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appShopping-App
    PRIVATE Qt6::Quick)

install(TARGETS appShopping-App
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
