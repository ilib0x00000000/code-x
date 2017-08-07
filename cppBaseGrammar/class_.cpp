#include <iostream>

using namespace std;

/**
 * @Coding  : utf-8
 * @Date    : 2017-08-07 16:37:04
 * @Author  : ilib0x00000000
 * @Email   : ilib0x00000000@aliyun.com
 * @Link    : https://github.com/ilib0x00000000
 * @Version : 0.1
 */

/**
 * 类：
 * 1. 权限修饰符
 * 2. 类（指针，引用）作参数
 */

class Demo
{
	int a;     // 在类中定义的成员，如果不加权限修饰符，则默认是 private
public:
	int get_attr(void);
	void set_attr(int r);
private:
	int attr;
	int deattr;
protected:
};

int Demo::get_attr(void)
{
	return attr;
}

void Demo::set_attr(int r)
{
	attr = r;
}

void operate_demo_p(Demo *d);
void operate_demo_r(Demo &d);


int main(int argc, char const *argv[])
{
	Demo d;

	d.set_attr(10);
	cout << "d的成员属性值是： " << d.get_attr() << endl;

	operate_demo_p(&d);
	operate_demo_r(d);

	system("pause");
	return 0;
}

void operate_demo_p(Demo *d)
{
	/**
	 * 类指针作为函数参数
	 */
	cout << "类指针作为函数参数：  " << d->get_attr() << endl;
}


void operate_demo_r(Demo &d)
{
	/**
	 * 类引用作为函数参数
	 */
	cout << "类引用作为函数参数： " << d.get_attr() << endl;
}
