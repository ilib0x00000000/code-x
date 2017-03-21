#include <iostream>


using namespace std;

/**
 * 继承中的构造函数与析构函数：
 * 1. 子类对象在创建时首先会调用父类的构造函数
 * 2. 父类构造函数执行结束后，执行子类的构造函数
 * 3. 当父类的构造函数有参数时，需要在子类的初始化列表中显示调用
 * 4. 析构函数的调用与构造函数相反
 *
 * 继承与组合混搭的情况下
 * 先调用父类（的父类的父类。。。）的构造函数，然后调用组合类的构造函数，再调用子类的构造函数。
 * 
 */

class Mixture
{
public:
	Mixture();
	Mixture(int a, int b);
	Mixture(const Mixture& nm);
	~Mixture();
private:
	int a;
	int b;
};


class Base
{
public:
	Base();
	Base(const char* cp);
	Base(const Base& nb);
	~Base();
private:
	char *strg;
};


class Extend: public Base
{
public:
	Extend(const char *cp);
	Extend(const Extend& ne);
	~Extend();
private:
	int value;
	Mixture ma;
	Mixture mb;
};

void objplay(void)
{
	//
	Extend ex("abcde");
}

int main(int argc, char const *argv[])
{
	objplay();
	return 0;
}


Base::Base()
{
	cout << "调用了基类的构造函数" << endl;
}
Base::Base(const char *cp)
{
	cout << "调用了基类的构造函数： " << cp << endl;
}
Base::Base(const Base& nb)
{
	cout << "调用了基类的拷贝构造函数：" << nb.strg << endl;
	this->strg = nb.strg;
}
Base::~Base()
{
	cout << "调用了基类的析构函数" << endl;
}



Extend::Extend(const char *cp): Base(cp), ma(10, 20), mb(888, 999)
{
	this->value = 0;
	cout << "调用了子类的构造函数" << endl;
}
Extend::Extend(const Extend& ne)
{
	this->value = ne.value;
	cout << "调用了子类的构造函数" << endl;
}
Extend::~Extend()
{
	cout << "调用了子类的析构函数" << endl;
}



Mixture::Mixture()
{
	cout << "调用混合类的无参构造函数" << endl;
}
Mixture::Mixture(int a, int b)
{
	this->a = a;
	this->b = b;
	cout << "调用混合类的带参构造函数" << endl;
}
Mixture::Mixture(const Mixture& nm)
{
	this->a = nm.a;
	this->b = nm.b;
	cout << "调用混合类的拷贝构造函数" << endl;
}
Mixture::~Mixture()
{
	cout << "调用混合类的析构函数" << endl;
}