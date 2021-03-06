#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point
{
private:
	Fixed const _x;
	Fixed const _y;

public:
	Point(void);
	Point(float const x, float const y);
	Point(Point const &other);
	~Point(void);

	Point &operator=(Point const &rhs);

	Fixed getX(void) const;
	Fixed getY(void) const;
};

std::ostream &operator<<(std::ostream &out, Point const &var);

#endif
