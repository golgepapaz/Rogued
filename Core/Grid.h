#include <array>
template <class T, int X, int Y>
class Grid
{
public:
    typedef std::array<T, Y> Column;
    Column& operator[] (std::size_t index)
    {
        return mData[index];
    }
    const Column& operator[] (std::size_t index) const
    {
        return mData[index]
    }
private:
    std::array<Column,X> mData;

};