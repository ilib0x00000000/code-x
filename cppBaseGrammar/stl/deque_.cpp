#include <deque>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * @Coding  : utf-8
 * @Date    : 2017-08-24 11:14:34
 * @Author  : ilib0x00000000
 * @Email   : ilib0x00000000@aliyun.com
 * @Link    : https://github.com/ilib0x00000000
 * @Version : 0.1
 */


/**
 * deque: 双端数组
 *
 * api:
 * 		.push_front()
 * 		.push_back()
 * 		.pop_front()
 * 		.pop_back()
 * 		.back()
 * 		.front()
 * 		.begin()
 * 		.end()
 */

void deque_demo(void)
{
	deque<int>  dq;

	dq.push_back(10);                // 后插
	dq.push_back(20);
	dq.push_back(30);
	dq.push_front(-30);              // 前插
	dq.push_front(-20);
	dq.push_front(-10);

	for(deque<int>::iterator it=dq.begin(); it!=dq.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;


	dq.back() = 999;                 // 赋值给最后一个元素
	dq.front() = 111;                // 赋值给第一个元素
	for(deque<int>::iterator it=dq.begin(); it!=dq.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;


	dq.pop_front();                  // 删除第一个元素
	dq.pop_back();                   // 删除最后一个元素
	for(deque<int>::iterator it=dq.begin(); it!=dq.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	// 查找元素是20的下标
	// 参数是迭代器
	// 返回值是迭代器
	deque<int>::iterator it = find(dq.begin(), dq.end(), 20);
	if(it != dq.end())
	{
		cout << "元素的位置下标是： " << distance(dq.begin(), it) << endl;
	}else
	{
		cout << "未找到该元素" << endl;
	}
}


int main(int argc, char const *argv[])
{
	deque_demo();

	system("pause");
	_CrtCheckMemory();
	return 0;
}