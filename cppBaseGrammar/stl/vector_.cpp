#include <vector>
#include <string>
#include <iostream>

using namespace std;

/**
* @Coding  : utf-8
* @Date    : 2017-08-24 09:36:30
* @Author  : ilib0x00000000
* @Email   : ilib0x00000000@aliyun.com
* @Link    : https://github.com/ilib0x00000000
* @Version : 0.1
*/

/**
* vector: 容器，可以装基本元素类型，复杂数据类型，指针
* 		容器中的元素必须是可以拷贝的类型：
* 				提供拷贝构造
* 				重载=运算符
*
* 初始化：
* 		vector<TYPE> contain(n);
* 		vector<TYPE> contain(n, element);
* 		vector<TYPE> contain(begin, end);
*
* api:
* 		.size()
* 		.push_back()    从最后添加一个元素
* 		.pop_back()     删除最后一个元素
* 		.back()         获取最后一个元素，返回的是引用
* 		.front()        获取第一个元素，返回的是引用
* 		.begin()
* 		.end()
* 		.rbegin() .rend()   逆向迭代器调用
* 		.erase()        区间删除    参数是迭代器
* 		.clear()        全部删除
* 		.insert()       插入   参数是迭代器
*/

class Object
{
public:
	Object();
	Object(uint64_t id, int32_t value);
	void print_(void);
	uint64_t getid(void);
private:
	uint64_t id;
	int32_t  value;
};


void init(void)
{
	vector<Object>  voc(10);     // 创建一个vector，里面有10个Object类型的元素

	for (int i = 0; i<voc.size(); i++)
	{
		voc[i] = Object(i, rand());
	}

	for (vector<Object>::iterator it = voc.begin(); it != voc.end(); it++)
	{
		it->print_();
	}
	cout << endl;

	/**
	* 删除第3个元素
	*/
	voc.erase(voc.begin() + 2);
	for (vector<Object>::iterator it = voc.begin(); it != voc.end(); it++)
	{
		it->print_();
	}
	cout << endl;

	/**
	* 删除id=6的元素
	*/
	for (vector<Object>::iterator it = voc.begin(); it != voc.end(); )
	{
		if (it->getid() == 6)
		{
			it = voc.erase(it);            // 使用迭代器删除元素之后，迭代器会自动向下偏移1个单位，同时返回
		}
		else
		{
			it++;
		}
	}
	for (vector<Object>::iterator it = voc.begin(); it != voc.end(); it++)
	{
		it->print_();
	}
	cout << endl;

	/**
	 * 在第一个元素后面插入一个新的对象
	 */
	Object obj(100, rand());
	voc.insert(voc.begin()+1, obj);

	/**
	 * 在第二个元素之后插入3个相同的对象
	 */
	Object objs(99, rand());
	voc.insert(voc.begin()+2, 3, objs);
	for (vector<Object>::iterator it = voc.begin(); it != voc.end(); it++)
	{
		it->print_();
	}
	cout << endl;
}


int main(int argc, char const *argv[])
{
	vector<int>  data;

	cout << data.size() << endl;

	data.push_back(111);
	data.push_back(222);
	data.push_back(999);

	data.front() = 0;
	data.back() = 10;

	while (data.size() > 0)
	{
		cout << "最后一个元素是： " << data.back() << endl;
		data.pop_back();
	}

	cout << data.size() << endl;

	init();

	system("pause");
	_CrtCheckMemory();
	return 0;
}


Object::Object()
{
	this->id = 0;
	this->value = 0;
}

Object::Object(uint64_t id, int32_t value)
{
	this->id = id;
	this->value = value;
}


void Object::print_(void)
{
	cout << "<" << this->id << " , " << this->value << ">   ";
}

uint64_t Object::getid(void)
{
	return this->id;
}
