#include "timer.h"
#include <thread>

void Engine::Timer::add(
	std::chrono::milliseconds delay, 
	std::function<void()> callback, 
	bool asynchronous)
{
	if (asynchronous) {
		std::thread([=]() {
			std::this_thread::sleep_for(std::chrono::milliseconds(delay));
			callback();
			}).detach();
	}
	else {
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
		callback();
	}
}

void Engine::Timer::add(
	std::chrono::seconds delay, 
	std::function<void()> callback, 
	bool asynchronous)
{
	if (asynchronous) {
		std::thread([=]() {
			std::this_thread::sleep_for(std::chrono::milliseconds(delay));
			callback();
			}).detach();
	}
	else {
		std::this_thread::sleep_for(std::chrono::seconds(delay));
		callback();
	}
}
