// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Bsp.h"
#include "LevelGenerator.h"
int _tmain(int argc, _TCHAR* argv[])
{

    BSPLevelGenerator gen;
    DungeonLevel* level = gen.GenerateLevel(100, 100);
    level->Print();
}

