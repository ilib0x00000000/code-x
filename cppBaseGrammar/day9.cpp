#include <iostream>
 
using namespace std;
 
/**
 * @Coding  : utf-8
 * @Date    : 2017-03-20 16:01:34
 * @Author  : ilib0x00000000 
 * @Email   : yinghaozhg@qq.com
 * @Link    : http://github.com/ilib0x00000000                              
 * @Version : 0.1
 *
 * 继承时，权限修饰符的使用，子类可以使用3种修饰符继承父类的成员
 * 继承时，父类的成员是否能使用，分为两种情况：
 * 		1. 在子类的内部
 * 		2. 在子类的外部----> 根据子类在继承时使用什么权限修饰符继承父类 -----> 父类中的成员被什么权限修饰符修饰
 *
 * 从父类继承来的成员，在子类中使用分两种情况：
 * 	1. 在子类内部使用：
 * 		只要父类中不是定义为private的成员，子类内部中都可以使用
 * 	2. 在子类外部使用
 * 		子类继承父类时，要使用public继承，且在父类中不是private
 */ 

class Parent
{
public:
	int a;
protected:
	int b;
private:
	int c;
};

// 继承时的权限影响的是成员在子类的外部是否能使用
class Child1: public Parent
{
public:
	void setMemValue(int a, int b, int c=0)
	{
		this->a = a;
		this->b = b;
		// this->c = c;  // 因为成员c在父类中是私有成员，所以子类不能访问
	}
	void printMem(void)
	{
		cout << "a的值是： " << this->a << endl;
		cout << "b的值是： " << this->b << endl;
		// cout << "c的值是： " << this->c << endl; // 因为成员c在父类中是私有成员，所以子类不能访问
	}
	Child1()
	{ this->a=0; this->b=0; }
};


class Child2: private Parent
{
	/**
	 * private继承将父类中的public/private/protected全部变成private属性
	 */
public:
	void setMemValue(int a, int b, int c=0)
	{
		this->a = a;
		this->b = b;
		// this->c = c;  // 因为成员c在父类中是私有成员，所以子类不能访问
	}
	void printMem(void)
	{
		cout << "a的值是： " << this->a << endl;
		cout << "b的值是： " << this->b << endl;
		// cout << "c的值是： " << this->c << endl; // 因为成员c在父类中是私有成员，所以子类不能访问
	}	
	Child2()
	{ this->a=0; this->b=0; }
};

class Child3: protected Parent
{
	/**
	 * protected修饰符继承父类，将父类的成员public/protected转为protected
	 */
public:
	void setMemValue(int a, int b, int c=0)
	{
		this->a = a;
		this->b = b;
		// this->c = c;  // 因为成员c在父类中是私有成员，所以子类不能访问
	}
	void printMem(void)
	{
		cout << "a的值是： " << this->a << endl;
		cout << "b的值是： " << this->b << endl;
		// cout << "c的值是： " << this->c << endl; // 因为成员c在父类中是私有成员，所以子类不能访问
	}	
	Child3()
	{ this->a=0; this->b=0; }
};



int main(int argc, char const *argv[])
{
	Child1 c1;
	Child2 c2;
	Child3 c3;

	/**
	 * 在子类的外部使用从父类继承的成员时，主要看子类使用什么权限修饰符继承父类
	 */
	c1.a = 100;
	// c1.b = 999;  // 成员b的权限是protected，只能在子类的内部和父类的内部使用
	c1.printMem();
	
	/**
	 * c2类在继承父类时，使用的是private继承，所以父类的成员都会变成相对子类是private权限，子类的外部不能访问
	 */
	// c2.a = 3;
	// c2.b = 4;
	// c2.c = 5;
	c2.printMem();
	c2.setMemValue(666, 888); // 在子类的内部可以访问父类的成员，这里的修改是成立的
	c2.printMem();

	/**
	 * c3类在继承父类时，使用的是protected继承，所以父类的成员都会变成相对子类是protected和private权限，子类的外部不能访问
	 */
	// c3.a = 222;
	// c3.b = 333;
	// c3.c = 444;
	c3.printMem();
	c3.setMemValue(1000, 2000);
	c3.printMem();

	return 0;
}
