#pragma once
#include <chrono>
#include <functional>

namespace Engine
{
	class Timer
	{
		Timer();
		void add(std::chrono::milliseconds delay,
			std::function<void()> callback,
			bool asynchronous = true);

		void add(std::chrono::seconds delay,
			std::function<void()> callback,
			bool asynchronous = true);
	};
}