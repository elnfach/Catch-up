#include "timer.h"

#include <chrono>
#include <functional>
#include <queue>

Engine::Timer::Timer(uint32_t delay, TimeUnit unit) : 
	m_delay(delay), 
	m_unit(unit), 
	m_is_busy(false), 
	m_is_finished(false)
{
}

void Engine::Timer::start()
{
	if (!m_is_busy)
	{
		m_is_busy = true;
		if (m_unit == TimeUnit::IN_MILLISECONDS)
		{
			m_timer_thread = std::thread([&]() {
				std::this_thread::sleep_for(std::chrono::milliseconds(m_delay));
				m_is_finished = true;
				m_is_busy = false;
			});
		}
		if (m_unit == TimeUnit::IN_SECONDS)
		{
			m_timer_thread = std::thread([&]() {
				std::this_thread::sleep_for(std::chrono::seconds(m_delay));
				m_is_finished = true;
				m_is_busy = false;
			});
		}
		m_timer_thread.detach();
	}
}

void Engine::Timer::reset()
{
	m_is_finished = false;
}

bool Engine::Timer::getStatus() const
{
	return m_is_finished;
}
