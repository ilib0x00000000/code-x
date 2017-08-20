#pragma once

#include <iostream>

using namespace std;

/*
一个容器数组类
	重载： []   =     <<      +
*/

template <typename ElementType>
class Vessel
{
	friend ostream & operator<< <ElementType>(ostream &out, Vessel<ElementType>& vx); // 重载<<
public:
	Vessel(int size=0);                    // 构造函数
	Vessel(Vessel<ElementType> &vx);       // 拷贝构造
	~Vessel();                             // 析构函数
	ElementType& operator[](int index);    // 重载[]
	Vessel<ElementType>& operator=(Vessel<ElementType>& vx);  // 重载=
	Vessel<ElementType> operator+(Vessel<ElementType>& vx);   // 重载+
	int length(void);

	bool append(ElementType &ne);
	bool insert(int index, ElementType &ne);
	bool pop(ElementType &ne);
private:
	int size;
	ElementType *ep;
};
