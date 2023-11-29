#ifndef CATCH_UP_ENGINE_SRC_INCLUDE_COMPONENT_BASE_H
#define CATCH_UP_ENGINE_SRC_INCLUDE_COMPONENT_BASE_H

#include "component.h"

namespace Engine
{
    class ComponentBase
    {
        static std::vector<Component*> component_list;

    protected:

        ComponentBase() { }
        ~ComponentBase() { }
    public:
        static ComponentBase& Instance()
        {
            static ComponentBase instance;
            return instance;
        }

        static void addInstance(Component* newInstance) {
            component_list.push_back(newInstance);
        }

        static void start()
        {
            for (size_t i = 0; i < component_list.size(); i++)
            {
                component_list[i]->start();
            }
        }

        static void update()
        {
            for (size_t i = 0; i < component_list.size(); i++)
            {
                component_list[i]->update();
            }
        }

        ComponentBase(ComponentBase const&) = delete;
        ComponentBase& operator=(ComponentBase const&) = delete;
    };
}

#endif // !CATCH_UP_ENGINE_SRC_INCLUDE_COMPONENT_BASE_H