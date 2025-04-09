#pragma once
#include "framework/Object.hpp"

namespace ss {
    class World;
    class Actor : public Object {
    public: 
        Actor(World* owningWorld);
        virtual ~Actor();
        void BeginPlayInternal();
        virtual void BeginPlay();
        virtual void Tick(float dt);
    private:
        World* mOwningWorld;
        bool mHasBeganPlay;
    };
}