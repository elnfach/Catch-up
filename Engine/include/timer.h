#pragma once

#include <thread>

namespace Engine
{
	class Timer
	{
	public:
		enum class TimeUnit
		{
			IN_MILLISECONDS = 0,
			IN_SECONDS = 1
		};

		Timer()						 = default;
		Timer(const Timer&)			 = delete;
		Timer(const Timer&&)		 = delete;
		~Timer()					 = default;
		void operator=(const Timer&) = delete;

		Timer(uint32_t delay, TimeUnit unit = TimeUnit::IN_SECONDS);
		
		void start();
		void reset();
		bool getStatus() const;
	private:
		uint32_t m_delay	= 0;
		bool m_is_finished  = false;
		bool m_is_busy		= false;
		TimeUnit m_unit;
		std::thread m_timer_thread;
	};
}