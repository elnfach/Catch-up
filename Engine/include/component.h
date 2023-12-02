#ifndef CATCH_UP_ENGINE_INCLUDE_COMPONENT_H
#define CATCH_UP_ENGINE_INCLUDE_COMPONENT_H

#include "object.h"

namespace Engine
{
	class Component : public Object
	{
	protected:
		enum class ComponentType
		{
			Unknown = 0,
			ScriptBehaviour,
			Transform,
			Drawable,
			BoxCollider2D
		};
	public:
		Component();
		Component(ComponentType type);
		~Component();

		inline std::string getInstanceType() const override {
			switch (component_type)
			{
			case ComponentType::Unknown:
				return "Unknown";
			case ComponentType::ScriptBehaviour:
				return "ScriptBehaviour";
			case ComponentType::Transform:
				return "Transform";
			case ComponentType::Drawable:
				return "Drawable";
			case ComponentType::BoxCollider2D:
				return "BoxCollider2D";
			default:
				return "Invalid type";
			}
		}

		virtual void start() {}
		virtual void update() {}
	private:
		ComponentType component_type;
	};
}

#endif // !CATCH_UP_ENGINE_INCLUDE_COMPONENT_H