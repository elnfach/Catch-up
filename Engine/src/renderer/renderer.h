#pragma once

#include "props.h"

namespace Engine
{
	class Renderer
	{
	protected:
		Renderer() {}
	public:
		Renderer(const Renderer&) = delete;
		Renderer(const Renderer&&) = delete;
		virtual ~Renderer() {}
		void operator=(const Renderer&) = delete;

		virtual void draw() = 0;
		virtual void setVSync(bool enabled) = 0;

		static Renderer* create(RendererProps props);
	};
}