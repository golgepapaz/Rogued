// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Bsp.h"
int _tmain(int argc, _TCHAR* argv[])
{
    auto fg = BSPTree(0, 0, 200, 200);
    fg.DivideRecursively(2, 10, 10, 0.5);
    int a = 0;
}

