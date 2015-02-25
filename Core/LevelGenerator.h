#pragma once
#include "Level.h"
class ILevelGenerator
{
public:
    virtual ~ILevelGenerator() {}

    virtual DungeonLevel GenerateLevel(int sizeX, int sizeY) = 0;
};

class BSPLevelGenerator : public ILevelGenerator
{
public:
    DungeonLevel GenerateLevel(int sizeX, int sizeY) override
    {}
};