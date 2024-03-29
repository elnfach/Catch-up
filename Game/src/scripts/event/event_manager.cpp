#include "event/event_manager.h"

#include "random.h"

std::vector<Game::Entity*> Game::EventManager::s_entities_list;

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

std::unique_ptr<Engine::Timer> Game::EventManager::s_ptr_cooldown_carrot_timer = nullptr;
std::unique_ptr<Engine::Timer> Game::EventManager::s_ptr_duration_carrot_timer = nullptr;

Game::EventManager* Game::EventManager::s_ptr_instance = nullptr;
Game::Map* Game::EventManager::s_ptr_map = nullptr;

Game::EventManager::EventManager()
{
	name = "EventManager";
	removeComponent<Engine::Transform>();
	removeComponent<Engine::RectangleDrawable>();
}

void Game::EventManager::terminate()
{
	s_wolf_list.clear();
	s_hare_list.clear();
	s_carrot_list.clear();
	for (auto& i : s_entities_list)
	{
		i->destroy((*i).getUUID());
	}
	delete s_ptr_instance;
	delete s_ptr_map;
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
	s_size_of_hare = size;
}

void Game::EventManager::setSizeCarrots(Engine::Vector2f size)
{
	s_size_of_carrot = size;
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
	s_ptr_cooldown_carrot_timer = std::make_unique<Engine::Timer>(s_cooldown_carrot_time);
	s_ptr_duration_carrot_timer = std::make_unique<Engine::Timer>(s_duration_carrot_time);

	for (size_t i = 0; i < s_number_of_wolf; i++)
	{ 
		s_entities_list.push_back(new Wolf(
			random.Next(min_bound.x, max_bound.x),				//	position.x
			random.Next(min_bound.y, max_bound.y),				//	position.y
			s_size_of_wolf.x,									//	width
			s_size_of_wolf.y,									//	height
			s_ptr_map->getInstance()->generateRandomMap(
				Engine::Vector2f(min_bound.x, min_bound.y), 
				Engine::Vector2f(max_bound.x, max_bound.y), 
				5, 
				25)
		));
	}

	for (size_t i = 0; i < s_number_of_hare; i++)
	{
		s_entities_list.push_back(new Hare(
			random.Next(min_bound.x, max_bound.x),				//	position.x
			random.Next(min_bound.y, max_bound.y),				//	position.y
			s_size_of_hare.x,									//	width
			s_size_of_hare.y,									//	height
			s_ptr_map->getInstance()->generateRandomMap(
				Engine::Vector2f(min_bound.x, min_bound.y),
				Engine::Vector2f(max_bound.x, max_bound.y),
				5,
				25)
		));
	}

	
}

void Game::EventManager::destroy(Engine::UUID uuid)
{
	for (auto i = s_entities_list.begin(); i != s_entities_list.end();)
	{
		if ((*i)->getUUID() == uuid)
		{
			if ((*i)->getType() == EntityType::WOLF)
				--s_number_of_wolf;
			if ((*i)->getType() == EntityType::HARE)
				--s_number_of_hare;
			if ((*i)->getType() == EntityType::CARROT)
				--s_number_of_carrot;
			(*i)->destroy(uuid);
			i = s_entities_list.erase(i);
		}
		else
			++i;
	}
}

void Game::EventManager::update()
{
	Engine::Random random;
	s_ptr_cooldown_carrot_timer->start();
	if (s_ptr_cooldown_carrot_timer->getStatus())
	{
		s_entities_list.push_back(new Carrot(
			random.Next(s_min_bound.x, s_max_bound.x),				//	position.x
			random.Next(s_min_bound.y, s_max_bound.y),				//	position.y
			s_size_of_carrot.x,										//	width
			s_size_of_carrot.y										//	height
		));
		s_number_of_carrot++;
		s_ptr_cooldown_carrot_timer->reset();
	}
	for (auto& i : s_entities_list)
	{
		if (i->getType() == EntityType::CARROT)
		{
			s_ptr_duration_carrot_timer->start();
			if (s_ptr_duration_carrot_timer->getStatus())
			{
				destroy(i->getUUID());
				s_number_of_carrot--;
				s_ptr_duration_carrot_timer->reset();
			}
		}
	}
}

uint32_t Game::EventManager::getNumberOfWolf() const
{
	return s_number_of_wolf;
}

uint32_t Game::EventManager::getNumberOfHare() const
{
	return s_number_of_hare;
}

uint32_t Game::EventManager::getNumberOfCarrots() const
{
	return s_number_of_carrot;
}

std::vector<Engine::Vector2f> Game::EventManager::getWolfTeam() const
{
	s_wolf_list.clear();
	for (size_t i = 0; i < s_entities_list.size(); i++)
	{
		if(s_entities_list[i]->getType() == EntityType::WOLF)
			s_wolf_list.push_back(s_entities_list[i]->getComponent<Engine::Transform>().position);
	}
	return s_wolf_list;
}

std::vector<Engine::Vector2f> Game::EventManager::getHareTeam() const
{
	s_hare_list.clear();
	for (size_t i = 0; i < s_entities_list.size(); i++)
	{
		if (s_entities_list[i]->getType() == EntityType::HARE)
		{
			s_hare_list.push_back(s_entities_list[i]->getComponent<Engine::Transform>().position);
		}
	}
	return s_hare_list;
}

std::vector<Engine::Vector2f> Game::EventManager::getCarrots() const
{
	s_carrot_list.clear();
	for (size_t i = 0; i < s_entities_list.size(); i++)
	{
		if (s_entities_list[i]->getType() == EntityType::CARROT)
			s_carrot_list.push_back(s_entities_list[i]->getComponent<Engine::Transform>().position);
	}
	return s_carrot_list;
}