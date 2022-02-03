cmake_minimum_required(VERSION 3.10)

project(virtualkeyboard)

# Use the standard c++17 for this project
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (CMAKE_COMPILER_IS_GNUCXX)
    add_compile_options(-W -Wall -Wextra -fPIC)
endif()

if (MSVC)
    add_compile_options(/W4 /utf-8)
endif()


find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Gui Widgets Quick REQUIRED)

add_subdirectory(3rd)
add_subdirectory(src)
add_subdirectory(examples)
