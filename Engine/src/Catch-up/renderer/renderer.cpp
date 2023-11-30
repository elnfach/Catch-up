#include "renderer.h"
#include "components\drawable\drawable.h"

Engine::RendererAPI* Engine::Renderer::m_ptr_renderer_api = nullptr;

std::vector<Engine::Drawable*> Engine::Renderer::m_drawable_list;

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
	m_drawable_list.push_back(drawable);
}

void Engine::Renderer::update()
{
	m_ptr_renderer_api->setColor(255, 255, 255, 255);
	m_ptr_renderer_api->clear();
	for (size_t i = 0; i < m_drawable_list.size(); i++)
	{
		m_ptr_renderer_api->draw(m_drawable_list[i]->draw());
	}
	m_ptr_renderer_api->present();
}