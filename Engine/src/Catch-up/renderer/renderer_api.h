#ifndef CATCH_UP_SRC_CATCH_UP_RENDERER_RENDERER_API_H
#define CATCH_UP_SRC_CATCH_UP_RENDERER_RENDERER_API_H

#include "Catch-up\props.h"
#include "components\transform.h"
#include "components\vector4f.h"

struct SDL_Renderer;
namespace Engine
{
	class Drawable;
	class RendererAPI
	{
#define SDL_MAX_UINT8   ((Uint8)0xFF)           /* 255 */
#define SDL_MIN_UINT8   ((Uint8)0x00)           /* 0 */
		typedef uint8_t Uint8;
	public:
		enum class API
		{
			None = 0, SDL = 1
		};

	protected:
		RendererAPI() = default;
	public:
		
		RendererAPI(const RendererAPI&) = delete;
		RendererAPI(const RendererAPI&&) = delete;

		virtual ~RendererAPI() {}

		void operator=(const RendererAPI&) = delete;

		virtual void setColor(Vector4f color) = 0;
		virtual void clear() = 0;
		virtual void drawRectangle(const Transform transform, Vector2f size, const Vector4f color) = 0;
		virtual void present() = 0;

		virtual void shutdown() = 0;

		virtual void setVSync(bool enabled) = 0;
		virtual bool isVSync() const = 0;

		static RendererAPI* create(RendererProps props);

	private:
		static API s_API;
	};
}

#endif // !CATCH_UP_SRC_CATCH_UP_RENDERER_RENDERER_API_H