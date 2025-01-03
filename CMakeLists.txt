cmake_minimum_required(VERSION 3.16)

project(SearchingApplication VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        searching_application.cpp
        searching_application.h
        searching_application.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(SearchingApplication
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        filereader.h filereader.cpp
        timecounter.h timecounter.cpp
        searching_algorithm.h searching_algorithm.cpp
        search_context.h search_context.cpp
        linear_search.h linear_search.cpp
        sort_needed_search.h sort_needed_search.cpp
        binary_search.h binary_search.cpp
        ternary_search.h ternary_search.cpp
        jump_search.h jump_search.cpp
        exponential_search.h exponential_search.cpp
        interpolation_search.h interpolation_search.cpp
        fibonacci_search.h fibonacci_search.cpp
        array_generator.h array_generator.cpp
        ascending_array.h ascending_array.cpp
        descending_array.h descending_array.cpp
        random_array.h random_array.cpp
        fieldreader.h fieldreader.cpp
        visualization.h visualization.cpp
        linear_visualization.h linear_visualization.cpp
        binary_visualization.h binary_visualization.cpp
        ternary_visualization.h ternary_visualization.cpp
        jump_visualization.h jump_visualization.cpp
        exponential_visualization.h exponential_visualization.cpp
        interpolation_visualization.h interpolation_visualization.cpp
        fibonacci_visualization.h fibonacci_visualization.cpp
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET SearchingApplication APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(SearchingApplication SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(SearchingApplication
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(SearchingApplication PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.SearchingApplication)
endif()
set_target_properties(SearchingApplication PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS SearchingApplication
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(SearchingApplication)
endif()
