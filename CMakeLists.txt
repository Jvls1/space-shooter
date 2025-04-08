cmake_minimum_required(VERSION 4.0)

project(
    SpaceShooter
    LANGUAGES C CXX
    VERSION 0.0.1
)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# creates a variable.
set(SPACE_SHOOTER_GAME_TARGET_NAME SpaceShooterGame)

add_subdirectory(SpaceShooter)