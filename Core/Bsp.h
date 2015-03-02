
#pragma once

#include "Random.h"
#include <algorithm>
#include <iostream>
#include <deque>

class BSPTree
{
    BSPTree *parent = nullptr;
    BSPTree *left = nullptr;
    BSPTree *right = nullptr;
public:
    int x = 0, y = 0, w = 0, h = 0;
    int level = 0;
public:
    BSPTree(int x, int y, int w, int h) : x(x), y(y), w(w), h(h)
    {

    }
    BSPTree* GetLeft() const
    {
        return left;
    }
    BSPTree* GetRight() const
    {
        return right;
    }
    void Divide(bool direction, int pos)
    {
        if (direction) //horizontal
        {
            left = new BSPTree(x, y, w, pos - y);
            right = new BSPTree(x, pos, w, y + h - pos);

        }
        else
        {
            left = new BSPTree(x, y, pos - x, h);
            right = new BSPTree(pos, y, x + w - pos, h);
        }
        left->parent = this;
        left->level = level + 1;
        right->parent = this;
        right->level = level + 1;

    }
    void DivideRecursively(int level, int minHeight, int minWidth, float hwratio)
    {
        if (!level || w < 2 * minWidth && h < 2 * minHeight)
            return;
        auto ratio = std::min(h, w) / std::max(w, h);
        int direction = 0;
        if (h < 2 * minHeight)
            direction = true;
        else if (w < 2 * minWidth)
            direction = false;
        else
        {
            direction = Randomizer::RandInt(0, 1);
        }


        if (direction)
        {
            int pos = Randomizer::RandInt(y + minHeight, y + h - minHeight);
            Divide(direction, pos);
        }
        else
        {
            int pos = Randomizer::RandInt(x + minWidth, x + w-minWidth);
            Divide(direction, pos);
        }
        left->DivideRecursively(level - 1, minHeight, minWidth, hwratio);
        right->DivideRecursively(level - 1, minHeight, minWidth, hwratio);

    }
    template <typename T>
    bool TraverseBFS(T visitor)
    {
        std::deque<BSPTree*> deq;
        deq.push_back(this);
        while (!deq.empty())
        {
            auto node = deq.front();
            deq.pop_front();
            if (node->GetLeft())
                deq.push_back(node->GetLeft());
            if (node->GetRight())
                deq.push_back(node->GetRight());
            if (!visitor(node))
                return false;
        }
        return true;
    }


};
struct BSPPrintVisitor
{
    bool operator()(BSPTree* tree)
    {
        std::cout << "level : " << tree->level << " (x,y,w,h) : " << tree->x << ','
            << tree->y << ',' << tree->w << ',' << tree->h << ")\n";
        return true;
    }
};
