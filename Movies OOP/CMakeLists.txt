cmake_minimum_required(VERSION 3.22)
project(Lab10OOP)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_OSX_ARCHITECTURES x86_64)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Lab10OOP main.cpp filme.cpp filme.h FilmeRepo.cpp FilmeRepo.h FilmeServ.cpp FilmeServ.h Console.cpp Console.h teste.cpp teste.h Undo.h Observer.h MyTableModel.h)
target_link_libraries(Lab10OOP
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

