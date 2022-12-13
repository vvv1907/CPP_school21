#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
	Fixed const _x;
	Fixed const _y;

public:
	Point();
	Point(const Point &copy);
	Point(const float x, const float y);

	~Point();

	Point&	operator= (const Point &assign);

	Fixed const getX() const;
	Fixed const getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
