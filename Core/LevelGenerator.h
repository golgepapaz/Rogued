#pragma once

#include "Bsp.h"
#include "DungeonLevel.h"



class ILevelGenerator
{
public:
    virtual ~ILevelGenerator() {}

    virtual DungeonLevel* GenerateLevel(int sizeX, int sizeY) = 0;
};

class BSPLevelGenerator : public ILevelGenerator
{
 
    DungeonLevel * level;
public:
    DungeonLevel* GenerateLevel(int sizeX, int sizeY) override
    {
        level = new DungeonLevel(sizeX, sizeY);

        BSPTree tree{ 0,0,sizeX, sizeY };
        tree.DivideRecursively(20, 20, 20, 10);
        tree.TraverseInvertedBFS(*this);
        return level;


    }
    bool operator()(BSPTree* tree)
    {
        if (tree->IsLeaf())
        {
            level->MakeRoom(tree->x + 1, tree->y + 1, tree->w - 2, tree->h - 2);
        }
        return true;
    }
};