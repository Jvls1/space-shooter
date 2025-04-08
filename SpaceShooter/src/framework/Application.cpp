#include "framework/Application.hpp"
#include <iostream>

namespace ss
{
    Application::Application()
        : mWindow(sf::VideoMode({1024, 1440}), "Window"),
        mTargetFrameRate{60.f},
        mTickClock{} {
    }

    void Application::Run() {
        mTickClock.restart();
        float accumulatedTime = 0.f;
        float targetDt = 1.f / mTargetFrameRate;
        while (mWindow.isOpen()) {
            while (const std::optional event = mWindow.pollEvent()) {
                if (event->is<sf::Event::Closed>() || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
                    mWindow.close();
                }
            }

            accumulatedTime += mTickClock.restart().asSeconds();
            while (accumulatedTime > targetDt) {
                accumulatedTime -= targetDt;
                Tick(targetDt);
            }
        }
    }

    void Application::Tick(float dt) {
        std::cout << "tick framerate: " << 1.f / dt << "\n";
    }

    void Application::Render() {

    }
}