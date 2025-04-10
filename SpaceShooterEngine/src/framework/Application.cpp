#include "framework/Application.hpp"
#include "framework/Core.hpp" 
#include "framework/World.hpp"

namespace ss
{
    Application::Application(unsigned int windowWidth, unsigned int windowHeigth, const std::string& title, std::uint32_t style)
        : mWindow(sf::VideoMode({windowWidth, windowHeigth}), title, style),
        mTargetFrameRate{60.f},
        mTickClock{},
        currentWorld{nullptr} {
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
                TickInternal(targetDt);
                RenderInternal();
            }
        }
    }

    void Application::TickInternal(float dt) {
        Tick(dt);
        if (currentWorld) {
            currentWorld->TickInternal(dt);
        }
    }

    void Application::Tick(float dt) {

    }

    void Application::RenderInternal() {
        mWindow.clear();
        Render();
        mWindow.display();
    }

    void Application::Render() {
        if (currentWorld) {
            currentWorld->Render(mWindow);
        }
    }
}