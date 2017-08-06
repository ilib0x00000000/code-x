#include <iostream>

using namespace std;

/**
 * @Coding  : utf-8
 * @Date    : 2017-08-06 08:43:36
 * @Author  : ilib0x00000000
 * @Email   : ilib0x00000000@aliyun.com
 * @Link    : https://github.com/ilib0x00000000
 * @Version : 0.1
 */


/**
 * 常引用：
 * 1. 使用变量初始化
 * 2. 使用字面值常量初始化
 */

struct User
{
	char name[64];
	int  age;
};

void foo(const struct User &vip);

int main(int argc, char const *argv[])
{
	/**
	 * 使用变量初始化常引用
	 */
	int a = 10;
	const int &b = a;    // 实质是： const int * const b = &a;
	// b = 20;           // 这样赋值是错误的，常引用使得引用的值不能在修改


	/**
	 * 使用字面值常量初始化常引用
	 */
	// int &ra = 10;     // 这样的写法是错误的，字面值常量在代码区，不能&
	const int &rb = 10;  // 这样写能通过的原因是：C++编译器为字面值常量创建了一块内存，所以可以&


	User vip;

	strcpy(vip.name, "ilib0x00000000");
	vip.age = 18;

	foo(vip);


	system("pause");
	return 0;
}

void foo(const struct User &vip)
{
	cout << "用户名是： " << vip.name << endl;
	cout << "用户年龄是： " << vip.age << endl;

	// vip.age = 100;   // 常引用指向的值不能修改
}