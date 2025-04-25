#pragma once
#include <framework/Actor.hpp>
#include "gameplay/HealthComponent.hpp"

namespace ss {
    class Spaceship : public Actor {
    public:
        Spaceship(World* owningWord, const std::string& texturePath = "");
        virtual void Tick(float dt) override;
        sf::Vector2f GetVelocity() const { return mVelocity; }
        void SetVelocity(const sf::Vector2f& newVel);
        virtual void Shoot();
        virtual void BeginPlay() override;
    private:
        void OnHealthChanged(float amt, float health, float maxHealth);
        sf::Vector2f mVelocity;
        HealthComponent mHealthComp;
    };
}