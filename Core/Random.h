#pragma once

#include <random>
#include <chrono>
class Randomizer
{
    static std::default_random_engine generator;
public:
    Randomizer()
    {
        std::random_device sd;
        generator.seed(sd);
    }
    static int RandInt(int min, int max)
    {
        std::uniform_int_distribution<int> dist(min, max);
        return dist(generator);
    }
    static float RandFloat(float min, float max)
    {
        std::uniform_real_distribution<float> dist(min, max);
        return dist(generator);
    }

};



