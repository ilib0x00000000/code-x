#include <map>
#include <string>
#include <iostream>

using namespace std;

/**
 * @Coding  : utf-8
 * @Date    : 2017-08-26 10:42:47
 * @Author  : ilib0x00000000
 * @Email   : ilib0x00000000@aliyun.com
 * @Link    : https://github.com/ilib0x00000000
 * @Version : 0.1
 */

/**
 * multimap:   键可以重复    功能：实现分组
 *
 * api:
 * 		.insert()
 * 		.begin()
 * 		.end()
 * 		.count()
 */

class Object
{
public:
	Object(string name_, int age_, double salary_): age(age_), salary(salary_), name(name_){}
	~Object();

public:
	string name;
	int  age;
	double salary;
};


void multimap_demo()
{
	Object obj1("obj1", 46, 13535.45);
	Object obj2("obj2", 23, 13535.45);
	Object obj3("obj3", 51, 13535.45);
	Object obj4("obj4", 34, 13535.45);
	Object obj5("obj5", 22, 13535.45);
	Object obj6("obj6", 36, 13535.45);

	multimap<string, Object>  company;

	// 插入是有返回值的，应该对返回值做检测
	company.insert(make_pair("develop", obj1));
	company.insert(make_pair("sale", obj2));
	company.insert(make_pair("sale", obj3));
	company.insert(make_pair("help", obj4));
	company.insert(make_pair("help", obj5));
	company.insert(make_pair("help", obj6));


	// 输出multimap
	for(multimap<string, Object>::iterator it=company.begin(); it!=company.end(); it++)
	{
		cout << "部门： " << it->first << "      员工信息： " << it->second.name << "  " << it->second.age << "  " << it->second.salary << endl;
 	}

 	cout << "销售部有" << company.count("sale") << "名员工" << endl;
}


int main(int argc, char const *argv[])
{
	multimap_demo();

	system("pause");
	_CrtCheckMemory();
	return 0;
}