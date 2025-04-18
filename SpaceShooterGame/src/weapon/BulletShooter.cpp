#include <framework/Core.hpp>
#include <framework/World.hpp>
#include "weapon/BulletShooter.hpp"
#include "weapon/Bullet.hpp"

namespace ss {
    BulletShooter::BulletShooter(Actor* owner, float cooldownTime)
        : Shooter{owner},
        mCooldownClock{},
        mCooldownTime{cooldownTime} {
    }

    bool BulletShooter::IsOnCooldown() const {
        if (mCooldownClock.getElapsedTime().asSeconds() > mCooldownTime) {
            return false;
        }

        return true;
    }

    void BulletShooter::ShootImpl() {
        mCooldownClock.restart();
        weak<Bullet> newBullet = GetOwner()->GetWorld()->SpawnActor<Bullet>(GetOwner(), "SpaceShooterRedux/PNG/Lasers/laserBlue01.png");
        newBullet.lock()->SetActorLocation(GetOwner()->GetActorLocation());
        newBullet.lock()->SetActorRotation(GetOwner()->GetActorRotation());
    }
}