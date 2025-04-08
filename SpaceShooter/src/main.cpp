#include <memory>
#include <SFML/Graphics.hpp>
#include "framework/Application.hpp"

int main() {
    std::unique_ptr<ss::Application> app = std::make_unique<ss::Application>() ;
    app->Run();
    return 0;
}