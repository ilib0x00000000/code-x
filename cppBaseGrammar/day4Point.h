# pragma once
/**
 * 相当于
 * #ifndef day4Point_H
 * #define day4Point_H
 *
 * #endif
 */


class Point
{
private:
	int x;   // 横坐标
	int y;   // 纵坐标

public:
	void   setX(int tx);  // 设置点的横坐标
	void   setY(int ty);  // 设置点的纵坐标
	void   setLocation(int tx, int ty);
	int    locX(void);   // 返回横坐标
	int    locY(void);   // 返回纵坐标
	double distance(Point& p); // 返回与指定点的距离
};

