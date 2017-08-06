#include <iostream>

using namespace std;

/**
* @Coding  : utf-8
* @Date    : 2017-08-06 11:13:24
* @Author  : ilib0x00000000
* @Email   : ilib0x00000000@aliyun.com
* @Link    : https://github.com/ilib0x00000000
* @Version : 0.1
*/


/**
* 默认参数-占位参数
*
* 默认参数的位置必须是在最右边
* 占位参数的函数，如果不给占位参数赋默认值，则调用的时候，必须传递等量的参数
*
* 在VS2015中，如果函数中使用了默认参数，则在函数声明中，不能给默认值赋值
*             如果函数中使用了占位参数，同样不能出现赋值
*
* 使用默认参数和占位参数时，需要注意：把函数声明写在调用函数之前
*
* 结论：如果仅使用占位参数，形参有几个，实参就要传递几个
*/

void with_default(int a, int b, int c, int d);
void with_placeholder(int a, int b, int);
void with_default_placeholser(int a, int b, int c, int);

void with_default(int a, int b, int c = 3, int d = 4)
{
	cout << "a的值是： " << a << endl;
	cout << "b的值是： " << b << endl;
	cout << "c的值是： " << c << endl;
	cout << "d的值是： " << d << endl;
}

void with_default_placeholser(int a, int b, int c = 20, int = 1000)
{
	/**
	* 既带默认参数的，又带占位参数的函数
	*/
	cout << "a的值是：" << a << endl;
	cout << "b的值是：" << b << endl;
	cout << "c的值是：" << c << endl;
}



void with_placeholder(int a, int b, int)
{
	cout << "使用占位符函数：  " << endl;
	cout << "a的值是： " << a << endl;
	cout << "b的值是： " << b << endl;
}


// void tprint(int x=10);
void tprint(int x = 10)
{
	printf("%d\n", x);
}

int main(int argc, char const *argv[])
{
	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;

	tprint();
	tprint(100);

	with_default(10, 20);

	with_placeholder(0, 0, 0);

	with_default_placeholser(1, 1);
	with_default_placeholser(999, 999, 999);
	with_default_placeholser(8, 88, 888, 8888);

	with_placeholder(10, 20, 30);  // 这里使用了占位参数，必须传递等量的参数

	system("pause");
	return 0;
}