#include "framework/World.hpp"
#include "framework/Actor.hpp"

namespace ss {
    World::World(Application* owningApp) 
        : mOwningApp(owningApp),
        mBeganPlay(false),
        mActors{},
        mPendingActors{} {

    }

    void World::BeginPlayInternal() {
        if (!mBeganPlay) {
            mBeganPlay = true;
            BeginPlay();
        }
    }

    void World::TickInternal(float dt) {
        for (shared<Actor> actor : mPendingActors) {
            mActors.push_back(actor);
            actor->BeginPlayInternal();
        }
        mPendingActors.clear();
        for (auto i = mActors.begin(); i != mActors.end();) {
            if (i->get()->IsPendingDestroy()) {
                i = mActors.erase(i);
            } else {
                i->get()->TickInternal(dt);
                ++i;
            }
        }
        Tick(dt);
    }

    void World::Render(sf::RenderWindow& window) {
        for (auto actor : mActors) {
            actor->Render(window);
        }
    }

    World::~World() {

    }

    void World::BeginPlay() {

    }

    void World::Tick(float dt) {

    }
}