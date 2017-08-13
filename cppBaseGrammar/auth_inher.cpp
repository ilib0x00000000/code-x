#include <iostream>

using namespace std;

/**
 * @Coding  : utf-8
 * @Date    : 2017-08-13 11:40:29
 * @Author  : ilib0x00000000
 * @Email   : ilib0x00000000@aliyun.com
 * @Link    : https://github.com/ilib0x00000000
 * @Version : 0.1
 */

/**
 * 继承时有3种继承权限修饰符：public/private/protected
 *
 * 如果是public继承：
 * 		相当于在子类中增加：父类中的public成员函数，public成员变量
 * 		                  父类中的protected成员函数，protected成员变量
 * 		                  父类中的private成员函数，private成员变量
 *
 * 如果是private继承：
 * 		相当于在子类中增加： 父类中所有的成员函数和成员变量，但是都会变成private属性
 *
 * 如果是protected继承：
 * 		相当于在子类中增加：protected：父类中的public成员函数和成员变量
 * 						  protected: 父类中的protected成员函数和成员变量
 * 						  private: 父类中的private成员函数和成员变量
 */

class Demo
{
private:
	int a;
protected:
	int b;
public:
	int c;
	Demo() { }
};

class ObjectA: public Demo
{
public:
	void print_base(void) const
	{
		// cout << "基类中a的值是： " << this->a << endl;
		cout << "基类中b的值是： " << this->b << endl;
		cout << "基类中c的值是： " << this->c << endl;
	}
};

class ObjectB: private Demo
{
public:
	ObjectB(){}
	~ObjectB(){}

	void print_base(void) const
	{
		// cout << "基类中a的值是： " << this->a << endl;
		cout << "基类中b的值是： " << this->b << endl;
		cout << "基类中c的值是： " << this->c << endl;		
	}
};


class ObjectC: protected Demo
{
public:
	ObjectC(){}
	~ObjectC(){}

	void print_base(void) const
	{
		// cout << "基类中a的值是： " << this->a << endl;
		cout << "基类中b的值是： " << this->b << endl;
		cout << "基类中c的值是： " << this->c << endl;		
	}
};


int main(int argc, char const *argv[])
{
	Demo d;
	cout << "基类中c的值是： " << d.c << endl;
	// cout << "基类中a的值是： " << d.a << endl;
	// cout << "基类中b的值是： " << d.b << endl;

	ObjectA oa;
	cout << "基类中c的值是： " << oa.c << endl;
	oa.print_base();
	// cout << "基类中a的值是： " << oa.a << endl;
	// cout << "基类中b的值是： " << oa.b << endl;

	ObjectB ob;
	ob.print_base();
	// cout << "基类中a的值是： " << ob.a << endl;
	// cout << "基类中b的值是： " << ob.b << endl;
	// cout << "基类中c的值是： " << ob.c << endl;

	ObjectC oc;
	oc.print_base();
	// cout << "基类中a的值是： " << oc.a << endl;
	// cout << "基类中b的值是： " << oc.b << endl;
	// cout << "基类中c的值是： " << oc.c << endl;


	system("pause");
	return 0;
}