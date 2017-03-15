#include "day4Point.h"
#include "day4Circle.h"



void Circle::setRadius(double r)
{
	/**
	 * 设置圆的半径
	 */
	radius = r;
}

void Circle::setCenter(Point &p)
{
	/**
	 * 设置圆的圆心
	 */
	center = p;
}

double Circle::getRadius(void)
{
	/**
	 * 返回圆的半径
	 */
	return radius;
}

Point Circle::getCenter(void)
{
	/**
	 * 返回圆的圆心对象
	 */
	return center;
}

