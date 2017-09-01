#include <map>
#include <string>
#include <iostream>

using namespace std;

/**
 * @Coding  : utf-8
 * @Date    : 2017-08-25 15:48:54
 * @Author  : ilib0x00000000
 * @Email   : ilib0x00000000@aliyun.com
 * @Link    : https://github.com/ilib0x00000000
 * @Version : 0.1
 */


/**
 * map： 键值对
 *
 * api:
 * 		.insert()
 * 		.begin()
 * 		.end()
 * 		.erase()
 * 		.empty()
 * 		.size()
 * 		.find()
 * 		.count()
 * 		.equal_range()
 */

void map_insert(void)
{
	/**
	 * map的4中插入方式   前3种插入方式是有返回值的，需要对返回值进行检验
	 */
	map<string, int> dict;

	// 1. pair
	dict.insert(pair<string, int>("user01", 1));
	dict.insert(pair<string, int>("user02", 2));

	// 2. make_pair
	dict.insert(make_pair("user03", 3));
	dict.insert(make_pair("user04", 4));

	// 3. map::value_type
	dict.insert(map<string, int>::value_type("user05", 5));
	dict.insert(map<string, int>::value_type("user06", 6));	

	// 4.
	dict["user07"] = 7;
	dict["user08"] = 8;


	// 遍历map
	for(map<string, int>::iterator it=dict.begin(); it!=dict.end(); it++)
	{
		cout << "用户名： " << it->first << "   id: " << it->second << endl;
	}

	// 插入时的返回值
	pair<map<string, int>::iterator, bool> pib1 = dict.insert(pair<string, int>("abc", 3));
	if (pib1.second)
	{
		cout << pib1.first->first << "插入成功" << endl;
	}
	else
	{
		cout << pib1.first->first << "插入失败" << endl;
	}

	// 插入时的返回值
	pair<map<string, int>::iterator, bool> pib2 = dict.insert(make_pair("content", 101));
	if (pib2.second)
	{
		cout << pib2.first->first << "插入成功" << endl;
	}
	else
	{
		cout << pib2.first->first << "插入失败" << endl;
	}

	// 插入时的返回值
	pair<map<string, int>::iterator, bool> pib3 = dict.insert(map<string, int>::value_type("python", 85));
	if (pib3.second)
	{
		cout << pib3.first->first << "插入成功" << endl;
	}
	else
	{
		cout << pib3.first->first << "插入失败" << endl;
	}

	// map的查找   返回一个迭代器
	map<string, int>::iterator its = dict.find("abc");
	if (its != dict.end())
	{
		cout << "查找到目标" << its->first << "  value是： " << its->second << endl;
	}
	else
	{
		cout << "没有找到目标" << endl;
	}
}


void map_delete(void)
{
	map<string, int> dict;

	dict["user01"] = 1;
	dict["user02"] = 2;
	dict["user03"] = 3;
	dict["user04"] = 4;
	dict["user05"] = 5;
	dict["user06"] = 6;
	dict["user07"] = 7;


	while(!dict.empty())
	{
		map<string, int>::iterator it=dict.begin();
		cout << "用户名： " << it->first << "  id: " << it->second << endl;
		dict.erase(it);
	}
	cout << "map<>的长度是： " << dict.size() << endl;
}


void map_range()
{
	map<int, string> dict;

	dict[0] = "abc";
	dict[1] = "def";
	dict[2] = "xyz";
	dict[3] = "xml";
	dict[4] = "html";
	dict[5] = "css";

	// typedef pair<iterator, bool> _Pairib;
	// typedef pair<iterator, iterator> _Pairii;
	// typedef pair<const_iterator, const_iterator> _Paircc;
	pair<map<int,string>::iterator, map<int, string>::iterator> pii = dict.equal_range(3);
	
	// 第一个迭代器是>=3的指针
	if (pii.first != dict.end())
	{
		cout << "第一个迭代器指向的元素： " << pii.first->first << "   " << pii.first->second << endl;
	}
	else
	{
		cout << "没有大于等于3的元素" << endl;
	}

	// 第二个迭代器是>3的指针
	if (pii.second != dict.end())
	{
		cout << "第二个迭代器指向的元素是： " << pii.second->first << "   " << pii.second->second << endl;
	}
	else
	{
		cout << "没有大于3的元素" << endl;
	}
}


int main(int argc, char const *argv[])
{
	map_insert();
	map_delete();
	map_range();

	system("pause");
	_CrtCheckMemory();
	return 0;
}