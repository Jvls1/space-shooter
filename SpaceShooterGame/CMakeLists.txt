add_executable(
    ${SPACE_SHOOTER_GAME_TARGET_NAME}

    ${CMAKE_CURRENT_SOURCE_DIR}/include/gameFramework/GameApplication.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gameFramework/GameApplication.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/include/gameplay/HealthComponent.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gameplay/HealthComponent.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/include/player/PlayerSpaceship.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/player/PlayerSpaceship.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/include/spaceship/Spaceship.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/spaceship/Spaceship.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/include/weapon/Bullet.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/weapon/Bullet.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/include/weapon/BulletShooter.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/weapon/BulletShooter.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/include/weapon/Shooter.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/weapon/Shooter.cpp
)

target_include_directories(${SPACE_SHOOTER_GAME_TARGET_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${SPACE_SHOOTER_GAME_TARGET_NAME} PUBLIC ${SPACE_SHOOTER_ENGINE_TARGET_NAME})

function(CopyLibDirToTarget LIB_NAME TARGET_NAME) 
    add_custom_command(
        TARGET ${TARGET_NAME}
        POST_BUILD
        COMMAND
        ${CMAKE_COMMAND} -E copy_directory
        $<TARGET_FILE_DIR:${LIB_NAME}>
        $<TARGET_FILE_DIR:${TARGET_NAME}>
    )
endfunction()

CopyLibDirToTarget(${SPACE_SHOOTER_ENGINE_TARGET_NAME} ${SPACE_SHOOTER_GAME_TARGET_NAME})

set(RESOURCE_FOLDER_NAME "assets")
set(RESOURCE_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${RESOURCE_FOLDER_NAME}")

add_custom_command(
    TARGET ${SPACE_SHOOTER_GAME_TARGET_NAME}
    POST_BUILD
    COMMAND
    ${CMAKE_COMMAND} -E copy_directory
    ${RESOURCE_SRC_DIR}
    $<TARGET_FILE_DIR:${SPACE_SHOOTER_GAME_TARGET_NAME}>/${RESOURCE_FOLDER_NAME}
)

configure_file(
    "config.hpp.in"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/config.hpp" ESCAPE_QUOTES
)