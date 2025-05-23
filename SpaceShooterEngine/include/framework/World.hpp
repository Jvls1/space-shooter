#pragma once
#include <SFML/Graphics.hpp>
#include "framework/Core.hpp"

namespace ss {
    class Actor;
    class Application;
    class World {
    public:
        World(Application* owningApp);

        void BeginPlayInternal();
        void TickInternal(float dt);
        void Render(sf::RenderWindow& window);

        virtual ~World();
        template<typename ActorType, typename... Args>
        weak<ActorType> SpawnActor(Args... args);
        
        sf::Vector2u GetWindowSize() const;
        void CleanCycle();
    private:
        void BeginPlay();
        void Tick(float dt);
        Application* mOwningApp;
        bool mBeganPlay;

        List<shared<Actor>> mActors;
        List<shared<Actor>> mPendingActors;
    };
    template<typename ActorType, typename... Args>
    weak<ActorType> World::SpawnActor(Args... args) {
        shared<ActorType> newActor{new ActorType(this, args...)};
        mPendingActors.push_back(newActor);
        return newActor;
    }
}