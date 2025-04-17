#include "gameFramework/GameApplication.hpp"
#include <framework/World.hpp>
#include <framework/Actor.hpp>
#include <framework/AssetManager.hpp>
#include "player/PlayerSpaceship.hpp"
#include <config.hpp>

ss::Application* GetApplication() {
    return new ss::GameApplication{};
}
namespace ss {
    GameApplication::GameApplication() 
        : Application{600, 980, "Space Shooter", sf::Style::Titlebar | sf::Style::Close} {
        AssetManager::Get().SetAssetRootDirectory(GetResourceDir());
        weak<World> newWorld = LoadWorld<World>();
        testPlayerSpaceship = newWorld.lock()->SpawnActor<PlayerSpaceship>();
        testPlayerSpaceship.lock()->SetActorLocation(sf::Vector2f(300.f, 490.f));
        //testPlayerSpaceship.lock()->SetActorRotation(-90.f);
    }

    void GameApplication::Tick(float dt) {
        
    }
}