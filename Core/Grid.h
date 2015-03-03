#include <array>
#include <boost/multi_array.hpp>
template <class T>
class Grid
{
    boost::multi_array<T> mData;
public:
    typedef std::array<T, Y> Column;
    Grid(int x, int y)
    {
        mData.

    }
    Column& operator[] (std::size_t index)
    {
        return mData[index];
    }
    const Column& operator[] (std::size_t index) const
    {
        return mData[index]
    }
private:


};