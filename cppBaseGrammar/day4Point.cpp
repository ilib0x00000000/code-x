#include <cmath>

#include "day4Point.h"


void Point::setX(int tx)
{
	x = tx;
}

void Point::setY(int ty)
{
	y = ty;
}

void Point::setLocation(int tx, int ty)
{
	x = tx;
	y = ty;
}


int Point::locX(void)
{
	return x;
}

int Point::locY(void)
{
	return y;
}


double Point::distance(Point &p)
{
	int    px = 0;
	int    py = 0;
	double distance = 0;

	px = p.locX();
	py = p.locY();

	distance = sqrt((px-x)*(px-x) + (py-y)*(py-y));

	return distance;
}

