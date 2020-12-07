cmake_minimum_required(VERSION 3.5)

project(Lab2 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_PREFIX_PATH C:/Qt/5.15.1/msvc2019_64/lib/cmake/Qt5Multimedia)
# \lib\cmake\Qt5Multimedia




# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets LinguistTools REQUIRED)
find_package(Qt5Multimedia CONFIG)

set(TS_FILES Lab2_en_150.ts)



if(ANDROID)
  add_library(Lab2 SHARED
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    ${TS_FILES}
  )
else()
  add_executable(Lab2
    main.cpp
    mainwindow.cpp
    settings.cpp
    alarmclock.cpp
    syshidden.cpp
    add_a_new_timer_dialog.cpp
    add_a_new_alarm_dialog.cpp
    timer_end_window.cpp
    alarm_end_window.cpp
    mainwindow.h
    alarmclock.h
    settings.h
    syshidden.h
    add_a_new_timer_dialog.h
    add_a_new_alarm_dialog.h
    timer_end_window.h
    alarm_end_window.h
    mainwindow.ui
    alarmclock.ui
    settings.ui
    add_a_new_timer_dialog.ui
    add_a_new_alarm_dialog.ui
    timer_end_window.ui
    alarm_end_window.ui
    res.qrc
    ${TS_FILES}
  )
endif()

target_link_libraries(Lab2 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(Lab2 PRIVATE Qt${QT_VERSION_MAJOR}::Multimedia)
qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
