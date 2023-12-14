#pragma once
#include <vector>
#include "wolf/wolf.h"
#include "hare/hare.h"
#include "carrot/carrot.h"
#include "timer.h"

namespace Game
{
	class EventManager : public Engine::ScriptBehaviour
	{
		static std::vector<Entity*> s_entities_list;

		static std::vector<Engine::Vector2f> s_hare_list;
		static std::vector<Engine::Vector2f> s_wolf_list;
		static std::vector<Engine::Vector2f> s_carrot_list;

		static uint32_t s_number_of_wolf;
		static uint32_t s_number_of_hare;
		static uint32_t s_number_of_carrot;

		static Engine::Vector2f s_size_of_wolf;
		static Engine::Vector2f s_size_of_hare;
		static Engine::Vector2f s_size_of_carrot;

		static uint32_t s_cooldown_carrot_time;
		static uint32_t s_duration_carrot_time;

		static Engine::Vector2f s_min_bound;
		static Engine::Vector2f s_max_bound;

		static Engine::Timer* s_ptr_cooldown_carrot_timer;

		static EventManager* s_ptr_instance;

		EventManager();
		
		~EventManager() = default;

		void update() override;
	public:
		EventManager(const EventManager&) = delete;
		EventManager(const EventManager&&) = delete;

		void operator=(const EventManager&) = delete;

		static EventManager* getInstance();

		static void terminate();

		void setNumberOfWolfAndSize(uint32_t number, Engine::Vector2f size = Engine::Vector2f(25.0f, 25.0f));
		void setNumberOfHareAndSize(uint32_t number, Engine::Vector2f size = Engine::Vector2f(25.0f, 25.0f));
		void setSizeCarrots(Engine::Vector2f size = Engine::Vector2f(12.0f, 12.0f));

		void setCooldownCarrot(uint32_t time_in_seconds);
		void setDurationCarrot(uint32_t time_in_seconds);

		void spawn(Engine::Vector2f min_bound, Engine::Vector2f max_bound);
		void destroy(Engine::UUID uuid);

		uint32_t getNumberOfWolf() const;
		uint32_t getNumberOfHare() const;
		uint32_t getNumberOfCarrots() const;

		std::vector<Engine::Vector2f> getWolfTeam() const;
		std::vector<Engine::Vector2f> getHareTeam() const;
		std::vector<Engine::Vector2f> getCarrots() const;
	};
}