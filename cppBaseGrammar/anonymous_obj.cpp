#include <iostream>

using namespace std;

/**
 * @Coding  : utf-8
 * @Date    : 2017-08-09 09:55:57
 * @Author  : ilib0x00000000
 * @Email   : ilib0x00000000@aliyun.com
 * @Link    : https://github.com/ilib0x00000000
 * @Version : 0.1
 */

/**
 * 匿名对象：
 * 		1. 当一个函数返回匿名对象
 * 		2. 当一个函数返回匿名对象的引用
 * 		3. 当一个函数返回一个对象
 * 		4. 当一个返回返回一个对象的引用
 *
 * 用上述返回的对象去初始化一个对象
 * 用上述返回的对象赋值一个对象
 * 用上述返回的对象去初始化一个对象的引用
 *
 * 总共： 3*4种情况
 */

class Demo
{
private:
	int m_a;
	int m_b;
public:
	Demo();
	Demo(int a, int b);
	Demo(Demo& d);
	~Demo();
};

Demo return_obj(void);
Demo& return_obj_r(void);
Demo return_anony_obj(void);
Demo& return_anony_obj_r(void);

void objplay(void)
{
	Demo d1 = return_obj();            // 调用了拷贝构造函数
	Demo d2 = return_obj_r();          // 调用了拷贝构造函数
	Demo d3 = return_anony_obj();
	Demo d4 = return_anony_obj_r();    // 调用了拷贝构造函数

	/***********************************************************************/

	Demo d5;   // 调用了无参构造函数  0   0
	Demo d6;   // 调用了无参构造函数  0   0
	Demo d7;   // 调用了无参构造函数  0   0
	Demo d8;   // 调用了无参构造函数  0   0

	d5 = return_obj();   // 调用了拷贝构造函数  12   13
	d6 = return_obj_r();
	d7 = return_anony_obj();
	d8 = return_anony_obj_r();

	/***********************************************************************/

	Demo &d9 = return_obj();   // 调用了拷贝构造函数  12   13
	Demo &d10 = return_obj_r();
	Demo &d11 = return_anony_obj();
	Demo &d12 = return_anony_obj_r();


	/**
	 * 结论： 
	 * 		返回对象的时候，无论是初始化还是赋值给一个对象/对象引用，都会调用拷贝构造
	 * 		返回对象的引用或者匿名对象的引用时，只有在初始化一个对象时，才会调用拷贝构造
	 */
}


int main(int argc, char const *argv[])
{
	objplay();



	system("pause");
	return 0;
}


Demo::Demo()
{
	m_a = 0;
	m_b = 0;
	cout << "调用了无参构造函数  " << m_a << "   " << m_b << endl;
}

Demo::Demo(int a, int b)
{
	m_a = a;
	m_b = b;
	cout << "调用了带参构造函数  " << m_a << "   " << m_b  << endl;
}

Demo::Demo(Demo &d)
{
	m_a = d.m_a;
	m_b = d.m_b;
	cout << "调用了拷贝构造函数  "  << m_a << "   " << m_b  << endl;
}


Demo::~Demo()
{
	cout << "调用了析构函数" << endl;
}


Demo return_obj(void)
{
	Demo d(12, 13);

	return d;
}

Demo& return_obj_r(void)
{
	Demo d(14, 15);

	return d;
}


Demo return_anony_obj(void)
{
	return Demo(16, 17);
}


Demo& return_anony_obj_r(void)
{
	return Demo(18, 19);
}


/*
全部输出

调用了带参构造函数  12   13
调用了拷贝构造函数  12   13
调用了析构函数

调用了带参构造函数  14   15
调用了析构函数
调用了拷贝构造函数  -858993460   9436460

调用了带参构造函数  16   17
调用了带参构造函数  18   19
调用了析构函数

调用了拷贝构造函数  16519268   7659520

调用了无参构造函数  0   0
调用了无参构造函数  0   0
调用了无参构造函数  0   0
调用了无参构造函数  0   0

调用了带参构造函数  12   13
调用了拷贝构造函数  12   13
调用了析构函数

调用了析构函数
调用了带参构造函数  14   15
调用了析构函数

调用了带参构造函数  16   17
调用了析构函数

调用了带参构造函数  18   19
调用了析构函数
调用了带参构造函数  12   13
调用了拷贝构造函数  12   13
调用了析构函数
调用了带参构造函数  14   15
调用了析构函数
调用了带参构造函数  16   17
调用了带参构造函数  18   19

调用了析构函数
调用了析构函数
调用了析构函数
调用了析构函数
调用了析构函数
调用了析构函数
调用了析构函数
调用了析构函数
调用了析构函数
调用了析构函数
调用了析构函数
*/