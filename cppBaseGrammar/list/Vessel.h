#pragma once

#include <iostream>

using namespace std;

/*
һ������������
	���أ� []   =     <<      +
*/

template <typename ElementType>
class Vessel
{
	friend ostream & operator<< <ElementType>(ostream &out, Vessel<ElementType>& vx); // ����<<
public:
	Vessel(int size=0);                    // ���캯��
	Vessel(Vessel<ElementType> &vx);       // ��������
	~Vessel();                             // ��������
	ElementType& operator[](int index);    // ����[]
	Vessel<ElementType>& operator=(Vessel<ElementType>& vx);  // ����=
	Vessel<ElementType> operator+(Vessel<ElementType>& vx);   // ����+
	int length(void);

	bool append(ElementType &ne);
	bool insert(int index, ElementType &ne);
	bool pop(ElementType &ne);
private:
	int size;
	ElementType *ep;
};
