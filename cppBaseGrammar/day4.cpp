#include <iostream>

#include "day4Point.h"
#include "day4Circle.h"

using namespace std;

/**
 * 面向对象编程
 *
 * 给一个圆的圆心坐标和半径
 * 输出另一个点是否在圆的内部
 */


int main(int argc, char const *argv[])
{
	double distance = 0;
	Point pl;  // 给的点对象
	Circle c;  // 给的圆对象
	Point cc;  // 圆心对象

	pl.setLocation(6, 7);  // 随机点的坐标
	cc.setLocation(2, 2);  // 圆心的坐标

	c.setRadius(6);
	c.setCenter(cc);

	distance = c.getCenter().distance(pl); // 圆心与随机点的距离

	if(distance < c.getRadius())
	{
		cout << "点在圆的内部" << endl;
	}else
	{
		cout << "点不在圆的内部" << endl;
	}

	return 0;
}