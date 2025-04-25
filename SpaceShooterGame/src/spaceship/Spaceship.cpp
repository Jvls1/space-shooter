#include "spaceship/Spaceship.hpp"

namespace ss {
    Spaceship::Spaceship(World* owningWord, const std::string& texturePath) 
        : Actor{owningWord, texturePath},
        mVelocity{},
        mHealthComp{100.f, 100.f} {

    }

    void Spaceship::Tick(float dt) {
        Actor::Tick(dt);
        AddActorLocationOffset(GetVelocity() * dt);
    }

    void Spaceship::SetVelocity(const sf::Vector2f& newVel) {
        mVelocity = newVel; 
    }

    void Spaceship::Shoot() {

    }

    void Spaceship::BeginPlay() {
        Actor::BeginPlay();
        SetEnablePhysics(true);
        mHealthComp.onHealthChanged.BindAction(GetWeakRef(), &Spaceship::OnHealthChanged);
    }

    void Spaceship::OnHealthChanged(float amt, float health, float maxHealth) {
        LOG("heath changed");
    }
}