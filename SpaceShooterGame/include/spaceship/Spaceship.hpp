#pragma once
#include <framework/Actor.hpp>

namespace ss {
    class Spaceship : public Actor {
    public:
        Spaceship(World* owningWord, const std::string& texturePath = "");
        virtual void Tick(float dt) override;
        sf::Vector2f GetVelocity() const { return mVelocity; }
        void SetVelocity(const sf::Vector2f& newVel);
        virtual void Shoot();
    private:
        sf::Vector2f mVelocity;
    };
}