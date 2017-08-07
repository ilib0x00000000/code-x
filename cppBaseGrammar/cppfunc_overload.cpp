#include <iostream>

using namespace std;

/**
 * @Coding  : utf-8
 * @Date    : 2017-08-07 14:49:16
 * @Author  : ilib0x00000000
 * @Email   : ilib0x00000000@aliyun.com
 * @Link    : https://github.com/ilib0x00000000
 * @Version : 0.1
 */

void oltest(int a);
void oltest(char *p);
void oltest(int a, int b, int c);

/**
 * 注意：函数重载时，如果某个函数有默认参数，则函数重载时需要注意参数的设置
 * 因为在调用的时候存在二义性
 *
 * 如下：编译过不去，VS2015
 */

/*
void print_def(int a, int b, int c=0);
void print_def(int a, int b);
*/

int main(int argc, char const *argv[])
{
	oltest("参数： 这是一个字符串");
	oltest(999);
	oltest(1, 2, 3);

	system("pause");
	return 0;
}


void oltest(int a)
{
	cout << "a的值是： " << a << endl;
}

void oltest(char *p)
{
	cout << "在函数重载中 p: " << p << endl;
}

void oltest(int a, int b, int c)
{
	cout << "a的值是： " << a << endl;
	cout << "b的值是： " << b << endl;
	cout << "c的值是： " << c << endl;	
}

/*
void print_def(int a, int b)
{
	cout << "a的值是： " << a << "  b的值是： " << b << endl;
}

void print_def(int a, int b, int c=0)
{
	cout << "a的值是： " << a << "  b的值是： " << b << "  c的值是： " << c << endl;
}
*/