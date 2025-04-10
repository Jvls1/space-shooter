#include "framework/Actor.hpp"

namespace ss {
    Actor::Actor(World* owningWorld, const std::string& texturePath)
        : mOwningWorld(owningWorld),
        mHasBeganPlay(false),
        mSprite{mTexture},
        mTexture{} {
        SetTexture(texturePath);
    }
    Actor::~Actor() {

    }

    void Actor::BeginPlayInternal() {
        if (!mHasBeganPlay) {
            mHasBeganPlay = true;
            BeginPlay();
        }
    }

    void Actor::TickInternal(float dt) {
        if (!IsPendingDestroy()) {
            Tick(dt);
        }
    }

    void Actor::BeginPlay() {

    }

    void Actor::Tick(float dt) {

    }

    void Actor::SetTexture(const std::string& texturePath) {
        mTexture.loadFromFile(texturePath);
        mSprite.setTexture(mTexture);

        int textureWidth = mTexture.getSize().x;
        int textureHeight = mTexture.getSize().y;
        mSprite.setTextureRect(sf::IntRect{ sf::Vector2i{}, sf::Vector2i{textureWidth, textureHeight} });
    }

    void Actor::Render(sf::RenderWindow& window) {
        if (IsPendingDestroy())
            return;
        window.draw(mSprite);
    }
}