#include "framework/Application.hpp"
#include "framework/AssetManager.hpp"
#include "framework/Core.hpp" 
#include "framework/World.hpp"

namespace ss
{
    Application::Application(unsigned int windowWidth, unsigned int windowHeigth, const std::string& title, std::uint32_t style)
        : mWindow(sf::VideoMode({windowWidth, windowHeigth}), title, style),
        mTargetFrameRate{60.f},
        mTickClock{},
        currentWorld{nullptr},
        mCleanCycleClock{},
        mCleanCycleInterval{2.f} {

    }

    void Application::Run() {
        mTickClock.restart();
        float accumulatedTime = 0.f;
        float targetDt = 1.f / mTargetFrameRate;
        while (mWindow.isOpen()) {
            sf::Event event;
            while (mWindow.pollEvent(event)) {
                if (event.type == sf::Event::EventType::Closed) {
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

    sf::Vector2u Application::GetWindowSize() const {
        return mWindow.getSize();
    }

    void Application::TickInternal(float dt) {
        Tick(dt);
        if (currentWorld) {
            currentWorld->TickInternal(dt);
        }
        
        if (mCleanCycleClock.getElapsedTime().asSeconds() >= mCleanCycleInterval) {
            mCleanCycleClock.restart();
            AssetManager::Get().CleanCycle();
            if (currentWorld) {
                currentWorld->CleanCycle();
            }
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