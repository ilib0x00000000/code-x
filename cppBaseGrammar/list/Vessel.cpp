#include "Vessel.h"

#include <iostream>

using namespace std;

template <typename ElementType>
Vessel<ElementType>::Vessel(int size=0)
{
	this->size = size;
	this->ep = new ElementType[size];
}

template <typename ElementType>
Vessel<ElementType>::Vessel(Vessel<ElementType> &vx)
{
	if (this->ep)
	{
		delete[] this->ep;
		this->ep = NULL;
	}

	this->size = vx.size;
	this->ep = new ElementType[this->size];

	for (i = 0; i < this->size; i++)
	{
		this->ep[i] = vx.ep[i];
	}
}

template <typename ElementType>
Vessel<ElementType>::~Vessel()
{
	if (this->ep)
	{
		delete[] this->ep;
		this->ep = NULL;
	}

	this->size = 0;
}

template <typename ElementType>
ElementType& Vessel<ElementType>::operator[](int index)    // ����[]
{
	// ����[]���ص����ݼ�Ҫ������ֵ��ҲҪ������ֵ
	// ���Է���Ԫ�ص�����
	return this->ep[index];
}


template <typename ElementType>
Vessel<ElementType>& Vessel<ElementType>::operator=(Vessel<ElementType>& vx)  // ����=
{
	if (this->ep)
	{
		delete[] ep;
		this->ep = NULL;
	}

	this->size = vx.size;
	this->ep = new ElementType[vx.size];

	for (int i = 0; i < vx.size; i++)
	{
		this->ep[i] = vx.ep[i];
	}

	return *this;
}


template <typename ElementType>
Vessel<ElementType> Vessel<ElementType>::operator+(Vessel<ElementType>& vx)   // ����+
{
	int leng = this->size + vx.size;    // �������ĳ���
	Vessel<ElementType> new_vs(leng);   // ����������

	for (int i = 0; i < this->size; i++)
	{
		new_vs.ep[i] = this->ep[i];
	}
	for (int i = 0; i < vx.size; i++)
	{
		new_vs.ep[i + this->size] = vx.ep[i];
	}

	return new_vs;            // ����ÿ�������
}

template <typename ElementType>
int Vessel<ElementType>::length(void)
{
	return this->size;
}

template <typename ElementType>
bool Vessel<ElementType>::append(ElementType &ne)
{
	return false;
}

template <typename ElementType>
bool Vessel<ElementType>::insert(int index, ElementType &ne)
{
	return false;
}

template <typename ElementType>
bool Vessel<ElementType>::pop(ElementType &ne)
{
	return false;
}

/*
��Ԫ������ʵ�֣�������Ԫ������ȫ�ֺ��������Բ���Ҫ�������÷�
*/
template <typename ElementType>
ostream& operator<<(ostream &out, Vessel<ElementType>& vx)  // ����<<
{
	// ��������ĳ��ȴ���5������ʾǰ3�������2��
	if (vx.size > 5)
	{
		for (int i = 0; i < 3; i++)
		{
			out << vx[i] << " ";
		}

		out << "... ";

		out << vx[vx.size - 2] << " ";
		out << vx[vx.size - 1] << " ";
	}
	else
	{
		for (int i = 0; i < vx.size; i++)
		{
			out << vx[i] << "  ";
		}
	}

	return out;
}

