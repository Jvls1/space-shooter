#pragma once
#include <SFML/Graphics.hpp>

namespace ss {
    class Application {
    public:
        Application();
        void Run();
    private:
        void TickInternal(float dt);
        void RenderInternal();

        virtual void Render();
        virtual void Tick(float dt);

        sf::RenderWindow mWindow;
        float mTargetFrameRate;
        sf::Clock mTickClock;
    };

}