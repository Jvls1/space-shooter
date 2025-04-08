#include "framework/World.hpp"

namespace ss {
    World::World(Application* owningApp) 
        : mOwningApp(owningApp),
        mBeganPlay(false) {

    }

    void World::BeginPlayInternal() {
        if (!mBeganPlay) {
            mBeganPlay = true;
            BeginPlay();
        }
    }

    void World::TickInternal(float dt) {
        Tick(dt);
    }

    World::~World() {

    }

    void World::BeginPlay() {

    }

    void World::Tick(float dt) {

    }
}