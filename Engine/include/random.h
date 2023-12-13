#pragma once

namespace Engine
{
	class Random
	{
		Random() = default;
		Random(const Random&) = delete;
		Random(const Random&&) = delete;

		void operator=(const Random&) = delete;

		int Next();
		int Next(int range);
		int Next(int start, int range);
	};
}