cmake_minimum_required(VERSION 3.27.7)

project(
    SpaceShooter
    LANGUAGES C CXX
    VERSION 0.0.1
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# creates a variable.
set(SPACE_SHOOTER_ENGINE_TARGET_NAME SpaceShooterEngine)
set(SPACE_SHOOTER_GAME_TARGET_NAME SpaceShooterGame)

add_subdirectory(SpaceShooterEngine)
add_subdirectory(SpaceShooterGame)