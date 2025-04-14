#pragma once
#include <framework/Application.hpp>
#include <framework/Core.hpp>

namespace ss {
   class PlayerSpaceship;
   class GameApplication : public Application {
   public:
      GameApplication();
      virtual void Tick(float dt) override;
   private:
      float counter;
      weak<PlayerSpaceship> testPlayerSpaceship;
   };
}