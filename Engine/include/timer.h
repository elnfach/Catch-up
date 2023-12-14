#pragma once

#include <thread>

namespace Engine
{
	class Timer
	{
		uint32_t m_delay	= 0;
		bool m_is_finished	= false;
		std::thread m_timer_thread;

		Timer()		= default;
		~Timer()	= default;
	public:
		Timer(const Timer&)			 = delete;
		Timer(const Timer&&)		 = delete;
		void operator=(const Timer&) = delete;

		enum class TimeUnit
		{
			IN_SECONDS		= 0,
			IN_MILLISECONDS = 1
		};
		
		void start(uint32_t delay, TimeUnit unit = TimeUnit::IN_SECONDS);
		bool getStatus();
	};
}