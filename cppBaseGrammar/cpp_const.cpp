#include <iostream>

using namespace std;


void func1(void);
void func2(void);


int main(int argc, char const *argv[])
{
	int a;
	const int b = 10;
	int c;
	/**
	 * 编译时，这3个变量在内存中占用的空间是相连的，因为都是在栈中
	 * 下面代码可以证明
	 */
	printf("a:%p    b:%p    c:%p\n", &a, &b, &c);
	

	int *p = NULL;
	p = (int *)&b;
	printf("p:%p\n", p);   // p的地址就是常量b的地址

	*p = 999;
	printf("*p:%d\n", *p);
	printf("b: %d\n", b);
	/**
	 * 上面的输出在C语言编译器和C++编译器是不同的
	 *
	 * 在C编译器中的输出，结果是相同的，C语言中的常量实际是可以通过指针修改的
	 * 但是在C++中的输出是不同的，因为C++实际上还替常量维护了一个常量表，符号b实质上指向的是常量表中的数据，该常量表存放的位置暂且不知
	 *
	 * 参考：
	 * http://bbs.csdn.net/topics/360189035
	 */
	
	func1();
	func2();

	system("pause");
	
	return 0;
}


void func1(void)
{
	#define LOAL 10
	// undef LOAL   // 卸载宏定义
}


void func2(void)
{
	printf("宏定义LOAL的值是： %d\n", LOAL);   // 宏定义是可以跨空间使用的
}

