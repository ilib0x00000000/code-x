#include <fstream>
#include <iostream>

using namespace std;

/**
 * @Coding  : utf-8
 * @Date    : 2017-08-22 17:06:16
 * @Author  : ilib0x00000000
 * @Email   : ilib0x00000000@aliyun.com
 * @Link    : https://github.com/ilib0x00000000
 * @Version : 0.1
 */

/**
 * 文件输出流： ofstream
 * 文件输入流： ifstream
 *
 * ios::in               以输入方式打开文件
 * ios::out              以输出方式打开文件
 * ios::app              以输出方式打开文件，写入数据时使用的是追加方式
 * ios::ate              打开一个已有的文件，文件指针指向文件末尾
 * ios::trunc            打开一个文件，如果文件已经存在，则删除其中全部数据，若文件不存在，则新建文件
 * ios::binary           以二进制方式打开一个文件
 * ios::nocreate         打开一个已有的文件，如果文件不存在，则打开失败
 *
 * 如果是组合形式，打开文件，使用|相连
 *
 *
 * ofstream.write()
 * ifstream.read()
 */

int main(int argc, char const *argv[])
{
	/**
	 * 建立一个文件输出流，向文件中写入数据
	 */
	char *filename = "test.txt";

	ofstream of(filename, ios::out);
	of << "这是一段话" << endl;                 
	of << "这是第二行话" << endl;
	of.close();



	/**
	 * 建立一个文件输入流
	 */
	char buff[256];
	ifstream ifs(filename, ios::in);
	ifs >> buff;                  // 以换行符为读取结束标志
	cout << buff << endl;
	ifs >> buff;                  // 以换行符为读取结束标志
	cout << buff << endl;
	ifs.close();

	system("pause");
	return 0;
}