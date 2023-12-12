#pragma once

namespace Engine {

	class Timestep
	{
	public:
		static Timestep* getInstance();

		operator float() const;

		static void setDeltaTime(float time = 0.0f);

		static float getDeltaTime();
		static float getMilliseconds();
	private:
		static float m_time;
	};
}