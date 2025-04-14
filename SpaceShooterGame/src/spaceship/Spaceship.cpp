#include "spaceship/Spaceship.hpp"

namespace ss {
    Spaceship::Spaceship(World* owningWord, const std::string& texturePath) 
        : Actor{owningWord, texturePath},
        mVelocity{} {

    }

    void Spaceship::Tick(float dt) {
        Actor::Tick(dt);
        AddActorLocationOffset(GetVelocity() * dt);
    }

    void Spaceship::SetVelocity(const sf::Vector2f& newVel) {
        mVelocity = newVel; 
    }
}