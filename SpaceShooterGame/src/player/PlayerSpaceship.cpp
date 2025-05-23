#include <SFML/Graphics.hpp>
#include <framework/MathUtility.hpp>
#include "player/PlayerSpaceship.hpp"
#include "weapon/BulletShooter.hpp"

namespace ss {
    PlayerSpaceship::PlayerSpaceship(World* mOwningWorld, const std::string& path)
        : Spaceship{mOwningWorld, path},
        mMoveInput{},
        mSpeed{200.f},
        mShooter{new BulletShooter{this, 0.1f} } {
        SetTeamID(1);
    }

    void PlayerSpaceship::Tick(float dt) {
        Spaceship::Tick(dt);
        HandleInput();
        ConsumeInput(dt);
    }

    void PlayerSpaceship::Shoot() {
        if (mShooter) {
            mShooter->Shoot();
        }
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
        ClampInputOnEdge();
        NormalizeInput();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            Shoot();
        }
    }

    void PlayerSpaceship::NormalizeInput() {
        Normalize<float>(mMoveInput);
    }

    void PlayerSpaceship::ClampInputOnEdge() {
        sf::Vector2f actorLocation = GetActorLocation();
        if (actorLocation.x < 0 && mMoveInput.x == -1) {
            mMoveInput.x = 0.f;
        }
        if (actorLocation.x > GetWindowSize().x && mMoveInput.x == 1.f) {
            mMoveInput.x = 0.f;
        }
        if (actorLocation.y < 0 && mMoveInput.y == -1) {
            mMoveInput.y = 0.f;
        }
        if (actorLocation.y > GetWindowSize().y && mMoveInput.y == 1.f) {
            mMoveInput.y = 0.f;
        }
    }

    void PlayerSpaceship::ConsumeInput(float dt) {
        SetVelocity(mMoveInput * mSpeed);
        mMoveInput.x = mMoveInput.y = 0.f;
    }
}