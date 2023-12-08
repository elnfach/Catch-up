#include "Catch-up/utils/platform_utils.h"
#include <SDL_timer.h>

namespace Engine
{
	float Time::GetTime()
	{
		return SDL_GetTicks() / 1000.0f;
	}
}