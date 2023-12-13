#include "event/event_manager.h"

std::vector<Wolf*> Game::EventManager::s_ptr_wolf_list;
std::vector<Hare*> Game::EventManager::s_ptr_hare_list;

std::vector<Wolf> Game::EventManager::s_wolf_list;
std::vector<Hare> Game::EventManager::s_hare_list;

uint32_t Game::EventManager::s_number_of_wolf	= 0;
uint32_t Game::EventManager::s_number_of_hare	= 0;
uint32_t Game::EventManager::s_number_of_carrot = 0;

uint32_t Game::EventManager::s_cooldown_carrot_time = 20;
uint32_t Game::EventManager::s_duration_carrot_time = 10;

Game::EventManager* Game::EventManager::getInstance()
{
	Game::EventManager instance;
	return &instance;
}

void Game::EventManager::setNumberOfWolf(uint32_t number, uint32_t size)
{
	s_number_of_wolf = number;
}

void Game::EventManager::setNumberOfHare(uint32_t number, uint32_t size)
{
	s_number_of_hare = number;
}

void Game::EventManager::setCooldownCarrot(uint32_t time_in_seconds)
{
	s_cooldown_carrot_time = time_in_seconds;
}

void Game::EventManager::setDurationCarrot(uint32_t time_in_seconds)
{
	s_duration_carrot_time = time_in_seconds;
}

void Game::EventManager::spawn(Engine::Vector2f min_bound, Engine::Vector2f max_bound)
{
	for (size_t i = 0; i < s_number_of_wolf; i++)
	{
		s_ptr_wolf_list.push_back(new Wolf());
		s_wolf_list.push_back(*s_ptr_wolf_list[i]);
	}

	for (size_t i = 0; i < s_number_of_hare; i++)
	{
		s_ptr_hare_list.push_back(new Hare());
		s_hare_list.push_back(*s_ptr_hare_list[i]);
	}
}

uint32_t Game::EventManager::getNumberOfWolf()
{
	return s_number_of_wolf;
}

uint32_t Game::EventManager::getNumberOfHare()
{
	return s_number_of_hare;
}

std::vector<Wolf> Game::EventManager::getWolfTeam()
{
	return s_wolf_list;
}

std::vector<Hare> Game::EventManager::getHareTeam()
{
	return s_hare_list;
}