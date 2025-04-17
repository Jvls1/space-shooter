#include "framework/Actor.hpp"
#include "framework/AssetManager.hpp"
#include "framework/MathUtility.hpp"
#include "framework/World.hpp"

namespace ss {
    Actor::Actor(World* owningWorld, const std::string& texturePath)
        : mOwningWorld(owningWorld),
        mHasBeganPlay(false),
        mTexture{},
        mSprite{} {
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
        mSprite.setRotation(newRotation);
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
        return mSprite.getRotation();
    }

    sf::Vector2f Actor::GetActorForwardDirection() const {
        return RotationToVector(GetActorRotation());
    }

    sf::Vector2f Actor::GetActorRightDirection() const {
        return RotationToVector(GetActorRotation() + 90.f);
    }

    sf::Vector2f Actor::GetActorLeftDirection() const {
        return RotationToVector(GetActorRotation() - 90.f);
    }

    sf::FloatRect Actor::GetActorGlobalBounds() const {
        return mSprite.getGlobalBounds();
    }

    sf::Vector2u Actor::GetWindowSize() const {
        return mOwningWorld->GetWindowSize();
    }

    void Actor::CenterPivot() {
        sf::FloatRect bound = mSprite.getGlobalBounds();
        mSprite.setOrigin({bound.width / 2.f, bound.height / 2.f});
    }

    bool Actor::IsActorOutOfWindowBounds() const {
        float windowWidth = GetWorld()->GetWindowSize().x;
        float windowHeight = GetWorld()->GetWindowSize().y;

        float width = GetActorGlobalBounds().width;
        float height = GetActorGlobalBounds().height;

        sf::Vector2f actorPosition = GetActorLocation();

        if (actorPosition.x < -width) {
            return true;
        }

        if (actorPosition.x > windowWidth + width) {
            return true;
        }

        if (actorPosition.y < -height) {
            return true;
        }

        if (actorPosition.y > windowHeight + height) {
            return true;
        }

        return false;
    }
}