#include <iostream>

using namespace std;

/**
 * @Coding  : utf-8
 * @Date    : 2017-08-12 11:23:37
 * @Author  : ilib0x00000000
 * @Email   : ilib0x00000000@aliyun.com
 * @Link    : https://github.com/ilib0x00000000
 * @Version : 0.1
 */

/**
 * 友元：
 * 		友元函数
 * 		友元类
 *
 * 使用场景：
 * 		1. 运算符重载的某些场合需要使用友元
 * 		2. 两个类要共享数据的时候
 *
 * 友元函数：
 *  1. 加关键字: friend
 * 	2. 在类中定义的位置没有要求，private/public/protected都一样
 * 	3. 如果要访问private成员，需要对象做参数
 * 	4. 如果只是访问static、全局变量，则不需要对象作为参数
 */

class Demo
{
private:
	int a;
	int b;
public:
	Demo();
	Demo(int a, int b);
	Demo(Demo& d);
	~Demo();
protected:
	friend void print_class_demo(Demo& d)
	{
		cout << "Class Demo 的成员a是： " << d.a << endl;
		cout << "Class Demo 的成员b是： " << d.b << endl;
	}
};


int main(int argc, char const *argv[])
{
	Demo d(10, 20);

	print_class_demo(d);

	system("pause");
	return 0;
}


Demo::Demo()
{
	this->a = 0;
	this->b = 0;
}

Demo::Demo(int a, int b)
{
	this->a = a;
	this->b = b;
}

Demo::Demo(Demo& d)
{
	this->a = d.a;
	this->b = d.b;
}

Demo::~Demo()
{
	cout << "析构函数" << endl;
}