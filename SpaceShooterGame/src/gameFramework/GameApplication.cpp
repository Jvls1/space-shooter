#include "gameFramework/GameApplication.hpp"
#include <framework/World.hpp>
#include <framework/Actor.hpp>

ss::Application* GetApplication() {
    return new ss::GameApplication{};
}
namespace ss {
    GameApplication::GameApplication() {
        weak<World> newWorld = LoadWorld<World>();
        newWorld.lock()->SpawnActor<Actor>();
    }
}