#ifndef CATCH_UP_ENGINE_SRC_INCLUDE_COMPONENT_BASE_H
#define CATCH_UP_ENGINE_SRC_INCLUDE_COMPONENT_BASE_H

#include "component.h"

namespace Engine
{
    class ComponentBase
    {
        ComponentBase* m_ptr_component_base = nullptr;
        static inline std::vector<Component*> component_list;
        ComponentBase() {}
        ~ComponentBase() {}
    public:
        
        static ComponentBase* getInstance() {
            static ComponentBase instance;
            return &instance;
        }
        ComponentBase(const ComponentBase&) = delete;
        ComponentBase(const ComponentBase&&) = delete;

        static void addInstance(Component* newInstance) {
            component_list.push_back(newInstance);
        }

        void start();
        void update();
    };
}

#endif // !CATCH_UP_ENGINE_SRC_INCLUDE_COMPONENT_BASE_H