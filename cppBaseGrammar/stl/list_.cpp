#include <list>
#include <iostream>

using namespace std;

/**
 * @Coding  : utf-8
 * @Date    : 2017-08-24 16:28:47
 * @Author  : ilib0x00000000
 * @Email   : ilib0x00000000@aliyun.com
 * @Link    : https://github.com/ilib0x00000000
 * @Version : 0.1
 */

/**
 * list： 链表容器   不可以随机存取，不支持下标访问
 *
 * api:
 * 		.push_back()
 * 		.size()
 * 		.begin()
 * 		.end()
 * 		.insert(iter, value)
 * 		.erase()
 * 		.clear()
 * 		.remove()
 * 		.back()              最后一个元素
 */


void list_demo(void)
{
	list<int> ls;

	cout << "list容器的长度是： " << ls.size() << endl;
	
	ls.push_back(11);
	ls.push_back(22);
	ls.push_back(33);
	ls.push_back(44);

	cout << "list容器的长度是： " << ls.size() << endl;

	for(list<int>::iterator it=ls.begin(); it!=ls.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;


	// 创建一个迭代器
	// 11 22 33 44
	// 11 22 33 100 44
	list<int>::iterator its = ls.begin();
	its ++;
	its ++;
	its ++;
	ls.insert(its, 100);
	for(list<int>::iterator it=ls.begin(); it!=ls.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;


	/**
	 * list删除
	 * 		1. 删除一个元素
	 * 		2. 删除一个区间元素   包含头不包含尾
	 * 		3. 删除某个指定值的元素
	 */
	list<int>::iterator it1 = ls.begin();
	list<int>::iterator it2 = ls.begin();
	it2++;
	it2++;
	it2++;
	ls.erase(it1, it2);        // 删除一个区间的元素，包含头，不包含尾
	for(list<int>::iterator it=ls.begin(); it!=ls.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;


	int tmp = ls.back();
	printf("%d\n", tmp);

	list<int>::iterator last = ls.end();
	last --;
	ls.erase(last);              // 删除最后一个元素
	for(list<int>::iterator it=ls.begin(); it!=ls.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;


	ls.push_back(rand());
	ls.push_back(999);
	ls.push_back(rand());
	ls.push_back(rand());
	ls.push_back(999);
	ls.push_back(rand());


	ls.remove(999);           // 删除list中值是999的元素
	for(list<int>::iterator it=ls.begin(); it!=ls.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;	
}


int main(int argc, char const *argv[])
{
	list_demo();

	system("pause");
	_CrtCheckMemory();
	return 0;
}