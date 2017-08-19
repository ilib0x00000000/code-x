#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>

using namespace std;

/**
* @Coding  : utf-8
* @Date    : 2017-08-19 09:40:06
* @Author  : ilib0x00000000
* @Email   : ilib0x00000000@aliyun.com
* @Link    : https://github.com/ilib0x00000000
* @Version : 0.1
*/

/**
* 类模板
*/

template <typename IntegerType, typename DecimalType>
class Demo
{
public:
	Demo()
	{
		this->leng = 0;
		this->value = 0;
	}

	Demo(DecimalType value, IntegerType leng)
	{
		this->value = value;
		this->leng = leng;
	}

	void print_(void)
	{
		char buff[128];
		sprintf(buff, "在截取指定小数位之后，price的值是： %%.%dlf\n", this->leng);
		printf(buff, this->value);
	}
protected:
	IntegerType leng;        // 小数点的长度
	DecimalType value;
};



/**
 * 继承模板类时，要显示出模板类的具体类型，以确定类的大小
 */
class Object: public Demo<int, double>         // 这样继承父类，是因为需要确定父类占用的空间大小IntegerType/DecimalType
{
public:
	Object(): Demo<int, double>()              // 调用父类的构造方法时，（最好）带上指定参数类型
	{
		this->discount = 1;
	}

	Object(double price, int leng, double discount=1): Demo<int, double>(price, leng)
	{
		this->discount = discount;
	}

	void final_price(void)
	{
		char buff[128];
		sprintf(buff, "%%.%dlf\n", this->leng);
		printf(buff, this->value * this->discount);
	}
private:
	double discount;
};


/**
 * 模板类继承模板类
 * 字模板类可以向父模板类传递 <泛型>
 */
template <typename IntegerType, typename DecimalType, typename StringType>
class Complex: public Demo<IntegerType, DecimalType>
{
public:
	Complex(): Demo<IntegerType, DecimalType>()   // 调用父类的无参构造函数
	{
		this->name = "";  // or "未知"
	}

	Complex(StringType name, IntegerType leng, DecimalType value): Demo<IntegerType, DecimalType>(value, leng)
	{
		this->name = name;
	}

	void print_msg(void)
	{
		cout << this->name << " 的价格是 "; 
		this->print_();   // 父类的函数
	}
private:
	StringType name;
};


// 类模板做函数参数
// 类模板在做函数参数时，类模板的类型要确定，因为C++编译器要为参数申请空间
void class_template(Demo<int, double> &dr)
{
	dr.print_();
}


int main(int argc, char const *argv[])
{

	Demo<int, double> price(4896.165118654, 5);
	Demo<int, float> df(251.123456, 2);

	// price.print_();

	class_template(price);
	// class_template(df);   // 这里会报错，因为函数定义时的参数类型已经确定下来

	Demo<int, double> dp1(369.0012, 2);
	Demo<int, double> dp2(369.6512, 6);
	Demo<int, double> dp3(369.123456789, 4);

	class_template(dp1);
	class_template(dp2);
	class_template(dp3);


	cout << "**********************************************************************************" << endl;

	Object fruit(9.99, 4);
	fruit.final_price();

	Object milk(19.99, 4, 0.8);
	milk.final_price();


	cout << "**********************************************************************************" << endl;

	Complex<int, double, string> onion("洋葱", 2, 13.4526);
	onion.print_msg();


	Complex<int, double, string> unknown;
	unknown.print_msg();

	system("pause");
	return 0;
}