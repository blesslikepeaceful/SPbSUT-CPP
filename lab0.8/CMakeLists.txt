cmake_minimum_required(VERSION 3.14)

# Укажите имя проекта
project(MyQtProject LANGUAGES CXX)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Найдите пакет Qt (проверьте свою версию Qt, например, 5.15 или 6.x)
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Sql)

# Укажите исполняемый файл
set(SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

# Добавьте исполняемый файл проекта
add_executable(${PROJECT_NAME} ${SOURCES})

# Свяжите проект с модулями Qt
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Sql)

# Укажите стандарт C++
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

