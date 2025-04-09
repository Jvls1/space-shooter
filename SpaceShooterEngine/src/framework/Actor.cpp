#include "framework/Actor.hpp"

namespace ss {
    Actor::Actor(World* owningWorld)
        : mOwningWorld(owningWorld),
        mHasBeganPlay(false) {

    }
    Actor::~Actor() {

    }
    void Actor::BeginPlayInternal() {
        if (!mHasBeganPlay) {
            mHasBeganPlay = true;
            BeginPlay();
        }
    }
    void Actor::BeginPlay() {

    }
    void Actor::Tick(float dt) {

    }
}