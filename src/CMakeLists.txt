cmake_minimum_required(VERSION 3.16)

project(Blackjack-Symulator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "C:/Qt/6.9.0/mingw_64/lib/cmake")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        ui/mainwindow.cpp
        ui/mainwindow.h
        ui/mainwindow.ui
        game/Card.cpp
        game/Card.h
        ui/gamewindow.h
        ui/gamewindow.cpp
        ui/gamewindow.ui
        ../resources/resources.qrc
        ui/balancewindow.h
        ui/balancewindow.cpp
        ui/balancewindow.ui
        game/Deck.cpp
        game/Deck.h
        game/Hand.cpp
        game/Hand.h
        game/Player.cpp
        game/Player.h
        game/Dealer.cpp
        game/Dealer.h
        ui/leaderboardwindow.cpp
        ui/leaderboardwindow.h
        ui/leaderboardwindow.ui
        score/scoremanager.cpp
        score/scoremanager.h
        game/gamelogic.cpp
        game/gamelogic.h
        ui/styledmessagebox.cpp
        ui/styledmessagebox.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Blackjack-Symulator
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
            ui/gamewindow.h ui/gamewindow.cpp ui/gamewindow.ui
            ../resources/resources.qrc
            ui/balancewindow.h ui/balancewindow.cpp ui/balancewindow.ui
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Blackjack-Symulator APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Blackjack-Symulator SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Blackjack-Symulator
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Blackjack-Symulator PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Blackjack-Symulator)
endif()
set_target_properties(Blackjack-Symulator PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Blackjack-Symulator
        BUNDLE DESTINATION ..
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Blackjack-Symulator)
endif()
