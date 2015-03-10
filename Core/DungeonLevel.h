
#pragma once
#include <boost/multi_array.hpp>
#include <fstream>
#include "Tile.h"

struct Coord
{
    int x;
    int y;
    Coord(int x = 0, int y = 0) : x(x), y(y)
    {}


};
class Room
{
public:
    int x;
    int y;
    int w;
    int h;
public:
    Room(int x = 0, int y = 0, int w = 1, int h = 1) : x(x), y(y), w(w), h(h)
    {}

};
class DungeonLevel
{
    boost::multi_array<Tile, 2> grid;
    std::vector <Room*> rooms;
public:

    DungeonLevel(int x, int y) : grid(boost::extents[x][y])
    {}
    auto operator[](std::size_t index) -> decltype(grid.operator[](index))
    {
        return grid[index];
    }
    Room* MakeRoom(int x, int y, int w, int h)
    {
        if (x == 0)
        {
            ++x;
            --w;
        }
        if (y == 0)
        {
            ++y;
            --h;
        }
        if (x + w >= grid.shape()[0])
        {
            w = grid.shape()[0] - x;
        }
        if (y + h >= grid.shape()[1])
        {
            h = grid.shape()[0] - y;
        }


        for (int i = x; i < x + w; ++i)
        {
            for (int j = y; j < y + h; ++j)
            {
                grid[i][j] = Tile{ TileTerrainType::ROCK };
            }
        }

        auto room = new Room(x, y, w, h);
        rooms.push_back(room);
        return room;
    }
    void DigHorizontally(int x1, int x2, int y)
    {
        auto max = std::max(x1, x2);
        auto min = std::min(x1, x2);
        if (min == max)
            return;
        do
        {
            grid[min][y] = { TileTerrainType::ROCK };
            ++min;
        } while (min < max +1);
    }
    void DigVertically(int y1, int y2, int x)
    {
        auto max = std::max(y1, y2);
        auto min = std::min(y1, y2);
        if (y1 == y2)
            return;
        do
        {
            grid[x][min] = { TileTerrainType::ROCK };
            ++min;
        } while (min<max+1);
    }
    void Print()
    {
        std::ofstream outFile("out.txt");
        for (auto x = 0; x < grid.shape()[0]; ++x)
        {
            for (auto y = 0; y < grid.shape()[1]; ++y)
            {
                if (grid[y][x].IsWall())
                    outFile << " ";
                else
                    outFile << "#";
            }
            outFile << "\n";
        }
    }
};