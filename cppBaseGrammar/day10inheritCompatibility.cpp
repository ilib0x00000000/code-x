#include <iostream>


using namespace std;


/**
 * 类型兼容性原则
 * 子类对象可以当做父类对象使用
 * 子类对象可以直接赋值给父类对象
 * 子类对象可以直接初始化父类对象
 * 父类指针可以直接指向子类对象
 * 父类引用可以直接引用子类对象
 */

class Parent
{
public:
	void printFromP(void);
private:
	int a;
protected:

};

class Child: public Parent
{
public:
	void printFromC(void);
};

void Parent::printFromP(void)
{
	cout << "这是父类对象" << endl;
}

void Child::printFromC(void)
{
	cout << "这是子类对象" << endl;
}


void useParentPoint(Parent *p)
{
	p->printFromP();
}

void useParentRefence(Parent &p)
{
	p.printFromP();
}


int main(int argc, char const *argv[])
{
	Parent p;
	Child  c;

	p.printFromP();

	c.printFromC();
	c.printFromP();   // 子类对象当父类使用


	Child c1;
	Parent p1;
	p1 = c1;          // 子类对象可以直接赋值给父类对象


	Child c2;
	Parent p2 = c2;   // 子类对象可以直接初始化父类对象

	
	useParentPoint(&c2);  // 父类指针可以直接指向子类对象
	useParentRefence(c2); // 父类引用可以直接使用子类对象

	return 0;
}






