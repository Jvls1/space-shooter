#include "weapon/Shooter.hpp"

namespace ss {
    Shooter::Shooter(Actor* owner)
        : mOwner{owner} {

    }

    void Shooter::Shoot() {
        if (CanShoot() && !IsOnCooldown()) {
            ShootImpl();
        }
    }
}