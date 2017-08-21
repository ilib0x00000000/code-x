#include <iostream>

using namespace std;

/**
 * @Coding  : utf-8
 * @Date    : 2017-08-21 08:57:55
 * @Author  : ilib0x00000000
 * @Email   : ilib0x00000000@aliyun.com
 * @Link    : https://github.com/ilib0x00000000
 * @Version : 0.1
 */

/**
 * 类型转换:
 * 		1. static_cast           静态类型转换  double----->int   编译时，C++会做类型检查  凡是能隐式转换的，static_cast都能转换成功
 * 		2. reinterpret_cast      重新解释类型  static_cast转换不了的，可以用reinterpret_cast转换
 * 		
 * 		3. dynamic_cast          动态类型转换  继承时的父子类  可以动态识别类型
 * 		4. const_cast            去const属性
 *
 * 语法：
 * 	TYPE var = xxx_cast<TYPE>vars
 */

// 抽象类
class Object
{
public:
	virtual void print_name(void) = 0;   // 纯虚函数
};

// 继承抽象类
class Fruit: public Object
{
public:
	virtual void print_name(void)
	{
		cout << "我是水果" << endl;
	}

	void delicious(void)
	{
		cout << "水果很美味" << endl;
	}
};

// 继承抽象类
class Vegetables : public Object
{
public:
	virtual void print_name(void)
	{
		cout << "我是蔬菜" << endl;
	}

	void eat(void)
	{
		cout << "多吃蔬菜更健康" << endl;
	}
};


void objplay(Object *obj)
{
	obj->print_name();      // 多态

	Fruit *pf = dynamic_cast<Fruit *>(obj);   // 动态类型转换， 如果能转换成功， 说明是一个类型， 如果不能，返回NULL
	if(pf)
	{
		pf->delicious();   // Fruit类特有的函数
	}

	Vegetables *pv = dynamic_cast<Vegetables *>(obj);
	if(pv)
	{
		pv->eat();         // Vegetables类特有的函数
	}
}


void modify(const char *pc)
{
	char *p = NULL;

	p = const_cast<char *>(pc);
	p[0] = '@';

	/*
		与上面的效果等效
	
		p = (char *)pc;             // const赋值给非const时，需要显示转换
		p[0] = '@';
	*/

	cout << pc << endl;
}


int main(int argc, char const *argv[])
{
	double pi = 3.14;
	int var = 0;

	var = static_cast<int>(pi);   // 如果这里不使用模板函数static_cast转换，则编译器会发出警告
	cout << var << endl;
	/**
	 * 静态转换(static_cast<>())只能做类型兼容的转换
	 * 其作用就是让编译器别发出警告
	 */



	/**
	 * reinterpret_cast
	 */
	char *ptr = "Hello World";
	int *pti = NULL;
	// pti = ptr;        // 直接转换 error
	// pti = static_cast<int *>(ptr); // 静态转换也是error
	pti = reinterpret_cast<int *>(ptr);  // 强制转换
	cout << ptr << endl;
	cout << pti << endl;


	/**
	 * 动态类型转换： 一般与多态配合使用
	 */
	Fruit f;
	Vegetables v;

	objplay(&f);
	objplay(&v);


	/**
	 * const_cast: 去除只读属性
	 */
	char buff[] = "iljiollkmlbub";
	modify(buff);


	system("pause");
	return 0;
}