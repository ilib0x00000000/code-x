#include <iostream>

using namespace std;

/**
 * @Coding  : utf-8
 * @Date    : 2017-08-09 17:06:12
 * @Author  : ilib0x00000000
 * @Email   : ilib0x00000000@aliyun.com
 * @Link    : https://github.com/ilib0x00000000
 * @Version : 0.1
 */


class Demo
{
private:
	int a;
	int b;

public:
	Demo();
	Demo(int _a, int _b);
	Demo(Demo& d);
	~Demo();
	int get_a(void);
	int get_b(void);
};


/**
 * 拷贝构造调用6种时机
 * 1. 使用一个对象初始化另一个对象
 * 2. 使用一个对象变量初始化另一个对象
 * 3. 形参是一个对象，调用函数时传递一个对象
 * 4. 返回一个对象，没有对象去接
 * 5. 返回一个对象，初始化一个对象
 * 6. 返回一个对象，赋值给一个对象
 */


void call_copy_1(void)
{ 
	Demo d1(1, 2);  // 调用了带参构造函数
	Demo d2(d1);    // 调用了拷贝构造函数
}

void call_copy_2(void)
{
	Demo d1(3, 4);  // 调用了带参构造函数

	Demo d2 = d1;   // 调用了拷贝构造函数

	Demo d3(5, 6);  // 调用了带参构造函数
	Demo d4;        // 调用了无参构造函数

	d4 = d3;
}

void func(Demo d)
{
	cout << "a的值是： " << d.get_a() << endl;
	cout << "b的值是： " << d.get_b() << endl;
}

void call_copy_3(void)
{
	Demo d1(7, 8);    // 调用了带参构造函数
	func(d1);  
	/*
	调用了拷贝构造函数
	a的值是：7
	b的值是：8
	*/
}

Demo generate(void)
{
	Demo d(9, 10);   
	return d;
	/*
	这里可以把对象类比成基本类型int
	1. 创建一个栈对象a
	2. 将a复制一份到寄存器中
	3. 返回寄存器变量

	同理：
	1. 创建一个对象d，调用了带参构造函数
	2. 将d复制一份到寄存器中，调用了拷贝构造函数
	3. d生命周期结束，调用析构函数
	4. 寄存器对象生命周期结束， 调用析构函数
	*/
}

void call_copy_4(void)
{
	generate();
	/*
	调用了带参构造函数
	调用了拷贝构造函数

	调用了析构函数
	调用了析构函数
	*/
}


void call_copy_5(void)
{
	Demo d = generate();   // 同call_copy_4()
}

void call_copy_6(void)
{
	Demo d;

	d = generate();
	/*
	调用了无参构造函数
	调用了带参构造函数
	调用了拷贝构造函数
	9   10  调用了析构函数
	19   20  调用了析构函数
	19   20  调用了析构函数
	*/
}


void main()
{
	call_copy_1();
	call_copy_2();
	call_copy_3();
	call_copy_4();
	call_copy_5();
	call_copy_6();

	system("pause");
}


Demo::Demo()
{
	a = 0;
	b = 0;
	cout << "调用了无参构造函数" << endl;
}


Demo::Demo(int _a, int _b)
{
	a = _a;
	b = _b;
	cout << "调用了带参构造函数" << endl;
}

Demo::Demo(Demo &d)
{
	a = d.a + 10;
	b = d.b + 10;
	cout << "调用了拷贝构造函数" << endl;
}


Demo::~Demo()
{
	cout << a << "   " << b << "  调用了析构函数" << endl;
}


int Demo::get_a(void)
{
	return a;
}

int Demo::get_b(void)
{
	return b;
}
