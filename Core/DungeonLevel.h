
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
        for (int i = x; i < x + w; ++i)
        {
            for (int j = y; j < y + h; ++j)
            {
                grid[i][j] = Tile{ TileTerrainType::ROCK };
            }
        }

        Tile zz = this[x][y];
        auto room = new Room(x, y, w, h);
        rooms.push_back(room);
        return room;
    }
    void Print()
    {
        std::ofstream outFile("out.txt");
        for (const auto& t : grid)
        {
            for (Tile z : t)
            {
                if (z.IsWall())
                    outFile << " ";
                else
                    outFile << "#";
            }
            outFile << '\n';

        }
    }
};