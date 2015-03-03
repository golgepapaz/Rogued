#pragma once
#include "Level.h"
#include "Bsp.h"
#include "Grid.h"

template <int X,int Y>
using DungeonGrid = Grid < Tile, X, Y > ;

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
    {
        DungeonGrid<sizeX, sizeY> grid;
        BSPTree tree{ 0,0,sizeX, sizeY };
        tree.DivideRecursively(4, 10, 10, 10);
        tree.TraverseInvertedBFS(*this);
        return DungeonLevel();


    }
    bool operator()(BSPTree* tree)
    {
        return true;
    }
};