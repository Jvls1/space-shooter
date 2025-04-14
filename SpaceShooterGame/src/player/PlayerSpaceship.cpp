#include <SFML/Graphics.hpp>
#include "player/PlayerSpaceship.hpp"

namespace ss {
    PlayerSpaceship::PlayerSpaceship(World* mOwningWorld, const std::string& path)
        : Spaceship{mOwningWorld, path},
        mMoveInput{},
        mSpeed{200.f} {

    }

    void PlayerSpaceship::Tick(float dt) {
        Spaceship::Tick(dt);
        HandleInput();
        ConsumeInput(dt);
    }

    void PlayerSpaceship::HandleInput() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            mMoveInput.y = -1.f;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            mMoveInput.y = 1.f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            mMoveInput.x = -1.f;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            mMoveInput.x = 1.f;
        }
    }

    void PlayerSpaceship::ConsumeInput(float dt) {
        SetVelocity(mMoveInput * mSpeed);
        mMoveInput.x = mMoveInput.y = 0.f;
    }
}