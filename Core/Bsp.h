
#pragma once

struct BSPNode
{
    BSPNode(int x, int y, int w, int h) : x(x), y(y), w(w), h(h), parent(nullptr), left(nullptr), right(nullptr)
    {}
    BSPNode *parent;
    BSPNode *left;
    BSPNode *right;
    int x, y, w, h;

};
class BSPTree : public BSPNode
{
    BSPNode  *root;
public:
    BSPTree(int x, int y, int w, int h) : BSPNode(x, y, w, h)
    {

    }
    void Divide(bool direction, int pos)
    {
        if (direction) //horizontal
        {
            int y1 = this->y;
            int y2 = pos;
            int h1 = pos - this->y;

            left = new BSPTree(x,)
        }

    }

};
