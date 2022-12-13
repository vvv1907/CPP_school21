#include "Point.hpp"

Point::Point(): _x(0), _y(0) {}

Point::Point(const Point &copy): _x(copy.getX()), _y(copy.getY()) {}

Point::Point(const float x, const float y): _x(x), _y(y) {}

Point::~Point() {}

Point&	Point::operator= (const Point &assign)
{
	(void)assign;
	return *this;
}

Fixed const Point::getX() const
{
	return _x;
}

Fixed const Point::getY() const
{
	return _y;
}
