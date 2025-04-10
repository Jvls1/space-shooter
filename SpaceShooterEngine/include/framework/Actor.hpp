#pragma once
#include <SFML/Graphics.hpp>

#include "framework/Object.hpp"

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
    private:
        World* mOwningWorld;
        bool mHasBeganPlay;

        sf::Sprite mSprite;
        sf::Texture mTexture;
    };
}