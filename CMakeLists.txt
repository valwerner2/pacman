cmake_minimum_required(VERSION 3.26)
project(pacman C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)
set(SDL2_PATH "C:/Users/valwe/OneDrive - theokoch.schule/ProgrammData/SLD2-2.28.5-mingw/x86_64-w64-mingw32")
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(pacman main.c
        eventHandler.c
        eventHandler.h
        controller.h
        controller.c)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})
