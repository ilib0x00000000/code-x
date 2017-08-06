#include <iostream>

using namespace std;

/**
 * @Coding  : utf-8
 * @Date    : 2017-08-06 09:32:50
 * @Author  : ilib0x00000000
 * @Email   : ilib0x00000000@aliyun.com
 * @Link    : https://github.com/ilib0x00000000
 * @Version : 0.1
 */

/**
 * C++内联函数：
 * 1. 定义内联函数时使用关键字inline，并且是在函数体之前
 * 2. 内联函数是在编译时，接受编译器选择性替换
 * 3. 如果内联函数中有循环或者大量的判断语句，编译器会忽略内联请求
 * 4. 内联函数避免了普通函数的入栈，返回，跳转等。
 */

inline void print_time()
{
	cout << "新中国成立的时间是： 1949年10月1日" << endl;
}

inline void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int main(int argc, char const *argv[])
{
	int a = 10;
	int b = 20;

	cout << "a的值是： " << a << "   b的值是： " << b << endl;

	swap(&a, &b);
	/**
	 * 内联函数的实质是替换
	 * {
	 * 		int temp;
	 *
	 * 		temp = *a;
	 * 		*a = *b;
	 * 		*b = temp;
	 * }
	 */
	cout << "a的值是： " << a << "   b的值是： " << b << endl;
	

	print_time();
	/**
	 * 这里内联的实质就是直接替换
	 * {
	 * 		cout << "新中国成立的时间是： 1949年10月1日" << endl;
	 * }
	 */

	
	system("pause");
	return 0;
}