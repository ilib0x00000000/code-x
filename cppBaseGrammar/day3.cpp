#include <iostream>


using namespace std;


/**
 * 引用：
 * 函数返回值是引用（基本类型的引用）
 * 函数返回值是引用（复杂类型的引用）
 *
 * 当函数的返回值是引用时，若返回栈变量，不能成为其他引用的初始值，不能作为左值
 * 若函数的返回值是引用，且是全局变量/静态变量的引用，则无上述限制
 *
 * 如果将函数的返回值赋值给基础类型的左值，相当于返回的是栈变量的副本。
 * 如果将函数的返回值赋值给引用类型的左值，相当于返回地址（栈变量的地址）
 *
 * 引用的本质就是：指针常量。
 * 		1. 引用一定义就要初始化------类似const
 * 		2. 引用的大小与指针一样
 *
 * 引用不完全等同于指针，可以看做是地址，但是是经过编译器处理的。引用不占用空间。
 *
 * 引用使用：
 * 		******************************
 * 		* 函数的返回值是引用时一定要谨慎 *
 * 		******************************
 */

int& rtmrefence(void)
{
	int loc;

	loc = 10;

	return loc;
}


void swap(int &a, int &b)
{
	/**
	 * 使用引用交换两个数的值
	 */
	int temp;

	temp = a;
	a = b;
	b = temp;

	return ;
}



int main(int argc, char const *argv[])
{
	int a = 0;
	int &ra = a;
	int *pa = &a;
	/**
	 * 引用并不分配内存
	 * 上面的变量定义只分配了一个int空间和int *空间。
	 * 引用是变量a的别名。
	 */

	char c = 'a';
	char &cc = c;
	char *pc = &c;

	cout << "cc的大小是： " << sizeof(cc) << endl;  // cc ==> *cc
	cout << "pc的大小是： " << sizeof(pc) << endl;

	cout << "ra的大小是： " << sizeof(ra) << endl;  // ra ==> *ra
	cout << "pa的大小是： " << sizeof(pa) << endl;

	a = rtmrefence();
	/**
	 * 由于左值是一个基本类型，所以函数会返回栈变量的副本
	 */

	cout << "a的值是： " << a << endl;

	int& b = rtmrefence();
	/**
	 * 由于左值是一个引用类型，函数返回栈变量的地址
	 */

	cout << "b的值是： " << b << endl;

	int t1 = 100;
	int t2 = 999;

	cout << "t1的值是： " << t1 << "   t2的值是： " << t2 << endl;

	swap(t1, t2);

	cout << "t1的值是： " << t1 << "   t2的值是： " << t2 << endl;

	return 0;
}