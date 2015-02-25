#pragma once

#include <random>
class Randomizer
{
    static std::default_random_engine generator;
public:
    static int RandInt(int min, int max)
    {
        std::uniform_int_distribution<int> dist(min, max);
        return dist(generator);
    }
    static float RandFloat(float min, float max)
    {
        std::uniform_real_distribution<float> dist(min, max)
        return dist(generator);
    }

};



