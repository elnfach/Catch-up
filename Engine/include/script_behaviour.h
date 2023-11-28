#ifndef CATHCHUP_ENGINE_INCLUDE_SCRIPT_BEHAVIOUR_H
#define CATHCHUP_ENGINE_INCLUDE_SCRIPT_BEHAVIOUR_H

#include "component.h"

namespace Engine
{
	class ScriptBehaviour : Component
	{
		std::vector<ScriptBehaviour*> list;
		static ScriptBehaviour* m_ptr_instance;
	public:
		ScriptBehaviour();
		~ScriptBehaviour();

		virtual void start() {}
		virtual void update() {}

		static ScriptBehaviour* create();
	};
}

#endif // !CATHCHUP_ENGINE_INCLUDE_SCRIPT_BEHAVIOUR_H