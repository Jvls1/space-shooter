#pragma once
#include <SFML/Graphics.hpp>
#include "framework/Core.hpp"
#include "framework/Object.hpp"

class b2Body;

namespace ss {
    class World;
    class Actor : public Object {
    public: 
        Actor(World* owningWorld, const std::string& texturePath = "");
        virtual ~Actor();
        void BeginPlayInternal();
        void TickInternal(float dt);
        virtual void BeginPlay();
        virtual void Tick(float dt);
        void SetTexture(const std::string& texturePath);
        void Render(sf::RenderWindow& window);

        void SetActorLocation(const sf::Vector2f& newLocation);
        void SetActorRotation(float newRotation);
        void AddActorLocationOffset(const sf::Vector2f& offsetAmt);
        void AddActorRotationOffset(float offsetAmt);
        sf::Vector2f GetActorLocation() const;
        float GetActorRotation() const;
        sf::Vector2f GetActorForwardDirection() const;
        sf::Vector2f GetActorRightDirection() const;
        sf::Vector2f GetActorLeftDirection() const;
        sf::FloatRect GetActorGlobalBounds() const;

        sf::Vector2u GetWindowSize() const;
        World* GetWorld() const { return mOwningWorld; }

        bool IsActorOutOfWindowBounds() const;
        void SetEnablePhysics(bool enable);
        virtual void OnActorBeginOverlap(Actor* other);
        virtual void OnActorEndOverlap(Actor* other);
        virtual void Destroy() override;
        static uint8 GetNeutralTeamID() { return neutralTeamID; }
        void SetTeamID(uint8 teamID) { mTeadID = teamID; }
        uint8 GetTeamID() const { return mTeadID; }
        bool IsOtherHostile(Actor* other);
        virtual void ApplyDamage(float amt);
    private:
        void CenterPivot();
        void InitializePhysics();
        void DisablePhysics();
        void UpdatePhysicsBodyTransform();

        World* mOwningWorld;
        bool mHasBeganPlay;

        sf::Sprite mSprite;
        shared<sf::Texture> mTexture;

        b2Body* mPhysicBody;
        bool mPhysicsEnabled;

        uint8 mTeadID;

        const static uint8 neutralTeamID = 255;
    };
}