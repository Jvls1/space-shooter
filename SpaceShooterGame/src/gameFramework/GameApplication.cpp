#include "gameFramework/GameApplication.hpp"
#include <framework/World.hpp>

ss::Application* GetApplication() {
    return new ss::GameApplication{};
}
namespace ss {
    GameApplication::GameApplication() {
        LoadWorld<World>();
    }
}