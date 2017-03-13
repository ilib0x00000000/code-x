#include <cctype>
#include <string>
#include <iostream>

/**
 * C++标准库类型：string
 * 
 * string对象的操作
 *
 * os << s         将s写到输出流os中，返回os
 * is >> s         从is中读取字符串赋值给s，字符串以空白符分隔，返回is
 * getline(is, s)  从is中读取一行赋给s，返回is
 * s.empty()       若字符串为空，返回true，否则返回false
 * s.size()        返回字符串的长度
 * s[n]            返回字符串中的第n个字符，从0开始计数
 * s1+s2           返回s1和s2连接后的字符串啊
 * s1=s2           将s2赋值给s1
 * s1==s2          判断s1与s2是否相同
 */

using namespace std;


int main(int argc, char const *argv[])
{
	// 初始化字符串
	string s1 = "";
	string s2 = s1;
	string s3("test");
	string s4 = "test";
	string s5(10, 'c');

	cout << "s1=" << s1 << " s2=" << s2 << " s3=" << s3 << " s4=" << s4 << " s5=" << s5 << endl;

	if(!s5.empty())
	{
		cout << "s5的长度是： " << s5.size() << endl;
		s5[0] = 'a';
		s5[s5.size() - 1] = 'z';

		cout << s5 << endl;
	}

	// string.size()返回的数据类型是string::size_type
	string::size_type st = s4.size();


	// 依次读取字符串中的每个字符
	// 使用引用
	for(auto &c : s4)
	{
		c = toupper(c);
	}
	cout << "使用引用修改s4之后的字符串： " << s4 << endl;

	return 0;
}