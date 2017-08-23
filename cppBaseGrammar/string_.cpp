#define _SCL_SECURE_NO_WARNINGS

#include <string>
#include <iostream>

using namespace std;

/**
 * @Coding  : utf-8
 * @Date    : 2017-08-23 10:46:09
 * @Author  : ilib0x00000000
 * @Email   : ilib0x00000000@aliyun.com
 * @Link    : https://github.com/ilib0x00000000
 * @Version : 0.1
 */

/**
 * string类的使用
 * 		.at()
 * 		.length()
 * 		.c_str()
 * 		.copy()
 * 		+=
 * 		.append()
 * 		.find()     char      char *      string &
 * 		.rfind()
 * 		.replace()
 * 		.erase()
 * 		.insert()
 */

void string_demo(void)
{
	/**
	 * 1. 字符串初始化
	 */
	string s1 = "abcdefg";
	string s2("123465");
	string s3 = s2;       // 发生拷贝构造
	string s4(10, 'c');

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;


	/**
	 * 2. 遍历字符串
	 */
	for(int i=0; i < s1.length(); i++)
	{
		cout << s1[i] << " ";
	}
	cout << endl;

	// 使用迭代器遍历字符串
	// 迭代器是容器相关的，所以要加上容器类型作用域
	for(string::iterator it=s1.begin(); it!=s1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;


	/**
	 * 3. 与char *相互转换
	 */
	const char *pc = s1.c_str();
	cout << pc << endl;

	char buff[128];
	s1.copy(buff, 5, 0);   // 从下标0开始，拷贝5个字符到buff中  
	/***********************************************************************************************************************************
	**                                                                                                                                **
	**                                                 不会自动添加0结束标志                                                            **
	**                                                                                                                                **
	************************************************************************************************************************************/
	buff[5] = 0;
	cout << buff << endl;


	/**
	 * 4. 连接字符串
	 */
	s1 += "9999999999";
	cout << s1 << endl;
	s1.append("1111111111");
	cout << s1 << endl;


	/**
	 * 5. 字符串的查找
	 *     如果能查找到，返回下标，否则，返回-1
	 */
	string http_request = "GET /index.html HTTP/1.1\r\n\r\nAccept-Type:text/html\r\nAccept-Coding:utf-8\r\ncache-control:private, max-age=21600\r\n";
	int index = 0;

	index = http_request.find("Accept-Type");
	cout << "index: " << index << endl;

	index = http_request.find("response");
	cout << "index: " << index << endl;


	/**
	 * 6. 字符串的替换
	 */
	index = http_request.find("HTTP/1.1");
	if(index != string::npos)
	{
		http_request.replace(index, 8, "HTTP/2.0");    // 从index位置开始，替换8个字符
	}
	cout << http_request << endl;


	/**
	 * 7. 字符串的删除
	 */
	string st = "hello abc world";
	st.erase(6, 3);                                   // 从下标为6开始的地方，删除3个字符
	cout << st << endl;
	

	/**
	 * 8. 字符串的插入
	 */
	string text = "this is a text";
	text.insert(0, "Dear all:");                      // 从下标为0的地方，插入一个字符串
	cout << text << endl;


	return ;
}


int main(int argc, char const *argv[])
{
	string_demo();

	system("pause");
	return 0;
}