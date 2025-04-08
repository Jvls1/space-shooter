add_executable(
    ${SPACE_SHOOTER_GAME_TARGET_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/Application.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Application.cpp
)

target_include_directories(${SPACE_SHOOTER_GAME_TARGET_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${SPACE_SHOOTER_GAME_TARGET_NAME} PUBLIC SFML::Graphics)

#function(CopyLibToTarget LIB_NAME TARGET_NAME) 
#    add_custom_command(
#        TARGET ${TARGET_NAME}
#       POST_BUILD
#        COMMAND
#        ${CMAKE_COMMAND} -E copy_if_different
#        $<TARGET_FILE:${LIB_NAME}>
#        $<TARGET_FILE_DIR:${TARGET_NAME}>
#    )
#endfunction()
#
#CopyLibToTarget(sfml-graphics ${SPACE_SHOOTER_GAME_TARGET_NAME})
#CopyLibToTarget(sfml-window ${SPACE_SHOOTER_GAME_TARGET_NAME})
#CopyLibToTarget(sfml-system ${SPACE_SHOOTER_GAME_TARGET_NAME})
#CopyLibToTarget(sfml-audio ${SPACE_SHOOTER_GAME_TARGET_NAME})