#include "timer.h"

#include <chrono>
#include <functional>
#include <queue>

void Engine::Timer::start(uint32_t delay, TimeUnit unit)
{
	if (unit == TimeUnit::IN_MILLISECONDS)
	{
		m_timer_thread = std::thread([&]() {
			std::this_thread::sleep_for(std::chrono::milliseconds(delay));
			m_is_finished = true;
		});
	} 
	if (unit == TimeUnit::IN_SECONDS)
	{
		m_timer_thread = std::thread([&]() {
			std::this_thread::sleep_for(std::chrono::seconds(delay));
			m_is_finished = true;
		});
	}
}

bool Engine::Timer::getStatus()
{
	return m_is_finished;
}
