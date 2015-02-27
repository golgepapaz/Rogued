
#include "Level.h"
#include "Grid.h"
#include "BSP.h"

int main()
{
    BSPTree sadf = BSPTree(0, 0, 200, 200);
    sadf.DivideRecursively(4, 6, 6, 0.5);

}