#include <iostream>

using namespace std;

/**
 * @Coding  : utf-8
 * @Date    : 2017-08-11 10:48:27
 * @Author  : ilib0x00000000
 * @Email   : ilib0x00000000@aliyun.com
 * @Link    : https://github.com/ilib0x00000000
 * @Version : 0.1
 */

/**
 * static在类中修饰的有2个：
 * 		1. 成员变量
 * 		2. 成员函数
 *
 * 如果修饰的是成员变量，则所有对象共享该变量，即，一个对象修改了该变量，对所有对象都可见
 * 如果修饰的是成员函数，则函数中只能使用静态成员，不能使用普通成员变量和方法
 *
 * 注意：静态成员变量初始化的时候可以使用类::
 */

class Demo
{
private:
	int a;
	int b;
	static int s;
public:
	void setab(int _a, int _b);
	void print_s(void);
	void add_s(int x);   // 函数声明中不能加默认参数，只能在函数定义中加

	static void print_static(char *name);
};

// 初始化静态变量
int Demo::s = 10;

int main(int argc, char const *argv[])
{
	Demo d0;
	Demo d1;
	Demo d2;

	d0.print_s();
	d1.print_s();
	d2.print_s();

	d1.add_s(2);

	d0.print_s();
	d1.print_s();
	d2.print_s();

	Demo::print_static("Demo类");    // 静态方法的调用方法
	d0.print_static("d0对象");
	d1.print_static("d1对象");
	d2.print_static("d2对象");

	system("pause");
	return 0;
}

void Demo::setab(int _a, int _b)
{
	a = _a;
	b = _b;
}

void Demo::print_s(void)
{
	cout << "静态成员变量的值是： " << s << endl;
}

void Demo::add_s(int x=1)
{
	s += x;
}

 
void Demo::print_static(char *name)    // 静态方法的定义实现
{ 
	/**
	 * 静态方法中不能出现：普通成员变量和普通成员函数
	 */
	cout << name << "  中调用了静态方法 " << s << endl;
}
