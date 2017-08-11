#include <iostream>

using namespace std;

/**
 * @Coding  : utf-8
 * @Date    : 2017-08-11 09:39:32
 * @Author  : ilib0x00000000
 * @Email   : ilib0x00000000@aliyun.com
 * @Link    : https://github.com/ilib0x00000000
 * @Version : 0.1
 */

/**
 * new 和 delete 关键字的用法
 *
 * 1. 基础类型   --- 与malloc/free无区别
 * 2. 数组       --- 与malloc/free无区别
 * 3. 类对象     --- 会自动调用构造/析构函数
 *
 * 在某些时候，new/free和malloc/delete可以混用，但是在申请类对象空间时，如果构造函数中又申请了堆空间，此时不能混用，以免内存泄漏
 */

class Demo
{
private:
	int a;
	int b;
public:
	Demo();
	Demo(int _a, int _b);
	Demo(Demo &d);
	~Demo();
};

void test0(void)
{
	// 基础类型
	char *pa = (char *)malloc(sizeof(char)*10);
	free(pa);

	int *npi = new int(10);   // 申请一个int字节空间，并且赋值为10
	delete npi;

	double *npd = new double; // 申请一个double字节空间
	*npd = 3.14;              // 赋值为3.14
	delete npd;               // 释放空间
} 


void test1(void)
{
	// 数组类型
	int *npi = new int[10];    // 申请10个int字节空间
	npi[0] = 1;
	npi[2] = 3;
	npi[5] = 4;
	npi[8] = 8;
	npi[9] = 6;
	delete [] npi;             // 释放空间

	double *npd = new double[5];  // 申请10个double字节空间
	npd[0] = 1.0;
	npd[1] = 2.0;
	npd[2] = 3.0;
	npd[3] = 4.0;
	npd[4] = 5.0;
	delete [] npd;
}


void test2(void)
{
	// 类对象
	Demo *npd = new Demo();    // 申请一个Demo类大小的字节空间，会自动调用无参构造函数
	delete npd;                // 释放空间，会自动调用析构函数


	Demo *npi = new Demo(5,5); // 申请一个Demo类大小的字节空间，会自动调用带参数的构造函数
	delete npi;                // 释放空间，会自动调用析构函数

	Demo *npa = new Demo[3];
	delete [] npa;
}


int main(int argc, char const *argv[])
{
	test0();
	test1();
	test2();

	system("pause");
	return 0;
}

Demo::Demo()
{
	a = 0;
	b = 0;
	cout << "无参构造函数 a: " << a << "  b: " << b << endl;
}

Demo::Demo(int _a, int _b)
{
	a = _a;
	b = _b;
	cout << "带参数构造函数 a: " << a << "  b: " << b << endl;
}

Demo::Demo(Demo &d)
{
	a = d.a;
	b = d.b;
	cout << "调用了拷贝构造函数" << endl;
}

Demo::~Demo()
{
	cout << "a: " << a << "  b: " << b << "   析构函数" << endl;
}
