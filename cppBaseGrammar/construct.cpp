#include <iostream>

using namespace std;

/**
 * @Coding  : utf-8
 * @Date    : 2017-08-09 08:04:40
 * @Author  : ilib0x00000000
 * @Email   : ilib0x00000000@aliyun.com
 * @Link    : https://github.com/ilib0x00000000
 * @Version : 0.1
 */

/**
 * 构造函数与析构函数:
 * 		都没有返回值
 * 		析构函数没有参数
 *
 * 构造函数有3种：
 * 		1. 无参构造函数
 * 		2. 带参构造函数
 * 		3. 拷贝构造函数
 *
 * 析构函数只有1种：
 * 		~ClassName(){....}
 */

class Demo
{
public:
	Demo();               // 无参构造函数
	Demo(int a, int b);   // 带参构造函数
	Demo(Demo &d);        // 拷贝构造函数

	~Demo();   // 析构函数
private:
	int m_a;
	int m_b;
};


void objplay(void)
{
	Demo d1;                 // 输出：调用了无参构造函数
	Demo d2(999, 888);       // 输出：调用了带参构造函数
	Demo d3 = Demo(10, 20);  // 输出：调用了带参构造函数  ------>  Demo d3(10, 20);
	Demo d4 = d3;            // 输出：调用了拷贝构造函数
	Demo d5;                 // 输出：调用了无参构造函数

	d5 = d3;
	/**
	 * 结论：
	 * 		用一个对象初始化和赋值给另一个对象，调用的构造方法是不同的
	 */
}


int main(int argc, char const *argv[])
{

	objplay();

	system("pause");
	return 0;
}


Demo::Demo()
{
	m_a = 0;
	m_b = 0;
	cout << "调用了无参构造函数" << endl;
}

Demo::Demo(int a, int b)
{
	m_a = a;
	m_b = b;
	cout << "调用了带参构造函数" << endl;
}

Demo::Demo(Demo &d)
{
	m_a = d.m_a;
	m_b = d.m_b;
	cout << "调用了拷贝构造函数" << endl;
}

Demo::~Demo()
{
	cout << "调用了析构函数" << endl;
}
