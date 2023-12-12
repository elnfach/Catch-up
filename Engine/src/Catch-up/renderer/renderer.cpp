#include "renderer.h"

Engine::RendererAPI* Engine::Renderer::m_ptr_renderer_api = nullptr;

void Engine::Renderer::init(void* window)
{
	m_ptr_renderer_api = RendererAPI::create(RendererProps(window));
}

void Engine::Renderer::clear(const Vector4f color = Vector4f(0.0f, 0.0f, 0.0f, 0.0f))
{
	m_ptr_renderer_api->setColor(color);
	m_ptr_renderer_api->clear();
}

void Engine::Renderer::drawRectangle(const Transform transform, Vector2f size, const Vector4f color)
{
	m_ptr_renderer_api->drawRectangle(transform, size, color);
}

void Engine::Renderer::drawCircle()
{

}

void Engine::Renderer::present()
{
	m_ptr_renderer_api->present();
}

void Engine::Renderer::shutdown()
{
	m_ptr_renderer_api->shutdown();
}

void Engine::Renderer::OnWindowResize(unsigned int width, unsigned int height)
{
}