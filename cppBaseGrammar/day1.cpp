#include <iostream>
#include <string>

#include "cprimer.h"

/**
 * C++数据类型---复合类型
 * 复合类型：是指基于其他类型定义的类型。
 *
 * 引用： 为对象起了另一个名字，引用类型引用另外一种类型。通过将声明符写成&d的形式来定义引用类型，其中d是声明的变量名
 * 		一般在初始化变量时，初始值会被拷贝到新建的对象中。然而定义引用时，程序把引用和它的初始值绑定在一起，而不是将初始值拷贝给引用。
 * 		一旦初始化完成，引用将和它的初始值对象一直绑定在一起。因为无法令引用重新绑定到另外一个对象，因此引用必须初始化。
 * 		（引用并非对象，相反的，它只是为一个已经存在的对象所起的另外一个名字）
 * 		* 因为引用本身不是一个对象，所以不能定义引用的引用
 * 		* 为引用赋值，实际上是把值赋给了与引用绑定的对象。
 * 		* 获取引用的值，实际上是获取了与引用绑定的对象的值。
 * 		* 引用只能绑定在对象上，不能与字面值或者某个表达式的计算结果绑定在一起。
 * 		
 * 指针： 是”指向“另外一种类型的复合类型。与引用类似，指针也实现了对其他对象的间接访问。
 * 		* 指针本身就是一个对象，允许对指针的赋值和拷贝，而且在指针的生命周期内可以先后指向几个不同的对象。
 * 		* 指针无需在定义时赋初值，在块作用域内定义的指针如果没有被初始化，也将拥有一个不确定的值。
 * 		* 因为引用不是对象，没有实际地址，所以不能定义指向引用的指针。
 */


int main(int argc, char const *argv[])
{
	int a = 10;
	double b = 5.59;

	int &ra = a;      // 定义一个a的引用
	double &rb = b;   // 定义一个b的引用

	std::cout << "a的值是： " << a << std::endl;
	std::cout << "b的值是： " << b << std::endl;
	std::cout << "ra引用的值是： " << ra << std::endl;
	std::cout << "rb引用的值是： " << rb << std::endl;

	char *cp = "abcde";
	int  *ip = nullptr;

	// 声明常量SYSTEM_BITS
	// 该常量是外部文件所定义的
	extern const int SYSTEM_BITS;
	std::cout << "常量值： " << SYSTEM_BITS << std::endl;

	/**
	 * 修改引用对象的值
	 */
	int cc = 100;
	int &rcc = cc;

	std::cout << "cc的值是： " << cc << std::endl;
	std::cout << "Rcc引用的值是： " << rcc << std::endl;

	rcc = 999999;

	std::cout << "cc的值是：" << cc << std::endl;
	std::cout << "Rcc引用的值是：" << rcc << std::endl;


	/**
	 * 定义一个类：struct
	 */
	struct book{
		std::string  book_name;
		double       book_price;
		unsigned int book_sold;
	};

	book bk1;
	book bk2;

	std::cin >> bk1.book_name >> bk1.book_price >> bk1.book_sold;
	std::cin >> bk2.book_name >> bk2.book_price >> bk2.book_sold;

	double pi1 = bk1.book_price * bk1.book_sold;
	double pi2 = bk2.book_price * bk2.book_sold;

	std::cout << bk1.book_name << "共卖出了" << pi1 << "元" << std::endl;
	std::cout << bk2.book_name << "共卖出了" << pi2 << "元" << std::endl;



	return 0;
}