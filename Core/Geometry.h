#pragma once

struct Coord
{
    int x;
    int y;
    Coord(int x = 0, int y = 0) : x(x), y(y)
    {}
};

class Rect
{
public:
    Rect() {}
    Rect(int left, int top, int width, int height) :
        x(left),
        y(top),
        w(width),
        h(height)
    {}
    int Left() const { return x; }
    int Top() const { return y; }
    int Right() const { return x + w; }
    int Bottom() const { return y + h; }
    Coord TopLeft() const { return Coord{ x, y };}
    Coord TopRight() const { return Coord{ x + w, y }; }
    Coord BottomLeft() const { return Coord{ x, y + h }; }
    Coord BottomRight() const { return Coord{ x + w, y + h }; }

    
    bool Intersects(const Rect& rhs) const
    {
        if (*this == rhs)
            return true;
        return (Left() < rhs.Right() &&
                Right() > rhs.Left() &&
                Top() < rhs.Bottom() &&
                Bottom() > rhs.Top());
    }
    friend bool operator==(const Rect& lhs, const Rect& rhs);
    friend bool operator!=(const Rect& lhs, const Rect& rhs);

private:
    int x = 0;
    int y = 0;
    int w = 0;
    int h = 0;
};

bool operator==(const Rect& lhs, const Rect& rhs)
{
    return (lhs.x == rhs.x &&
            lhs.y == rhs.y &&
            lhs.w == rhs.w &&
            lhs.h == rhs.h);
}
bool operator!=(const Rect& lhs, const Rect& rhs)
{
    return !(lhs == rhs);
}
