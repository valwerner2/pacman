cmake_minimum_required(VERSION 3.26)
project(pacman C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)
set(SDL2_PATH "C:/Users/valwe/OneDrive - theokoch.schule/ProgrammData/SLD2-2.28.5-mingw/x86_64-w64-mingwSPRITE_SIZE")
set(SDL2_IMAGE_PATH "C:/Users/valwe/OneDrive - theokoch.schule/ProgrammData/SDL2_image-2.8.2-mingw/x86_64-w64-mingwSPRITE_SIZE")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(pacman main.c
        eventHandler.c
        eventHandler.h
        controller.h
        controller.c
        entity.c
        entity.h
        pacman.h
        pacman.c
        drawScreen.h
        drawScreen.c
        collisionDetection.c
        collisionDetection.h
        ghost.h
        ghost.c
        common.h
        bigCoin.h
        bigCoin.c
        smallCoin.c
        smallCoin.h
        pathFinding.c
        pathFinding.h
        wall.c
        wall.h
        maze.c
        maze.h
        common.c)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES})

add_compile_options(${PROJECT_NAME} -Wall)