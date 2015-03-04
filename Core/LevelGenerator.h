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
    unsigned minX = 20;
    unsigned minY = 20;
    unsigned minRoomX = 6;
    unsigned minRoomY = 6;

public:
    DungeonLevel* GenerateLevel(int sizeX, int sizeY) override
    {
        level = new DungeonLevel(sizeX, sizeY);

        BSPTree tree{ 0,0,sizeX, sizeY };
        auto depth = sizeX * sizeY / (minX * minY);
        tree.DivideRecursively(20, minX, minY, 10);
        tree.TraverseInvertedBFS(*this);
        return level;


    }
    bool operator()(BSPTree* tree)
    {
        if (tree->IsLeaf())
        {
           auto x1 = Randomizer::RandInt(tree->x, tree->x + tree->w - minRoomX);
           auto x2 = Randomizer::RandInt(x1 + minRoomX, tree->x + tree->w);
           auto y1 = Randomizer::RandInt(tree->y, tree->y + tree->h - minRoomY);
           auto y2 = Randomizer::RandInt(y1 + minRoomY, tree->y + tree->h);

           tree->room = level->MakeRoom(x1, y1 , x2-x1, y2-y1);


        }
        else
        {
            auto left = tree->GetLeft()->room;
            auto right = tree->GetRight()->room;
            if (tree->horizontal)
            {
                //no intersection
                if (left->x + left->w - 1 < right->x || right->x + right->w - 1 < left->x)
                {

                }
                else
                {

                }

            }
        }
        return true;
    }
};