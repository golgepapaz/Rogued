#pragma once
#include "Geometry.h"
#include "LevelGenerator.h"

class SpanningTreeGenerator : public ILevelGenerator
{
    virtual DungeonLevel* GenerateLevel(int sizeX, int sizeY) override;
};