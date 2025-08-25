cmake_minimum_required(VERSION 3.16)

project(ContainerApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwidget.h
        mainwidget.cpp
        mainclient.h
        mainclient.cpp

        resources.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ContainerApp
        MANUAL_FINALIZATION WIN32
        ${PROJECT_SOURCES}
        postwidget.h postwidget.cpp

        container.h
        box.h box.cpp

        cylinder.h cylinder.cpp

        simplecontainerfactory.h simplecontainerfactory.cpp
        containermemento.h
        cylindermemento.h cylindermemento.cpp
        boxmemento.h boxmemento.cpp
        inventoryhistory.h inventoryhistory.cpp
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET ContainerApp APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(ContainerApp SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(ContainerApp
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(ContainerApp PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.ContainerApp)
endif()
set_target_properties(ContainerApp PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
# install(TARGETS ContainerApp
#     BUNDLE DESTINATION .
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
# )

# Windows Deployment (MinGW)
if(WIN32 AND MINGW)
    # Get Qt's MinGW bin path (where windeployqt.exe is)
    get_target_property(QT_QMAKE_EXECUTABLE Qt${QT_VERSION_MAJOR}::qmake IMPORTED_LOCATION)
    get_filename_component(QT_BIN_DIR "${QT_QMAKE_EXECUTABLE}" DIRECTORY)
    set(WINDEPLOYQT_EXECUTABLE "${QT_BIN_DIR}/windeployqt.exe")

    # Run windeployqt after build
    add_custom_command(TARGET ContainerApp POST_BUILD
        COMMAND ${WINDEPLOYQT_EXECUTABLE}
                $<TARGET_FILE:ContainerApp>
                --verbose 1
                --no-compiler-runtime
                --no-opengl-sw
        COMMENT "Deploying Qt libraries with MinGW..."
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        VERBATIM
    )
endif()

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ContainerApp)
endif()
