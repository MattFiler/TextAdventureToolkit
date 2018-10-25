#[[ A specially curated CMAKE file designed to handle
    importing of all the necessary libraries to run ASGE games.
    It's important to note that due to the way CMake operates,
    static libraries requires linking to all dependencies in
    the build chain. Using shared, only requires the use of a
    single DLL.

    Shared Build    => Executable
                    => GameEngine.dll
                    => GCC runtime dlls

    Static Build    => Executable   static app
                    => OpenGL       static library, provided by OS
                    => GLEW         static library
                    => GLFW         static library
                    => Freetype     static library
                    => PhysFS       static library
                    => PhysFS++     static library
                    => GameEngine   static library

    NB: You should not need to edit this file, unless adding new libraries to your game ]]


## set the library directories ##
if(WIN32)
    set(ASGE_BIN_DIRECTORY ${CMAKE_SOURCE_DIR}/Libs/ASGE/bin)
    set(ASGE_LIB_DIRECTORY ${CMAKE_SOURCE_DIR}/Libs/ASGE/lib/win)
elseif(APPLE)
    set(ASGE_BIN_DIRECTORY ${CMAKE_SOURCE_DIR}/Libs/ASGE/lib/osx)
    set(ASGE_LIB_DIRECTORY ${CMAKE_SOURCE_DIR}/Libs/ASGE/lib/osx)
else()
    set(ASGE_BIN_DIRECTORY ${CMAKE_SOURCE_DIR}/Libs/ASGE/lib/linux)
    set(ASGE_LIB_DIRECTORY ${CMAKE_SOURCE_DIR}/Libs/ASGE/lib/linux)
endif()


## postfix to ensure we link to the correct libs ##
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(POSTFIX "d")
else()
    set(POSTFIX "")
endif()


if(BUILD_SHARED_LIBS)

    ## shared libraries only requires a single link to game engine
    find_library(libGameEngine REQUIRED
            NAMES libGameEngine${POSTFIX}.dll libGameEngine${POSTFIX}.so ASGE${POSTFIX}
            PATHS ${ASGE_BIN_DIRECTORY} NO_DEFAULT_PATH)
    message("libGameEngine: " ${libGameEngine} )

    set_property (
            TARGET ASGE PROPERTY
            IMPORTED_LOCATION
            ${libGameEngine})

    set(libGameEngine ${libGameEngine} PARENT_SCOPE)

else()

    ## static builds are hideous
    find_library(libFreetype REQUIRED NAMES freetype${POSTFIX}              PATHS ${ASGE_LIB_DIRECTORY} NO_DEFAULT_PATH)
    find_library(libPhysFS   REQUIRED NAMES physfs${POSTFIX}                PATHS ${ASGE_LIB_DIRECTORY} NO_DEFAULT_PATH)
    find_library(libPhysFS++ REQUIRED NAMES physfscpp${POSTFIX}             PATHS ${ASGE_LIB_DIRECTORY} NO_DEFAULT_PATH)
    find_library(libGLFW     REQUIRED NAMES glfw3${POSTFIX}                 PATHS ${ASGE_LIB_DIRECTORY} NO_DEFAULT_PATH)
    find_library(libGLEW     REQUIRED NAMES GLEW${POSTFIX} glew32${POSTFIX} PATHS ${ASGE_LIB_DIRECTORY} NO_DEFAULT_PATH)

    set(OpenGL_GL_PREFERENCE "GLVND")
    find_package(OpenGL REQUIRED)
    message("libOpenGL:     " ${OPENGL_LIBRARIES})

    if(PLATFORM STREQUAL "linux")
        find_package(X11 REQUIRED)
        find_package(ZLIB REQUIRED)
        find_package(BZip2 REQUIRED)

        message("libX11:        " ${X11_LIBRARIES})
        message("libZLIB:       " ${ZLIB_LIBRARIES})
        message("libBZip2:      " ${BZIP2_LIBRARIES})
    endif()


    find_library(libGameEngine REQUIRED
            NAMES libGameEngine${POSTFIX}.a libGameEngine${POSTFIX}.lib ASGE
            PATHS ${ASGE_LIB_DIRECTORY} NO_DEFAULT_PATH)

    message("libGLEW:       " ${libGLEW})
    message("libGLFW:       " ${libGLFW})
    message("libFreetype:   " ${libFreetype})
    message("libPhysFS:     " ${libPhysFS})
    message("libPhysFS++:   " ${libPhysFS++})
    message("libGameEngine: " ${libGameEngine})

    set_property (
            TARGET ASGE PROPERTY
            IMPORTED_LOCATION
            ${libGameEngine}
    )

    ## all platforms need these libraries
    list(APPEND LINK_LIBS ${libGLEW} ${libGLFW} ${libFreetype} ${libPhysFS++} ${libPhysFS} ${OPENGL_LIBRARIES})

    if(PLATFORM STREQUAL "linux")
        list(APPEND LINK_LIBS
                ${X11_LIBRARIES}
                ${X11_Xi_LIB}
                ${X11_Xrandr_LIB}
                ${X11_Xxf86vm_LIB}
                ${X11_Xinerama_LIB}
                ${X11_Xcursor_LIB}
                ${ZLIB_LIBRARIES}
                ${BZIP2_LIBRARIES}
                harfbuzz
                pthread   #threading
                dl )      #dynamic loader
    endif()

    set_property(
            TARGET ASGE PROPERTY
            INTERFACE_LINK_LIBRARIES
            ${LINK_LIBS}
    )

endif()