#pragma once
#include <vector>
#include "wolf/wolf.h"
#include "hare/hare.h"

namespace Game
{
	class EventManager
	{
		static std::vector<Hare*> s_ptr_hare_list;
		static std::vector<Wolf*> s_ptr_wolf_list;
		//static std::vector<Carrot*> s_ptr_carrot_list;

		static std::vector<Engine::Vector2f> s_hare_list;
		static std::vector<Engine::Vector2f> s_wolf_list;
		//static std::vector<Carrot*> s_carrot_list;

		static uint32_t s_number_of_wolf;
		static uint32_t s_number_of_hare;
		static uint32_t s_number_of_carrot;

		static Engine::Vector2f s_size_of_wolf;
		static Engine::Vector2f s_size_of_hare;

		static uint32_t s_cooldown_carrot_time;
		static uint32_t s_duration_carrot_time;

		static EventManager* s_ptr_instance;

		~EventManager() = default;
	public:

		static EventManager* getInstance();

		static void destroy();

		void setNumberOfWolfAndSize(uint32_t number, Engine::Vector2f size = Engine::Vector2f(25.0f, 25.0f));
		void setNumberOfHareAndSize(uint32_t number, Engine::Vector2f size = Engine::Vector2f(25.0f, 25.0f));

		void setCooldownCarrot(uint32_t time_in_seconds);
		void setDurationCarrot(uint32_t time_in_seconds);

		void spawn(Engine::Vector2f min_bound, Engine::Vector2f max_bound);
		void destroy(Engine::UUID uuid);

		uint32_t getNumberOfWolf();
		uint32_t getNumberOfHare();

		std::vector<Engine::Vector2f> getWolfTeam();
		std::vector<Engine::Vector2f> getHareTeam();
	};
}