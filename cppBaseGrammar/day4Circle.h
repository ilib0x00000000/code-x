# pragma once
/**
 * 相当于
 * #ifndef Circle_H
 * #define Circle_H
 *
 * #endif
 */

#include "day4Point.h"


class Circle
{
	/**
	 * 圆的类定义
	 */
private:
	double radius;   // 半径
	Point  center;   // 圆心


public:
	void setRadius(double r);
	void setCenter(Point &p);
	double getRadius(void);
	Point getCenter(void);
};
