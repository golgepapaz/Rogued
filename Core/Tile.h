#pragma once

enum class TileTerrainType
{
    ROCK_WALL,
    DIRT_WALL,
    WALL_END = DIRT_WALL,
    ROCK,
    DIRT,
    LAVA,
    SHALLOW_WATER,
    DEEP_WATER
};
struct Tile
{
    TileTerrainType mType;
    Tile(TileTerrainType  type = TileTerrainType::ROCK_WALL) : mType(type)
    {}  
    bool IsWall()
    {
        return mType >= TileTerrainType::ROCK_WALL && mType <= TileTerrainType::WALL_END;
    }
};