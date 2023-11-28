#pragma once

#include "props.h"

namespace Engine
{
	class Drawable;
	class Renderer
	{
	protected:
		Renderer() {}
	public:
		Renderer(const Renderer&) = delete;
		Renderer(const Renderer&&) = delete;
		virtual ~Renderer() {}
		void operator=(const Renderer&) = delete;

		virtual void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) = 0;
		virtual void clear() = 0;
		virtual void draw(Drawable* dr) = 0;
		virtual void setVSync(bool enabled) = 0;
		virtual bool isVSync() const = 0;
		virtual void* getInstance() const = 0;
		virtual void shutdown() = 0;

		static Renderer* create(RendererProps props);
	};
}