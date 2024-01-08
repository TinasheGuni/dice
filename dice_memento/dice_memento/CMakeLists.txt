cmake_minimum_required(VERSION 3.14)

project(dice_memento LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Gui Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui Widgets)

add_executable(dice_memento
  main.cpp
  dicegui.h dicegui.cpp
  randomnumbergenerator.h randomnumbergenerator.cpp
  randomnumbergeneratormemento.h randomnumbergeneratormemento.cpp
  randomnumbercaretaker.h randomnumbercaretaker.cpp
  resources.qrc
)
target_link_libraries(dice_memento PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

include(GNUInstallDirs)
install(TARGETS dice_memento
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
