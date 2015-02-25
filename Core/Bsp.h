
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
class BSPTree
{
    BSPNode  *root;
public:
    BSPTree(int x, int y, int w, int h)
    {
        root = new BSPNode(x, y, w, h);
    }

};
