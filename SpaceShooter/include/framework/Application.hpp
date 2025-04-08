#pragma once
#include <SFML/Graphics.hpp>

namespace ss {
    class Application {
    public:
        Application();
        void Run();
    private:
        void Tick(float dt);
        void Render();

        sf::RenderWindow mWindow;
        float mTargetFrameRate;
        sf::Clock mTickClock;
    };

}