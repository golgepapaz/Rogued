// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Bsp.h"
int _tmain(int argc, _TCHAR* argv[])
{
    auto fg = BSPTree(0, 0, 100, 100);
    fg.DivideRecursively(3, 10, 10, 0.5);
    BSPPrintVisitor vis;
    fg.TraverseBFS(vis);
}

