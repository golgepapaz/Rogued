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
    TileTerrainType type;
    bool IsWall()
    {
        return type >= TileTerrainType::ROCK_WALL && type <= TileTerrainType::WALL_END;
    }
};