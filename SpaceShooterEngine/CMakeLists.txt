add_library(
    ${SPACE_SHOOTER_ENGINE_TARGET_NAME} STATIC

    ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/Actor.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Actor.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/Application.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Application.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/AssetManager.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/AssetManager.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/Core.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Core.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/Delegate.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Delegate.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/MathUtility.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/MathUtility.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/Object.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Object.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/PhysicsSystem.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/PhysicsSystem.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/World.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/World.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/include/EntryPoint.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/EntryPoint.cpp
)

target_include_directories(${SPACE_SHOOTER_ENGINE_TARGET_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

include(FetchContent)
set(SFML_LIB_NAME SFML)

FetchContent_Declare(
    ${SFML_LIB_NAME}
    GIT_REPOSITORY https://github.com/SFML/SFML
    GIT_TAG 2.5.1
    GIT_SHALLOW FALSE
)

FetchContent_MakeAvailable(${SFML_LIB_NAME})

target_link_libraries(${SPACE_SHOOTER_ENGINE_TARGET_NAME} PUBLIC sfml-graphics)
target_link_libraries(${SPACE_SHOOTER_ENGINE_TARGET_NAME} PUBLIC sfml-window)
target_link_libraries(${SPACE_SHOOTER_ENGINE_TARGET_NAME} PUBLIC sfml-system)
target_link_libraries(${SPACE_SHOOTER_ENGINE_TARGET_NAME} PUBLIC sfml-audio)

set(BOX2D_LIB_NAME Box2D)
option(BOX2D_BUILD_UNIT_TESTS "Build the Box2D unit tests" OFF)
FetchContent_Declare(
    ${BOX2D_LIB_NAME}
    GIT_REPOSITORY https://github.com/erincatto/box2d
    GIT_TAG v2.4.1
    GIT_SHALLOW FALSE
)

FetchContent_MakeAvailable(${BOX2D_LIB_NAME})

target_link_libraries(${SPACE_SHOOTER_ENGINE_TARGET_NAME} PUBLIC box2d)

function(CopyLibToTarget LIB_NAME TARGET_NAME) 
   add_custom_command(
        TARGET ${TARGET_NAME}
        POST_BUILD
        COMMAND
        ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:${LIB_NAME}>
        $<TARGET_FILE_DIR:${TARGET_NAME}>
   )
endfunction()

CopyLibToTarget(sfml-graphics ${SPACE_SHOOTER_ENGINE_TARGET_NAME})
CopyLibToTarget(sfml-window ${SPACE_SHOOTER_ENGINE_TARGET_NAME})
CopyLibToTarget(sfml-system ${SPACE_SHOOTER_ENGINE_TARGET_NAME})
CopyLibToTarget(sfml-audio ${SPACE_SHOOTER_ENGINE_TARGET_NAME})
CopyLibToTarget(box2d ${SPACE_SHOOTER_ENGINE_TARGET_NAME})