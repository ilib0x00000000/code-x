#include <iostream>

using namespace std;

/**
* @Coding  : utf-8
* @Date    : 2017-08-07 15:03:33
* @Author  : ilib0x00000000
* @Email   : ilib0x00000000@aliyun.com
* @Link    : https://github.com/ilib0x00000000
* @Version : 0.1
*/

/*
 *函数指针有2种定义方法：
 * 1. 定义一个函数类型，升阶成为函数指针
 * 2. 定义一个函数指针类型
*/

int test(char *p);
int test(int a, double b);
int test(int a, int b);


// 1
typedef int (func_type)(int, double);    // 定义一个类型，该类型是参数为int ,double,返回值为int的函数类型


// 2
typedef int(*func_type_p)(int, double);  // 定义一个类型，该类型是一个指针，指向参数为int,double,返回值为int的函数

void main()
{
	func_type * fp = NULL;   // 定义一个函数指针
	func_type_p fps = NULL;

	fps = test;
	fps(100, 200);   // 这里的函数指针指向的函数参数是固定的类型 int double，传递别的类型参数，就会报错

	fps = &test;
	fps(1, 2);



	system("pause");
	return;
}


int test(char *p)
{
	cout << "参数值是： " << p << endl;
	return 0;
}

int test(int a, double b)
{
	cout << "参数a的值是： " << a << endl;
	cout << "参数b的值是： " << b << endl;
	return 0;
}

int test(int a, int b) 
{
	cout << "参数a的值是： " << a << endl;
	cout << "参数b的值是： " << b << endl;
	return 0;
}
