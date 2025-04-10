#include "framework/Actor.hpp"
#include "framework/AssetManager.hpp"
#include "framework/MathUtility.hpp"

namespace ss {
    Actor::Actor(World* owningWorld, const std::string& texturePath)
        : mOwningWorld(owningWorld),
        mHasBeganPlay(false),
        mSprite{*mTexture},
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
        mTexture = AssetManager::Get().LoadTexture(texturePath);
        if (!mTexture) return;
        mSprite.setTexture(*mTexture);

        int textureWidth = mTexture->getSize().x;
        int textureHeight = mTexture->getSize().y;
        mSprite.setTextureRect(sf::IntRect{ sf::Vector2i{}, sf::Vector2i{textureWidth, textureHeight} });
        CenterPivot();
    }

    void Actor::Render(sf::RenderWindow& window) {
        if (IsPendingDestroy())
            return;
        window.draw(mSprite);
    }

    void Actor::SetActorLocation(const sf::Vector2f& newLocation) {
        mSprite.setPosition(newLocation);
    }

    void Actor::SetActorRotation(float newRotation) {
        mSprite.setRotation(sf::radians(newRotation));
    }

    void Actor::AddActorLocationOffset(const sf::Vector2f& offsetAmt) {
        SetActorLocation(GetActorLocation() + offsetAmt);
    }
    
    void Actor::AddActorRotationOffset(float offsetAmt) {
        SetActorRotation(GetActorRotation() + offsetAmt);
    }

    sf::Vector2f Actor::GetActorLocation() const {
        return mSprite.getPosition();
    }

    float Actor::GetActorRotation() const {
        return mSprite.getRotation().asRadians();
    }

    sf::Vector2f Actor::GetActorForwardDirection() const {
        return RotationToVector(GetActorRotation());
    }

    sf::Vector2f Actor::GetActorRightDirection() const {
        return RotationToVector(GetActorRotation() + 90.f);
    }

    void Actor::CenterPivot() {
        sf::FloatRect bound = mSprite.getGlobalBounds();
        mSprite.setOrigin({bound.size.x / 2.f, bound.size.y / 2.f});
    }
}