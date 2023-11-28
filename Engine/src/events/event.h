#ifndef CATCH_UP_ENGINE_SRC_EVENTS_EVENT_H
#define CATCH_UP_ENGINE_SRC_EVENTS_EVENT_H

namespace Engine
{
	class Event
	{
		enum class EventType
		{
			None = 0,
			WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
			AppTick, AppUpdate, AppRender,
			OnCollisionEnter2D, OnCollisionExit2D,
			KeyPressed, KeyReleased, KeyTyped,
			MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
		};
	public:
		Event();
		~Event();
	};
}

#endif // !CATCH_UP_ENGINE_SRC_EVENTS_EVENT_H