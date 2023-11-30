#include "renderer.h"
#include "components\drawable\drawable.h"

Engine::RendererAPI* Engine::Renderer::m_ptr_renderer_api = nullptr;

void Engine::Renderer::init(void* window)
{
	m_ptr_renderer_api = RendererAPI::create(RendererProps(window));
}

void Engine::Renderer::shutdown()
{
}

void Engine::Renderer::OnWindowResize(unsigned int width, unsigned int height)
{
}

void Engine::Renderer::submit(Drawable* drawable)
{
	if (drawable != nullptr)
	{
		//m_drawable_list.push_back(drawable);
	}
}

void Engine::Renderer::update()
{
	m_ptr_renderer_api->setColor(255, 255, 255, 255);
	m_ptr_renderer_api->clear();
}