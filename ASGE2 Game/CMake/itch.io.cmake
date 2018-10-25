#[[ A specially curated CMAKE file designed to handle
    data creation, compression and itch.io support. It will
    create a game.dat archive of all resources, which can be
    read by ASGE. The itch.io command relies on butler and will
    correctly tag and push builds to the service, assuming the
    project exists.

    1. For data packaging to work the variable GAMEDATA_FOLDER
       must be set

    2. For itch.io support, both GAMEDATA_FOLDER and ITCHIO_USER
       must bet set

    NB: It's probably best not to change these scripts
    unless you have a good reason to do so ]]

if(GAMEDATA_FOLDER)

    ## copies the game data folder to the bin folder, maybe unix should use links??##
    add_custom_command(
            OUTPUT "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${GAMEDATA_FOLDER}"
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_SOURCE_DIR}/${GAMEDATA_FOLDER}" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${GAMEDATA_FOLDER}"
            COMMENT "copying data resources to build destintation")

    if(WIN32)
        ## creates a compressed version of the game data ready for publishing ##
        add_custom_target(
                ${PROJECT_NAME}+GameData ALL

                COMMAND "${CMAKE_SOURCE_DIR}/Tools/7zip/${PLATFORM}/7za" a
                        "$<TARGET_FILE_DIR:${PROJECT_NAME}>/game.dat" "${CMAKE_SOURCE_DIR}/${GAMEDATA_FOLDER}/*"
                WORKING_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
                COMMENT "creating data archive")
    else()
        ## creates a compressed version of the game data for nix ready for publishing ##
        add_custom_target(
                ${PROJECT_NAME}+GameData ALL
                DEPENDS "$<TARGET_FILE_DIR:${PROJECT_NAME}>/${GAMEDATA_FOLDER}"
                COMMAND ${CMAKE_COMMAND} -E tar cfv "$<TARGET_FILE_DIR:${PROJECT_NAME}>/game.dat" --format=7zip -- *
                # COMMAND ${CMAKE_COMMAND} -E remove_directory "$<TARGET_FILE_DIR:${PROJECT_NAME}>/${GAMEDATA_FOLDER}"
                WORKING_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${GAMEDATA_FOLDER}"
                COMMENT "creating data archive")
    endif()

    if(ITCHIO_USER)
        ## uses butler to push the built game to itch.io ##
        add_custom_target(ItchIO
                COMMAND "${CMAKE_SOURCE_DIR}/Tools/itch.io/${PLATFORM}/butler" update &&
                "${CMAKE_SOURCE_DIR}/Tools/itch.io/${PLATFORM}/butler" --ignore=data push ..
                ${ITCHIO_USER}/${PROJECT_NAME}:${PLATFORM}-${CMAKE_BUILD_TYPE}
                WORKING_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
                COMMENT "uploading game to itch.io. be patient")

        add_dependencies(ItchIO ${PROJECT_NAME}+GameData)
    else()
        message("No itch.io user has been specified: disabling itch build targets")
    endif()

else()
    message("No game data folder has been specified: disabling data and itch.io targets")
endif()


