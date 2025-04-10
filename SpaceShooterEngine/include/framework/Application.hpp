#pragma once
#include <SFML/Graphics.hpp>
#include "framework/Core.hpp"

namespace ss {
    class World;
    class Application {
    public:
        Application(unsigned int windowWidth, unsigned int windowHeigth, const std::string& title, std::uint32_t style);
        void Run();

        template<typename WorldType>
        weak<WorldType> LoadWorld();
    private:
        void TickInternal(float dt);
        void RenderInternal();

        virtual void Render();
        virtual void Tick(float dt);

        sf::RenderWindow mWindow;
        float mTargetFrameRate;
        sf::Clock mTickClock;

        shared<World> currentWorld;
    };

    template<typename WorldType>
    weak<WorldType> Application::LoadWorld() {
        shared<WorldType> newWorld{new WorldType{this}};
        currentWorld = newWorld;
        return newWorld;
    }
}