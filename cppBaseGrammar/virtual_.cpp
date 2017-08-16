#include <iostream>

using namespace std;

/**
 * @Coding  : utf-8
 * @Date    : 2017-08-16 08:33:30
 * @Author  : ilib0x00000000
 * @Email   : ilib0x00000000@aliyun.com
 * @Link    : https://github.com/ilib0x00000000
 * @Version : 0.1
 */


/**
 * 多继承时会导致二义性，所以出现了虚继承
 * 
 * 虚继承：
 *
 * 				class A
 * 	     virtual/     \ virtual
 * 			   /       \
 * 		    classB   classC
 * 		       \       /
 * 		    	\     /
 * 		    	class D
 *
 * 虚继承只能解决如上继承方式
 *
 * 
 * 像如下继承方式
 * 			classA   classB
 * 			   \       /
 * 			    \     /
 * 			     classC
 * 继承时带来的缺陷，虚继承无法解决
 */

class Base
{
public:
	int a;
};


class ObjectA: public Base
{
public:
	ObjectA(int x=0)
	{
		this->b1 = x;
	}
	void print_A(void)
	{
		cout << "b1的值是： " << this->b1 << endl;
	}
private:
	int b1;
};

class ObjectB: public Base
{
public:
	ObjectB(int x=0)
	{
		this->b2 = x;
	}
	void print_B(void)
	{
		cout << "b2的值是： " << this->b2 << endl;
	}
private:
	int b2;
};


class Demo: public ObjectA, public ObjectB
{
public:
	Demo(int x=0, int y=0): ObjectA(x), ObjectB(y)              // 父类没有提供默认的构造函数时，子类构造函数中必须显示提供
	{}
};


class VobjectA: virtual public Base 
{};

class VobjectB: virtual public Base
{};

class Test: public VobjectA, public VobjectB
{};


int main(int argc, char const *argv[])
{
	cout << "Base的大小是： " << sizeof(Base) << endl;              // 4
 	cout << "ObjectA的大小是： " << sizeof(ObjectA) << endl;        // 4
	cout << "ObjectB的大小是： " << sizeof(ObjectB) << endl;        // 4
	cout << "Demo的大小是： " << sizeof(Demo) << endl;              // 8

	Demo d(500);
	// d.a = 100;               // 这里编译不过去
	d.ObjectA::a = 200;
	d.ObjectB::a = 300;
	d.print_A();
	d.print_B();


	/**
	 * 虚继承时，子类会自动添加一些属性
	 */
	cout << "VobjectA的大小是： " << sizeof(VobjectA) << endl;      // 8              
	cout << "VobjectB的大小是： " << sizeof(VobjectB) << endl;      // 8
	cout << "Test的大小是： " << sizeof(Test) << endl;              // 12


	/**
	 * 正常编译
	 */
	Test t;
	t.a = 999;

	system("pause");
	return 0;
}