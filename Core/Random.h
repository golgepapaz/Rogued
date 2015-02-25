#pragma once

#include <random>
namespace Random
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine gen(seed);
    std::uniform_distribution<int>

}
