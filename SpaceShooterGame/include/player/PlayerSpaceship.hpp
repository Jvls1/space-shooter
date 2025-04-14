#pragma once
#include "spaceship/Spaceship.hpp"

namespace ss {
    class PlayerSpaceship : public Spaceship {
    public:
        PlayerSpaceship(World* owningWorld, const std::string& path = "SpaceShooterRedux/PNG/playerShip1_blue.png");

        virtual void Tick(float dt) override;
        void SetSpeed(float newSpeed) { mSpeed = newSpeed; };
        float GetSpeed() const { return mSpeed; }
    private:
        void HandleInput();
        void ConsumeInput(float dt);
        sf::Vector2f mMoveInput;
        float mSpeed;
    };
}