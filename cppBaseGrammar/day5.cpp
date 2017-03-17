#include <iostream>

using namespace std;


/**
 * 类与对象
 *
 * 构造函数：没有类型，即没有返回值
 * 构造函数细分可以分成4类：
 * 		无参构造函数
 * 		带参构造函数
 * 		拷贝构造函数
 * 		默认构造函数
 *
 * 析构函数：无参无返回值
 *
 * struct和class的区别：
 * 在class中，如果某个成员没有权限修饰符修饰，则默认为private
 * 在struct中，如果某个成员没有权限修饰符修饰，则默认为public
 *
 * 构造函数使用：
 * 1. 当类中没有定义任何一个构造函数，C++编译器会提供默认无参构造函数和默认拷贝构造函数
 * 2. 当类中定义了带参构造函数或者拷贝构造函数，C++编译器不会提供无参构造函数
 * 3. 默认拷贝构造函数成员简单赋值
 */

class Clock
{
private:
	int hour;
	int minute;
	int second;

public:
	/**
	 * [getTime description]
	 * @param h [小时]
	 * @param m [分钟]
	 * @param s [秒数]
	 */
	void getTime(int& h, int& m, int& s);
	void setTime(int h, int m, int s);


	/**
	 * [equalTime description]
	 * @param  nc [另一个Clock对象]
	 * @return    [如果两个对象表示的时间点是一样的，返回1，否则，返回0]
	 */
	int equalTime(const Clock& nc);

	Clock();
	Clock(int h, int m, int s);
	Clock(const Clock &nc);

	~Clock();
};


int main(int argc, char const *argv[])
{
	Clock c;

	/**
	 * 每个对象只对成员变量分配存储空间
	 */
	cout << "sizeof(class Clock) = " << sizeof(c) << endl;

	return 0;
}

/**
 * 定义构造函数
 */
Clock::Clock()
{
	hour = 0;
	minute = 0;
	second = 0;
}

Clock::Clock(int h, int m, int s)
{
	hour = h;
	minute = m;
	second = s;
}

Clock::Clock(const Clock& nc)
{
	hour = nc.hour;
	minute = nc.minute;
	second = nc.second;
}


/**
 * 定义析构函数
 */
Clock::~Clock()
{
	cout << "这里自动调用了析构函数" << endl;
}


/**
 * 定义成员函数
 */
void Clock::getTime(int& h, int& m, int& s)
{
	h = hour;
	m = minute;
	s = second;
}


void Clock::setTime(int h, int m, int s)
{
	hour = h;
	minute = m;
	second = s;
}

int Clock::equalTime(const Clock& nc)
{
	if(nc.hour==hour && nc.minute==minute && nc.second==second)
	{
		return 1;
	}

	return 0;
}