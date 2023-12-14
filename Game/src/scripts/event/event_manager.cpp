#include "event/event_manager.h"

#include "random.h"
#include <thread>

std::vector<Entity*> Game::EventManager::s_ptr_entities_list;

std::vector<Engine::Vector2f> Game::EventManager::s_wolf_list;
std::vector<Engine::Vector2f> Game::EventManager::s_hare_list;
std::vector<Engine::Vector2f> Game::EventManager::s_carrot_list;

uint32_t Game::EventManager::s_number_of_wolf	= 0;
uint32_t Game::EventManager::s_number_of_hare	= 0;
uint32_t Game::EventManager::s_number_of_carrot = 0;

Engine::Vector2f Game::EventManager::s_size_of_wolf = Engine::Vector2f(25.0f, 25.0f);
Engine::Vector2f Game::EventManager::s_size_of_hare = Engine::Vector2f(25.0f, 25.0f);
Engine::Vector2f Game::EventManager::s_size_of_carrot = Engine::Vector2f(12.0f, 12.0f);

uint32_t Game::EventManager::s_cooldown_carrot_time = 5;
uint32_t Game::EventManager::s_duration_carrot_time = 10;

Engine::Vector2f Game::EventManager::s_min_bound = Engine::Vector2f(0.0f, 0.0f);
Engine::Vector2f Game::EventManager::s_max_bound = Engine::Vector2f(0.0f, 0.0f);

Engine::Timer* Game::EventManager::m_ptr_timer = nullptr;

Game::EventManager* Game::EventManager::s_ptr_instance = nullptr;

void Game::EventManager::terminate()
{
	s_wolf_list.clear();
	s_hare_list.clear();
	s_carrot_list.clear();
	for (auto& i : s_ptr_entities_list)
	{
		i->destroy(i);
	}
	delete m_ptr_timer;
	delete s_ptr_instance;
	s_ptr_instance = nullptr;
}

Game::EventManager* Game::EventManager::getInstance()
{
	if (s_ptr_instance == nullptr)
		s_ptr_instance = new EventManager();
	return s_ptr_instance;
}

void Game::EventManager::setNumberOfWolfAndSize(uint32_t number, Engine::Vector2f size)
{
	s_number_of_wolf = number;
	s_size_of_wolf = size;
}

void Game::EventManager::setNumberOfHareAndSize(uint32_t number, Engine::Vector2f size)
{
	s_number_of_hare = number;
	s_size_of_wolf = size;
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
	Engine::Random random;
	s_min_bound = min_bound;
	s_max_bound = max_bound;
	m_ptr_timer = new Engine::Timer();

	for (size_t i = 0; i < s_number_of_wolf; i++)
	{
		//!!!	There is a collision	!!!
		// 
		// Details:
		// If the random number generator produces close positions for two or more objects, 
		// then a collision will occur and there is a possibility that the objects 
		// may get stuck in each other or be pushed beyond the boundaries of the map, 
		// which is unacceptable.
		// 
		s_ptr_entities_list.push_back(new Wolf(
			random.Next(min_bound.x, max_bound.x),				//	position.x
			random.Next(min_bound.y, max_bound.y),				//	position.y
			s_size_of_wolf.x,									//	width
			s_size_of_wolf.y									//	height
		));
	}

	for (size_t i = 0; i < s_number_of_hare; i++)
	{
		//!!!	There is a collision	!!!
		//	
		// Details:
		// If the random number generator produces close positions for two or more objects, 
		// then a collision will occur and there is a possibility that the objects 
		// may get stuck in each other or be pushed beyond the boundaries of the map, 
		// which is unacceptable.
		//
		s_ptr_entities_list.push_back(new Hare(
			random.Next(min_bound.x, max_bound.x),				//	position.x
			random.Next(min_bound.y, max_bound.y),				//	position.
			s_size_of_hare.x,									//	width
			s_size_of_hare.y									//	height
		));
	}
}

void Game::EventManager::destroy(Engine::UUID uuid)
{
	std::vector<Entity*>::iterator temp;
	for (auto i = s_ptr_entities_list.begin(); i != s_ptr_entities_list.end(); i++)
	{
		if ((*i)->GetUUID() == uuid)
		{
			temp = i;
		}
	}
	(*temp)->destroy((*temp));
	s_ptr_entities_list.erase(temp);
}

void Game::EventManager::update()
{
	//Engine::Random random;
	/*m_ptr_timer->addInSeconds(s_cooldown_carrot_time, [&]() {

	});*/
}

uint32_t Game::EventManager::getNumberOfWolf()
{
	return s_number_of_wolf;
}

uint32_t Game::EventManager::getNumberOfHare()
{
	return s_number_of_hare;
}

std::vector<Engine::Vector2f> Game::EventManager::getWolfTeam()
{
	s_wolf_list.clear();
	for (size_t i = 0; i < s_ptr_entities_list.size(); i++)
	{
		if(s_ptr_entities_list[i]->getType() == EntityType::WOLF)
			s_wolf_list.push_back(s_ptr_entities_list[i]->getComponent<Engine::Transform>().position);
	}
	return s_wolf_list;
}

std::vector<Engine::Vector2f> Game::EventManager::getHareTeam()
{
	s_hare_list.clear();
	for (size_t i = 0; i < s_ptr_entities_list.size(); i++)
	{
		if(s_ptr_entities_list[i]->getType() == EntityType::HARE)
			s_hare_list.push_back(s_ptr_entities_list[i]->getComponent<Engine::Transform>().position);
	}
	return s_hare_list;
}