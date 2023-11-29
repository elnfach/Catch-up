#include "component_base.h"

void Engine::ComponentBase::start()
{
    for (size_t i = 0; i < component_list.size(); i++)
    {
        component_list[i]->start();
    }
}

void Engine::ComponentBase::update()
{
    for (size_t i = 0; i < component_list.size(); i++)
    {
        component_list[i]->update();
    }
}