cmake_minimum_required(VERSION 4.0)

project(
    SpaceShooter
    LANGUAGES C CXX
    VERSION 0.0.1
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
set(SFML_LIB_NAME SFML)

FetchContent_Declare(
    ${SFML_LIB_NAME}
    GIT_REPOSITORY https://github.com/SFML/SFML
    GIT_TAG 3.0.0
    GIT_SHALLOW FALSE
)

FetchContent_MakeAvailable(${SFML_LIB_NAME})

# creates a variable.
set(SPACE_SHOOTER_GAME_TARGET_NAME SpaceShooterGame)

add_subdirectory(SpaceShooter)