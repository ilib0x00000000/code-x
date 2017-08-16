#include <iostream>

using namespace std;

/**
 * @Coding  : utf-8
 * @Date    : 2017-08-16 09:02:13
 * @Author  : ilib0x00000000
 * @Email   : ilib0x00000000@aliyun.com
 * @Link    : https://github.com/ilib0x00000000
 * @Version : 0.1
 */


/**
 * 类型兼容性原则：
 * 		只能是定义一个父类类型指针，然后将子类对象或父类对象赋值给他。
 * 		只能是定义一个父类类型引用，然后将子类对象或父类对象赋值给他。
 * 		
 * 
 * 多态：
 * 		定义一个指针，如果定义指针的时候指明类型是父类，则不管是将父类还是子类对象赋值给该指针，通过该指针调用函数时，都是调用父类的函数。
 *
 *		但是子类的指针不能指向父类
 *
 * 多态语法：
 * 		在父类和子类重写的函数之前，加一个关键字virtual
 *
 * 多态使用：
 * 		在一个接口中，参数是父类指针（引用），在调用接口时只要传递父类的对象或者子类对象就可以根据对象调用不同的函数。
 *
 * 多态使用3要素：
 * 		1. 继承
 * 		2. 函数重写（virtual）
 * 		3. 父类指针（引用）做参数
 */

class Base
{
public:
	Base(int x=0)
	{
		this->a = x;
	}

	/**
	 * 父类中的函数被子类重写了，通过父类指针（引用）调用的函数，全是父类函数，如果希望能调用子类函数，则必须用virtual关键字修饰该函数
	 */
	virtual void print(void)
	{
		cout << "父类函数调用" << endl;
	}
private:
	int a;
};


class Demo: public Base
{
public:
	Demo(int x, int y=0): Base(y)
	{
		this->b = x;
	}
	virtual void print(void)
	{
		cout << "子类函数调用" << endl;
	}
private:
	int b;
};

void callable_point(Base *pb)
{
	pb->print();
}

void callable_referce(Base &pr)
{
	pr.print();
}


int main(int argc, char const *argv[])
{
	Base *pb = NULL;

	Base b(999);     // 父类对象
	Demo d(10, 20);  // 子类对象

	pb = &b;         // 指针指向父类对象
	pb->print();

	pb = &d;         // 指针指向子类对象
	pb->print();


	Demo *pd = NULL;  // 顶一个指向子类对象的指针

	Base bb(111111);
	// pd = &bb;       // 错误，子类指针不能指向父类

	{
		Base b(9999);
		Demo d(10, 20);

		callable_point(&b);
		callable_point(&d);
	}

	{
		Base b(9999);
		Demo d(10, 20);

		callable_referce(b);
		callable_referce(d);
	}


	system("pause");
	return 0;
}