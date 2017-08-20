#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "Vessel.cpp"

using namespace std;

/*
如果类中有动态申请的空间，则需要注意拷贝构造和重载=运算符
*/
class Object
{
	friend ostream& operator<<(ostream &out, Object &obj);  // 重载<<运算符
public:
	Object();
	Object(char *name, int value);
	Object(const Object &obj);
	~Object();
private:
	char name[65];
	int value;
};


void main()
{
	Vessel<int> list(10);
	list[0] = 0;
	list[1] = 1;
	list[2] = 2;
	list[3] = 3;
	list[4] = 4;

	for (int i = 0; i < 10; i++)
	{
		cout << list[i] << "   ";
	}
	cout << endl;


	Vessel<Object> lists(10);
	lists[0] = Object("obj1", 1);
	lists[1] = Object("obj2", 2);
	lists[2] = Object("obj3", 3);
	lists[3] = Object("obj4", 4);
	lists[4] = Object("obj5", 5);
	lists[5] = Object("obj6", 6);
	lists[6] = Object("obj7", 7);

	for (int i = 0; i < 10; i++)
	{
		cout << lists[i] << "  ";
	}
	cout << endl;

	cout << lists << endl;

	system("pause");
}


Object::Object()
{
	sprintf(this->name, "");
	this->value = 0;
}

Object::Object(char *name, int value)
{
	sprintf(this->name, name);
	this->value = value;
}

Object::Object(const Object &obj)
{
	sprintf(this->name, obj.name);
	this->value = value;
}

Object::~Object()
{
}


// 友元函数时全局函数，不需要加域操作符
ostream& operator<<(ostream &out, Object &obj)
{
	char buff[1024];
	sprintf(buff, "<name:%s, value:%d>", obj.name, obj.value);
	out << buff;

	return out;
}

