#include <iostream>

using namespace std;

/**
 * @Coding  : utf-8
 * @Date    : 2017-08-21 10:10:35
 * @Author  : ilib0x00000000
 * @Email   : ilib0x00000000@aliyun.com
 * @Link    : https://github.com/ilib0x00000000
 * @Version : 0.1
 */

/**
 * 异常：
 * 		1. 语法
 * 		2. 抛出异常
 * 		3. 捕获异常
 */


// 函数声明后面没有加限制，可以抛出任何异常
double divide(int x, int y)
{
	if(y==0)
	{
		throw x;   // 抛出异常
	}

	return x/y;
}


// 函数声明后面加抛出异常类型的限制，则函数中只能抛出指定的异常类型
void except(void) throw(char, char *)
{
	cout << "这是在执行except()函数" << endl;
	throw 1;       // 这里也能编译的过去。。。。。。。。。。
	throw "string exception";
	cout << "你看不见这句话" << endl;
}


// 也可以设置函数不允许抛出异常
void except_1(void) throw ()
{
	throw "error";       // 编译时会有警告，但是还是会正常运行
}


class StringException
{
public:
	StringException()
	{
		cout << "调用了StringException的构造函数" << endl;
	}
	StringException(StringException &se)
	{
		cout << "调用了拷贝构造" << endl;
	}
	~StringException()
	{
		cout << "调用了StringException的析构函数" << endl;
	}
};

class TextException 
{
public:
	TextException() 
	{
		cout << "调用了TextException的构造函数" << endl;
	}
	TextException(TextException &te)
	{
		cout << "调用了拷贝构造" << endl;
	}
	~TextException() 
	{
		cout << "调用了TextException的析构函数" << endl;
	}
};

class TracebackException
{
public:
	TracebackException() 
	{
		cout << "调用了TracebackException的构造函数" << endl;
	}
	TracebackException(TracebackException &tbe) 
	{
		cout << "调用了拷贝构造" << endl;
	}
	~TracebackException() 
	{
		cout << "调用了TracebackException的析构函数" << endl;
	}
};


// 抛出类对象异常
void except_2(int i)
{
	switch(i)
	{
		case 1:
			cout << "即将抛出StringException类对象异常" << endl;
			throw StringException();
			break;
		case 2:
			cout << "即将抛出TextException类对象异常" << endl;
			throw TextException();
			break;
		default:
			cout << "即将抛出TracebackException类对象异常" << endl;
			throw TracebackException();
			break;
	}

	cout << "你看不见我" << endl;
}


int main(int argc, char const *argv[])
{
	int x;
	int y;

	try
	{
		x = 50;
		y = 13;
		cout << divide(x, y) << endl;
		// cout << divide(x, 0) << endl;
		// except_1();
		except_2(1);
	}catch(int e)
	{
		// 捕获到异常
		cout << e << "除以0，发生错误" << endl;
	}catch(char *e)
	{	
		cout << e << endl;
	}catch(StringException se)
	{
		cout << "....." << endl;
	}catch(TextException te)
	{
		// 捕获异常时，相当于结束当前函数，调用另一个函数
		// 将异常作为函数参数传递过去，清理当前函数栈的内容
		// 所以会调用拷贝构造
		cout << "....." << endl;
	}catch(TracebackException tbe)
	{
		cout << "....." << endl;
	}catch( ... )
	{
		// 捕获到其他异常
		cout << "捕获到其他异常" << endl;
	}


	system("pause");
	return 0;
}