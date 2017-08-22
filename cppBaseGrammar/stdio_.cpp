#include <iostream>

using namespace std;

/**
 * @Coding  : utf-8
 * @Date    : 2017-08-22 10:57:44
 * @Author  : ilib0x00000000
 * @Email   : ilib0x00000000@aliyun.com
 * @Link    : https://github.com/ilib0x00000000
 * @Version : 0.1
 */


/**
 * 输入输出流：
 * 				        ios
 * 		        	   /   \
 *      			  /     \
 * (basic_istream)istream ostream(basic_ostream)
 *      		      \     /
 * 		               \   /
 * 		             iostream
 */


/**
 *                    应用程序<---------------------缓冲区<-----------------------------键盘
 * cin api:
 *    cin.get()
 *    cin.getline()
 *    cin.ignore(n)   忽略缓冲中n个字符
 *    cin.peek()      如果缓冲区中有数据，取出第一个字符
 *    cin.putback(ch) 将ch放回缓冲区最前边  
 */


/**
 * cout api:
 * 		cout.put(ch)                    输出一个字符
 * 		cout.write(char *, int length)  输出一个字符串
 */


int main(int argc, char const *argv[])
{
	int a;
	double d;

	cin >> a;
	cin >> d;

	char ch;

	cin.get();             // 去除空格或者换行
	cin.get(ch);

	cout << "a: " << a << "      d: " << d << "    ch: " << ch << endl;


	char buff_1[128];
	char buff_2[128];

	cin >> buff_1;
	cin >> buff_2;

	cout << buff_1 << endl;
	cout << buff_2 << endl;

	char buff[256];
	cin.getline(buff, 256, '\n');     // 读取一行，以最后一个参数为行分割符
	cout << buff << endl;

	system("pause");
	return 0;
}