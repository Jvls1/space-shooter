#include "EntryPoint.hpp"
#include "framework/Application.hpp"

int main() {
    ss::Application* app = GetApplication();
    app->Run();
    delete app;
}