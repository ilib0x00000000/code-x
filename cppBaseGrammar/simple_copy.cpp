#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

/**
 * @Coding  : utf-8
 * @Date    : 2017-08-10 10:52:45
 * @Author  : ilib0x00000000
 * @Email   : ilib0x00000000@aliyun.com
 * @Link    : https://github.com/ilib0x00000000
 * @Version : 0.1
 */

/**
 * 浅拷贝：
 * 如果一个类的构造函数中，动态申请了一段内存空间，并且在析构函数中释放了，则在以下情况中，可能发生浅拷贝
 * 		1. 拷贝构造           ----- 重复析构堆内存地址
 * 		2. =赋值给另一个对象   ----- 内存泄露 重复析构内存地址
 */

class Buffer
{
private:
	int len;
	char *buff;
public:
	Buffer();
	Buffer(char *data);
	// Buffer(Buffer &b);     // 这里故意没有定义拷贝构造
	~Buffer();
	void print_buff(void);
};

void objplay(void)
{
	Buffer b("cache");
	b.print_buff();

	Buffer ch = b;   // 这里会调用拷贝构造
	ch.print_buff();  
	/**
	 * 在对象生命周期结束的时候：
	 * 		1. 析构ch对象的buff指向的堆空间
	 * 		2. 析构b对象的buff指向的堆空间
	 * 而ch和b对象的buff指向同一个内存空间
	 *
	 * 解决方案：
	 *  显示定义拷贝构造，在拷贝构造中重新申请一段堆内存空间
	 */
}

void objplay_1(void)
{
	Buffer b("cache");
	b.print_buff();

	Buffer ch;       // 调用无参构造函数
	ch = b;          // ch对象的len和buff属性被b对象的属性赋值
	ch.print_buff();
	/**
	 * 在对象生命周期结束的时候：
	 * 		1. 析构ch对象的buff指向的堆空间
	 * 		2. 如果ch对象的buff原本指向另一段堆内存空间，则会发生内存泄漏
	 * 		3. 析构b对象的buff指向的堆空间
	 *
	 * 解决方案：
	 * 	重载=运算符
	 */
}


int main(int argc, char const *argv[])
{
	objplay_1();

	system("pause");
	return 0;
}


Buffer::Buffer()
{
	len = 0;
	buff = NULL;
}

Buffer::Buffer(char *data)
{
	len = strlen(data) + 1;
	buff = (char *)malloc(len);
	strcpy(buff, data);
}

	// Buffer(Buffer &b);
Buffer::~Buffer()
{
	if(buff != NULL)
	{
		free(buff);
		buff = NULL;
		len = 0;
	}
}


void Buffer::print_buff(void)
{
	cout << "缓冲区内容是： " << buff << endl;
}
