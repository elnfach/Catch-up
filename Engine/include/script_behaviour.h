#ifndef CATHCHUP_ENGINE_INCLUDE_SCRIPT_BEHAVIOUR_H
#define CATHCHUP_ENGINE_INCLUDE_SCRIPT_BEHAVIOUR_H

#include "game_object.h"

namespace Engine
{
	class ScriptBehaviour : public GameObject
	{
		static ScriptBehaviour* m_ptr_instance;
	public:
		ScriptBehaviour();
		~ScriptBehaviour();

		ScriptBehaviour(const ScriptBehaviour&) = delete;
		ScriptBehaviour(const ScriptBehaviour&&) = delete;

		void operator=(const ScriptBehaviour&) = delete;

		ScriptBehaviour* create();
	};
}

#endif // !CATHCHUP_ENGINE_INCLUDE_SCRIPT_BEHAVIOUR_H