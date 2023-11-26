#pragma once
#include <iostream>

typedef unsigned int SDL_bool;
class Window;
class Application
{
    Window* m_window;

    SDL_bool m_running = false;

    static Application* s_ptr_instance;
public:
    Application();
    virtual ~Application() {}

    void run();

    inline Window& getWindow() {  }

    inline static Application& get_instance() { return *s_ptr_instance; }
private:

};

Application* createApplication();