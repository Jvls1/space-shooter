#pragma once

#include <framework/Actor.hpp>

namespace ss {
    class Bullet : public Actor {
    public:
        Bullet(World* world, Actor* owner, const std::string& texturePath, float speed = 600.f, float damage = 10.f);
        void SetSpeed(float newSpeed);
        void SetDamage(float newDamage);
        virtual void Tick(float dt) override;
        virtual void BeginPlay() override;
    private:
        void Move(float dt);
        Actor* mOwner;
        float mSpeed;
        float mDamage;
    };
}