#include <array>
#include <boost/multi_array.hpp>

class DungeonLevel
{
    boost::multi_array<Tile,2> mData;
public:

    DungeonLevel(int x, int y) :mData(boost::extents(x, y))
    {}
 };