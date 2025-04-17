#include <weapon/Bullet.hpp>

namespace ss {
    Bullet::Bullet(World* world, Actor* owner, const std::string& texturePath, float speed, float damage)
        : Actor{world, texturePath},
        mOwner{owner},
        mSpeed{speed},
        mDamage{damage} {
    }

    void Bullet::SetSpeed(float newSpeed) {
        mSpeed = newSpeed;
    }

    void Bullet::SetDamage(float newDamage) {
        mDamage = newDamage;
    }

    void Bullet::Tick(float dt) {
        Actor::Tick(dt);
        Move(dt);
    }

    void Bullet::Move(float dt) {
        SetActorRotation(0.f);
        AddActorLocationOffset(GetActorLeftDirection() * mSpeed * dt);
    }
}