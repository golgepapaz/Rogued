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
    unsigned minRoomX = 10;
    unsigned minRoomY = 10;

public:
    DungeonLevel* GenerateLevel(int sizeX, int sizeY) override
    {
        level = new DungeonLevel(sizeX, sizeY);

        BSPTree tree{ 0, 0, sizeX, sizeY };
        auto depth = sizeX * sizeY / (minX * minY);
        tree.DivideRecursively(1, minX, minY, 10);
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

            level->MakeRoom(x1, y1, x2 - x1, y2 - y1);
            tree->x = x1;
            tree->y = y1;
            tree->w = x2 - x1 + 1;
            tree->h = y2 - y1 + 1;


        }
        else
        {
            auto left = tree->GetLeft();
            auto right = tree->GetRight();
            tree->x = std::min(left->x, right->x);
            tree->y = std::min(left->y, right->y);
            tree->w = std::max(left->x + left->w, right->x + right->w) - tree->x;
            tree->h = std::max(left->y + left->h, right->y + right->h) - tree->y;


            if (tree->horizontal)
            {
                //no intersection
        /*        if (left->x + left->w - 1 < right->x || right->x + right->w - 1 < left->x)
                {
                    int x1 = Randomizer::RandInt(left->x, left->x + left->w - 1);
                    int x2 = Randomizer::RandInt(right->x, right->x + right->w - 1);
                    int y = Randomizer::RandInt(left->y + left->h, right->y);
                    level->DigVertically(left->y, y-1, x1);
                    level->DigHorizontally(x1, x2, y);
                    level->DigVertically(right->y, y , x2);

                }
                else
                {
                    int minX = std::max(left->x, right->x);
                    int maxX = std::min(left->x + left->w - 1, right->x + right->w - 1);
                    int x = Randomizer::RandInt(minX, maxX);
                    level->DigVertically(left->y, right->y, x);


                }*/

            }
            else
            {
                if (left->y + left->h - 1 < right->y || right->y + right->h - 1 < left->y)
                {
                    int y1 = Randomizer::RandInt(left->y, left->y + left->h - 1);
                    int y2 = Randomizer::RandInt(right->y, right->y + right->h - 1);
                    int x = Randomizer::RandInt(left->x + left->w, right->x);
                    level->DigHorizontally(left->x, x - 1, y1);
                    level->DigVertically(y1, y2, x);
                    level->DigHorizontally(right->x, x, y2);
                }
                else
                {
                    int minY = std::max(left->y, right-> y);
                    int maxY = std::min(left->y +left->h - 1, right->y + right->h - 1);
                    int y = Randomizer::RandInt(minY, maxY);
                    level->DigHorizontally(left->x, right->x, y);


                }

            }
        }
        return true;
    }
};