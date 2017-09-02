#include <set>
#include <iostream>

using namespace std;

/**
* @Coding  : utf-8
* @Date    : 2017-08-25 15:24:19
* @Author  : ilib0x00000000
* @Email   : ilib0x00000000@aliyun.com
* @Link    : https://github.com/ilib0x00000000
* @Version : 0.1
*/

/**
* multiset： 可重复 自动排序 集合
*
* api:
* 		.begin()
* 		.end()
* 		.empty()
* 		.erase()
* 		.insert()
*/

void multiset_demo(void)
{
	multiset<int> ms;

	ms.insert(8);
	ms.insert(5);
	ms.insert(3);
	ms.insert(2);
	ms.insert(2);
	ms.insert(4);
	ms.insert(5);
	ms.insert(8);
	ms.insert(6);
	ms.insert(1);

	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;

	while (!ms.empty())
	{
		multiset<int>::iterator it = ms.begin();
		cout << "删除元素: " << *it << endl;
		ms.erase(it);
	}

	cout << "multiset集合的长度是： " << ms.size() << endl;
}


int main(int argc, char const *argv[])
{
	multiset_demo();

	system("pause");
	_CrtCheckMemory();
	return 0;
}