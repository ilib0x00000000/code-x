#include<iostream>

using namespace std;

// C++引用本质是常量指针
// Type * const ref = var;

/**
 * C++中的引用定义：经过编译器优化的指针常量，具体体现在下面1、2
 *
 * 引用作为函数的返回值时，要特别注意：
 * 		1. 如果函数返回的是基本类型
 * 				1. 将函数返回值赋值给一个变量
 * 				2. 将函数返回值赋值给一个引用
 * 		2. 如果函数返回的是复杂类型
 */

struct Type 
{
	int age;
	char name[4];

	bool& rrs;
	char& rch;
	short& rsi;
	int& ri;
	long& rli;
	float& rfa;
	double& rda;
};

int  return_int_(void);    // 返回一个变量
int& return_int_r(void);   // 返回一个变量的引用
int* return_int_p(void);   // 返回一个变量的指针

void main()
{
	bool rs = true;
	char ch = 'a';
	short si = 2;
	int i = 8;
	long li = 1023821312384;
	float fa = 1.327;
	double da = 213.8162363;

	bool& rrs = rs;
	char& rch = ch;
	short& rsi = si;
	int& ri = i;
	long& rli = li;
	float& rfa = fa;
	double& rda = da;

	printf("%d   %d    %d    %d   %d   %d   %d   \n", sizeof(rrs), sizeof(rch), sizeof(rsi),
		sizeof(ri), sizeof(rli), sizeof(rfa), sizeof(rda));      // 1


	printf("%d\n", sizeof(struct Type));

	// 使用变量来接 
	int ra;
	ra = return_int_r();        // 2
	printf("%d\n", ra);


	// 使用引用来接
	int& rra = return_int_r();
	printf("%d\n", rra);

	/**
	 * 上面的输出： 使用变量来接是正常的，使用引用来接有可能正常，也有可能是乱码
	 *
	 * 解释：
	 * 如果使用变量来接，编译器检测到是赋值给变量，就将引用指向的空间的值赋值给该变量
	 * 如果使用引用来接，编译器就直接将引用的指向赋值给该引用，再通过引用读取值时，该空间有可能已经被清空了
	 *
	 * 参考：
	 * http://blog.csdn.net/k346k346/article/details/46805159
	 */


	system("pause");
}


int& return_int_r(void)
{
	int a;
	a = 5;
	return a;
}

int  return_int_(void)
{
	int a;
	a = 5;
	return a;    // 返回值是存放在一个寄存器中
}

int* return_int_p(void)
{
	int a;
	a = 5;
	return &a;
}