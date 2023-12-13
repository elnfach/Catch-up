#include "random.h"

#include <random>

static std::random_device s_random_device;
static std::mt19937_64 s_engine(s_random_device());
static std::uniform_int_distribution<uint64_t> s_uniform_distribution;

/// <summary>
/// Generates a random number with 64-bit state
/// </summary>
/// 
/// <returns>
/// <para>Returns a random number</para>
/// </returns>
int Engine::Random::Next()
{
    return s_uniform_distribution(s_engine);
}

/// <summary>
/// Generates a random number with 64-bit state
/// </summary>
/// <param name="range">The range in which the generator will output a random number</param>
/// <returns>
/// <para>Returns a random number in a range</para>
/// </returns>
int Engine::Random::Next(int range)
{
    return s_uniform_distribution(s_engine) % range;
}

/// <summary>
/// Generates a random number with 64-bit state
/// </summary>
/// <param name="start">The smallest number in the range</param>
/// <param name="range">The range in which the generator will output a random number</param>
/// <returns>
/// <para>Returns a random number in a range</para>
/// </returns>
int Engine::Random::Next(int start, int range)
{
    start += s_uniform_distribution(s_engine);
    return start % range;
}
