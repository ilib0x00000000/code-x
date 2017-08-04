#include <iostream>

using namespace std;

/**
 * C++编译器在C的基础上优化升级了部分
 *
 * 1. C中的定义语句必须在执行语句前面，C++中不是必须
 * 2. register变量在C中不能&，但是在C++中可以，因为C++编译器检测到对register变量的&，就将其转换成普通变量了，取消了register特性
 * 3. C++中不可以重复定义某个变量，但是VC中可以
 * 4. C语言中struct声明的类型，在创建变量时，需要带上struct关键字，但是C++可以不带
 * 5. C++中的三目运算符表达式可以做左值，但C语言中不行
 */

struct Usertype{
	char *name;
	char sex;
	int age;
};


void test(register int tm);

int main(int argc, char const *argv[])
{
	int loal = 10;
	cout << "loal的值是： " << loal << endl;

	int xma = 12;
	cout << "xma的值是： " << xma << endl;

	for(int i = 0; i < 10000; i++)
	{
		/**
		 * 在C++中，编译器检测到多次重复使用的变量，会自动将其转换成register变量
		 */
		;
	}


	test(loal);

	/**
	 * 在C语言中，这的定义必须是： struct Usertype xxx;
	 */
	Usertype user;
	user.name = "ilib0x00000000";
	user.sex = 'f';
	user.age = 18;


	int a = 10;
	int b = 20;
	(a > b ? a : b) = 1000;    // 将a和b中较大的赋值为1000
	cout << "a和b中较大的值是： " << b << endl;
	
	return 0;
}


void test(register int tm)
{
	/**
	 * 在C语言中对register变量取地址是会报错的，但是在C++中是合法的
	 * 因为C++会自动取消该变量的register特性
	 */
	cout << "tm的地址是： " << &tm << endl;

	return ;
}

/**
 * 在C语言中：
 *
 * int var;
 * int var = 100;
 * 这样定义是合法的，且输出其值是100
 *
 * int var = 100;
 * int var;
 * 这样的定义也是合法的，且其输出值还是100
 *
 * 但是以上的定义在C++中均是错误的
 */