#include <iostream>

using namespace std;

/**
 * 在重载一个类的运算符操作时，如果这个类的数据成员中包含指针，就可能涉及到浅拷贝和深拷贝
 *
 * =运算符默认是浅拷贝
 */

class Test
{
public:
	Test(){  cout << "调用了默认构造" << endl; }
	Test(int len);
	Test(const char *string);
	Test(const Test &nt);
	~Test();
	void printMem(void);
	Test& operator=(const Test& nt)     // 重载=运算符
	{
		/**
		 * 重载=号运算符
		 */
		// 释放原有的缓冲区空间
		cout << "调用了重载=运算符" << endl;
		delete [] this->buffer;

		int len = nt.length;
		
		this->buffer = new char[len];
		this->length = len;

		strcpy(this->buffer, nt.buffer);
		this->buffer[len] = 0;

		return *this;		
	}
	bool operator==(const Test& nt);    // 重载==运算符
private:
	int length;
	char *buffer;
};

bool Test::operator==(const Test& nt)
{
	if(this->length==nt.length && strcmp(this->buffer, nt.buffer)==0)
		return true;

	return false;
}


void objplay(void)
{
	Test t1("string1");
	Test t2("string2");	

	t1.printMem();
	t2.printMem();

	Test t3 = t1;    // 用一个对象初始化另一个对象时，调用了拷贝构造
	t3.printMem();

	Test t4("test");
	// t3.printMem();

	t4 = t1;   // =号默认行为是浅拷贝
	t4.printMem();

	if(t3==t1)
		cout << "t3==t1" << endl;
	else
		cout << "t3!=t1" << endl;

	if(t2==t1)
		cout << "t2==t1" << endl;
	else
		cout << "t2!=t1" << endl;
}


int main(int argc, char const *argv[])
{
	objplay();

	return 0;
}


Test::Test(int len)
{
	this->length = len;
	this->buffer = new char[len];
	this->buffer[0] = '\0';
}


Test::Test(const char *string)
{
	int length = strlen(string);
	
	this->length = length;
	this->buffer = new char[length+1];
	
	strcpy(this->buffer, string);
	this->buffer[length] = '\0';
}


Test::Test(const Test& nt)
{
	cout << "调用了拷贝构造" << endl;
	int len = nt.length;

	cout << "原先的垃圾值是： " << this->length << " 和 " << this->buffer << endl;

	this->length = len;
	this->buffer = new char[len];

	strcpy(this->buffer, nt.buffer);
	// this->buffer[len] = 0;
}

Test::~Test()
{
	delete [] this->buffer;
	this->length = 0;
}

void Test::printMem(void)
{
	cout << "对象的长度是： " << this->length << "  字符串内容是： " << this->buffer << endl;
}

