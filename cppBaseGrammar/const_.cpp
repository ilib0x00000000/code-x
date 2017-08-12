#include <iostream>

using namespace std;

/**
 * @Coding  : utf-8
 * @Date    : 2017-08-12 10:39:18
 * @Author  : ilib0x00000000
 * @Email   : ilib0x00000000@aliyun.com
 * @Link    : https://github.com/ilib0x00000000
 * @Version : 0.1
 */


/**
 * 成员函数声明时的const常量：修饰的是this指针
 *
 * this指针的实质是： ClassName *const this
 * 表明this的指向只能是本类，不能改变this的指向
 *
 * 如果在成员函数定义时，指定const修饰符，则相当于修饰this指针: const ClassName *const this
 */
class Demo
{
private:
	int a;
	int b;
public:
	Demo();
	Demo(int a, int b);
	Demo(Demo &d);
	~Demo();
	void print_attr(void) const;
};


int main(int argc, char const *argv[])
{
	Demo d(10, 20);
	d.print_attr();

	system("pause");
	return 0;
}


Demo::Demo()
{
	this->a = 0;
	this->b = 0;
	cout << "a的值是： " << this->a << endl;
	cout << "b的值是： " << this->b << endl;	
}


Demo::Demo(int a, int b)
{
	this->a = a;
	this->b = b;
	cout << "a的值是： " << this->a << endl;
	cout << "b的值是： " << this->b << endl;	
}


Demo::Demo(Demo& d)
{
	this->a = d.a;
	this->b = d.b;
	cout << "a的值是： " << this->a << endl;
	cout << "b的值是： " << this->b << endl;	
}


Demo::~Demo()
{
	cout << "调用了析构函数" << endl;
}

void Demo::print_attr(void) const
{
	// 在成员函数定义时，指定了const修饰符，则表明this指针指向的空间的数据不能被修改
	
	// this->a = 999;    // 这里无法修改this指向的值，编译不过去
	cout << "a的值是： " << this->a << endl;
	cout << "b的值是： " << this->b << endl;	
}
