#pragma once

#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>
#include <components/vector2f.h>

extern "C" {
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
}

class Lua
{
private:
	sol::state lua;
public:

	void init()
	{
		lua.open_libraries(
			sol::lib::base,
			sol::lib::debug,
			sol::lib::math,
			sol::lib::table,
			sol::lib::coroutine,
			sol::lib::string,
			sol::lib::package
		);

		lua.new_usertype<Engine::Vector2f>(
			"Vector2f", 
			sol::constructors<void(), void(float, float)>(),
			"x", &Engine::Vector2f::x,
			"y", &Engine::Vector2f::y,
			"Normalized", &Engine::Vector2f::normalized,
			"Magnitude", &Engine::Vector2f::magnitude,
			"operator+", sol::overload(
				[](Engine::Vector2f& self, float number) { return self + number; }),
			"operator+", sol::overload(
				[](Engine::Vector2f& self, Engine::Vector2f& right) { return self + right; })
		);
		lua.new_usertype<Engine::Transform>(
			"Transform",
			sol::constructors<void(), void(float x, float y), void(Engine::Vector2f), void(Engine::Vector2f, Engine::Vector3f, Engine::Vector2f)>(),
			"position", &Engine::Transform::position,
			"rotation", &Engine::Transform::rotation,
			"scale", &Engine::Transform::scale,
			"translate", &Engine::Transform::translate,
			"toString", &Engine::Transform::toString,
			"getInstanceID", &Engine::Transform::getInstanceID
		);
	}
	void open(const char* filename)
	{
		lua.do_file(filename);
	}
	int start()
	{
		sol::function call_start = lua["Start"];
		sol::protected_function_result result = call_start();

		if (!result.valid()) {
			std::cout << "call 'Start' failed" << std::endl;
			return 1;
		}
		return 0;
	}

	int update(float delta)
	{
		sol::function call_update = lua["Update"];
		sol::protected_function_result result = call_update.call(delta);

		if (!result.valid()) {
			//std::cout << "call 'Update' failed" << std::endl;
			return 1;
		}
		return 0;
	}
};
Lua lua;