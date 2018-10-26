cmake_minimum_required(VERSION 3.10)
project(TextAdventureGame)

if(UNIX AND APPLE)
    set(PLATFORM "osx" )
elseif(UNIX)
    set(PLATFORM "linux")
else()
    set(PLATFORM "win")
endif()

## hide console unless debug build ##
if (NOT CMAKE_BUILD_TYPE STREQUAL "Debug" AND WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows")
endif()

set(CMAKE_DEBUG_POSTFIX d)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Builds")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Builds")

## set to true to use dlls instead of static libs ##
set(BUILD_SHARED_LIBS OFF)

## itch.io and gamedata settings ##
set(GAMEDATA_FOLDER "Resources")
set(ITCHIO_USER     "")

## files used to build this game
add_executable(
        ${PROJECT_NAME}
        main.cpp
        Source/ActionList.h
        Source/Animations.cpp
        Source/Animations.h
        Source/Game.cpp
        Source/Game.h
        Source/GameConstants.h
        Source/GameDataType.h
        Source/GameLogic.cpp
        Source/GameLogic.h
        Source/GameProgress.cpp
        Source/GameProgress.h
        Source/GameScreenText.cpp
        Source/GameScreenText.h
        Source/GameStates.h
        Source/Rect.cpp
        Source/Rect.h
        Source/SpriteComponent.cpp
        Source/SpriteComponent.h)

## library includes
target_include_directories(
        ${PROJECT_NAME}
        PRIVATE        "${CMAKE_SOURCE_DIR}/Libs/ASGE/include"
        PRIVATE        "${CMAKE_SOURCE_DIR}/Libs/irrKlang/include")

## compile language settings
target_compile_features(
        ${PROJECT_NAME}
        PRIVATE
        cxx_std_17)

## build the game libs folder
add_library(ASGE UNKNOWN IMPORTED)
add_subdirectory(Libs)
target_link_libraries(${PROJECT_NAME} ASGE)

## copy the dlls post build
if(BUILD_SHARED_LIBS)
    # copy the game engine dll to bin
    add_custom_command(
            TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${libGameEngine}"
            $<TARGET_FILE_DIR:${PROJECT_NAME}>)

    if(WIN32 AND NOT MSVC)
        # copy the mingw runtime files to bin
        add_custom_command(
                TARGET ${PROJECT_NAME} PRE_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_SOURCE_DIR}/Libs/mingw64/bin $<TARGET_FILE_DIR:${PROJECT_NAME}>)
    endif()
endif()


## enable static linking against gcc build
if (WIN32 AND NOT BUILD_SHARED_LIBS AND NOT MSVC)
    target_link_libraries(${PROJECT_NAME} -static)
endif()

## utility scripts
include(CMake/itch.io.cmake)

## build types
set(CMAKE_CONFIGURATION_TYPES Debug;Release)
