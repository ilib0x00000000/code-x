#include <iostream>

using namespace std;

/**
 * @Coding  : utf-8
 * @Date    : 2017-08-10 12:03:28
 * @Author  : ilib0x00000000
 * @Email   : ilib0x00000000@aliyun.com
 * @Link    : https://github.com/ilib0x00000000
 * @Version : 0.1
 */

/**
 * 对象初始化列表
 * 有两个类：
 * 		1. 类1没有无参构造函数（默认构造函数）
 * 		2. 类2属性包含类1
 *
 * 这样在实例化类2的时候，如果不显示实例化类1，则编译器会报错，因为类1没有默认构造函数，编译器不知道怎么实例化类1
 */

class ObjectsA
{
private:
	int a;
public:
	ObjectsA(int _a);
	~ObjectsA();
};

class ObjectsB
{
private:
	int a;
	int b;
	ObjectsA a1;
	ObjectsA a2;
public:
	ObjectsB();
	ObjectsB(int _a, int _b);
	ObjectsB(int _a, int _b, int m, int n);
	~ObjectsB();
};


void objplay(void)
{
	ObjectsB ob1;

	ObjectsB ob2 = ObjectsB(111, 222);
	
	ObjectsB ob3 = ObjectsB(123, 456, 789, 110);
	/**
	 * 这里先调用a1的构造函数
	 * 再调用a2构造函数
	 * 最后是ObjectB的构造函数
	 *
	 * 调用类ObjectA的构造函数时，是以B中的属性顺序来调用的，与构造方法中的顺序无关
	 * 即先定义属性a1，后定义属性a2，
	 * 所以调用顺序永远都是a1在前，a2在后
	 */
}


int main(int argc, char const *argv[])
{
	objplay();

	system("pause");
	return 0;
}

ObjectsA::ObjectsA(int _a)
{
	a = _a;
	cout << "调用了A的构造方法  " << a << endl;
}

ObjectsA::~ObjectsA()
{
	cout << "调用了A的析构函数" << a << endl;
}


/**
 * 如果在构造函数定义时，后面不加上属性a1,a2的初始化，则编译器不知道怎么初始化a1,a2，因为ObjectA没有默认构造函数，
 * 则编译器报错
 */
ObjectsB::ObjectsB() : a1(0), a2(0)
{
	a = 0;
	b = 0;
	cout << "调用了B的构造函数 " << a << "  " << b << endl;
}

ObjectsB::ObjectsB(int _a, int _b) : a2(0), a1(0)
{
	a = _a;
	b = _b;
	cout << "调用了B的带参数构造函数 " << a << "  " << b << endl;
}

ObjectsB::ObjectsB(int _a, int _b, int m, int n) : a2(n), a1(m)  
{
	a = _a;
	b = _b;
}



ObjectsB::~ObjectsB()
{
	cout << "B析构函数" << a << "   " << b << endl;
}
