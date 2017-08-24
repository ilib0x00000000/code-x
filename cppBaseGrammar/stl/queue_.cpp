#include <deque>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>


using namespace std;

/**
 * @Coding  : utf-8
 * @Date    : 2017-08-24 13:33:17
 * @Author  : ilib0x00000000
 * @Email   : ilib0x00000000@aliyun.com
 * @Link    : https://github.com/ilib0x00000000
 * @Version : 0.1
 */

/**
 * queue: 队列   先进先出
 *
 * api:
 * 		.push()
 * 		.pop()
 * 		.empty()
 * 		.front()
 * 		.size()
 * 		.back()
 */


void queue_demo(void)
{
	queue<int> qs;    // 创建一个队列

	qs.push(10);
	qs.push(20);
	qs.push(30);
	qs.push(40);

	cout << "队列的长度是： " << endl;

	/**
	 * queue没有迭代器
	 */
	// for(queue<int>::iterator it = qs.begin(); it!=qs.end(); it++)
	// {
	// 	cout << *it << "  ";
	// }
	// cout << endl;


	while(!qs.empty())
	{
		int temp = qs.front();
		cout << "队列的首元素是： " << temp << endl;
		qs.pop();
	}
}


int main(int argc, char const *argv[])
{
	queue_demo();

	system("pause");
	_CrtCheckMemory();
	return 0;
}