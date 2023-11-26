#pragma once

struct WindowProps
{
	std::string title;
	unsigned int width;
	unsigned int height;
	WindowProps(std::string title = "Catch up!"
		, unsigned int width = 1280
		, unsigned int height = 720
	) : title(title), width(width), height(height)
	{}
};