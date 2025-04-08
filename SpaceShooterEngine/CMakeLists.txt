add_library(
    ${SPACE_SHOOTER_ENGINE_TARGET_NAME} STATIC

    ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/Application.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Application.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/Core.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Core.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/World.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/World.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/include/EntryPoint.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/EntryPoint.cpp
)

target_include_directories(${SPACE_SHOOTER_ENGINE_TARGET_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${SPACE_SHOOTER_ENGINE_TARGET_NAME} PUBLIC SFML::Graphics)

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
#CopyLibToTarget(sfml-graphics ${SPACE_SHOOTER_ENGINE_TARGET_NAME})
#CopyLibToTarget(sfml-window ${SPACE_SHOOTER_ENGINE_TARGET_NAME})
#CopyLibToTarget(sfml-system ${SPACE_SHOOTER_ENGINE_TARGET_NAME})
#CopyLibToTarget(sfml-audio ${SPACE_SHOOTER_ENGINE_TARGET_NAME})