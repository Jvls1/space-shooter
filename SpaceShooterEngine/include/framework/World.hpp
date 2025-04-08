#pragma once

namespace ss {
    class Application;
    class World {
    public:
        World(Application* owningApp);

        void BeginPlayInternal();
        void TickInternal(float dt);

        virtual ~World();
    private:
        void BeginPlay();
        void Tick(float dt);
        Application* mOwningApp;
        bool mBeganPlay;
    };
}