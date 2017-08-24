#include <deque>
#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * @Coding  : utf-8
 * @Date    : 2017-08-24 11:57:02
 * @Author  : ilib0x00000000
 * @Email   : ilib0x00000000@aliyun.com
 * @Link    : https://github.com/ilib0x00000000
 * @Version : 0.1
 */

/**
 * stack： 栈   后进先出
 *
 * api:
 * 		.push()
 * 		.empty()
 * 		.top()
 * 		.pop()
 * 		.size()
 */


void stack_demo(void)
{
	stack<int>  sk;

	sk.push(10);
	sk.push(20);
	sk.push(30);
	sk.push(40);

	cout << "栈的大小是： " << sk.size() << endl;

	while(!sk.empty())
	{
		int tmp = sk.top();    // 获取栈的顶端元素
		cout << "栈顶元素是: " << tmp << endl;
		sk.pop();
	}

}


int main(int argc, char const *argv[])
{
	stack_demo();

	system("pause");
	_CrtCheckMemory();
	return 0;
}