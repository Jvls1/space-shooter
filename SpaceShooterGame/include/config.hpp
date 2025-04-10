#pragma once
#include <string>

std::string GetResourceDir() {
    #ifdef NDEBUG
        return "assets/";
    #else
        return "/home/joao/Documents/devprojects/cpp-course/space-shooter/SpaceShooterGame/assets/";
    #endif
}
