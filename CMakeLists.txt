cmake_minimum_required(VERSION 3.5)

project(RPG_planner VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/install" CACHE PATH "..." FORCE)
endif()

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        achievementform.h
        helpwidget.h
        itemeditor.h
        mainwidget.h
        skillsform.h
        taskitem.h
        tasksform.h
        achievementform.cpp
        helpwidget.cpp
        itemeditor.cpp
        main.cpp
        mainwidget.cpp
        skillsform.cpp
        taskitem.cpp
        tasksform.cpp
        achievementform.ui
        helpwidget.ui
        itemeditor.ui
        mainwidget.ui
        skillsform.ui
        taskitem.ui
        tasksform.ui
)
set(app_icon_resource_windows "${CMAKE_CURRENT_SOURCE_DIR}/resources/app.rc")

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(RPG_planner
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES} ${app_icon_resource_windows}
    )
else()
    add_executable(RPG_planner ${PROJECT_SOURCES} ${app_icon_resource_windows})
endif()

target_link_libraries(RPG_planner PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(RPG_planner PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(RPG_planner)
endif()


set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

install(TARGETS RPG_planner DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
install(TARGETS RPG_planner DESTINATION .)


