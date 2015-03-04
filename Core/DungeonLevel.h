
#pragma once
#include <boost/multi_array.hpp>
#include <fstream>
#include "Tile.h"



class DungeonLevel
{
    boost::multi_array<Tile,2> mData;
public:

    DungeonLevel(int x, int y): mData(boost::extents[x][y])
    {}
    auto operator[](std::size_t index) -> decltype(mData.operator[](index))
    {
        return mData[index];
    }
    void MakeRoom(int x, int y, int w, int h)
    {
        for (int i = x; i < x + w; ++i)
        {
            for (int j = y; j < y + h; ++j)
            {
                mData[i][j] = Tile{ TileTerrainType::ROCK };
            }
        }
    }
    void Print()
    {
        std::ofstream outFile("out.txt");
        for (auto& t : mData)
        {
            for (Tile& z : t)
            {
                if (z.IsWall())
                    outFile << "#";
                else
                    outFile << " ";
            }
            outFile << '\n';

        }
    }
 };