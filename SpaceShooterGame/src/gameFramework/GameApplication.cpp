#include "gameFramework/GameApplication.hpp"
#include <framework/World.hpp>
#include <framework/Actor.hpp>

ss::Application* GetApplication() {
    return new ss::GameApplication{};
}
namespace ss {
    GameApplication::GameApplication() 
        : Application{600, 980, "Space Shooter", sf::Style::Titlebar | sf::Style::Close} {
        weak<World> newWorld = LoadWorld<World>();
        newWorld.lock()->SpawnActor<Actor>();
    }
}