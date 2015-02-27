#pragma once

#include <random>
#include <chrono>
class Randomizer
{
    static std::default_random_engine generator;
    static class _init
    {
    public:
        _init()
        {
            std::random_device sd;
            generator.seed(sd());
        }
    }  init;
public:

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



