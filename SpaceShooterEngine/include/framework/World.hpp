#pragma once
#include "framework/Core.hpp"

namespace ss {
    class Actor;
    class Application;
    class World {
    public:
        World(Application* owningApp);

        void BeginPlayInternal();
        void TickInternal(float dt);

        virtual ~World();
        template<typename ActorType>
        weak<ActorType> SpawnActor();
    private:
        void BeginPlay();
        void Tick(float dt);
        Application* mOwningApp;
        bool mBeganPlay;

        List<shared<Actor>> mActors;
        List<shared<Actor>> mPendingActors;
    };
    template<typename ActorType>
    weak<ActorType> World::SpawnActor() {
        shared<ActorType> newActor{new ActorType(this)};
        mPendingActors.push_back(newActor);
        return newActor;
    }
}