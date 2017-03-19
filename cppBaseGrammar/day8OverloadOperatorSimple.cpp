#include <iostream>

using namespace std;

/**
 * 运算符重载
 * 		* 全局函数（友元函数）实现，在重载<<、>>的时候只能通过友元函数实现
 * 		* 成员函数实现
 */

class Location
{
	/**
	 * 定义一个点坐标
	 * 用成员函数实现重载-，前置--，后置--
	 * 用全局函数实现重载+，前置++，后置++
	 * 用全局函数实现重载<<
	 */
public:
	Location(int x=0, int y=0)
	{
		this->x = x;
		this->y = y;
	}
	Location(const Location& nl)
	{
		this->x = nl.x;
		this->y = nl.y;
	}
	~Location(){}
	void showLocation(void)
	{ cout << "( " << this->x << "," << this->y << " )" << endl; }

	// 重载-运算符(二元运算符)
	Location operator-(const Location& nl);
	// 重载前置--运算符(一元运算符)
	Location& operator--(void);
	// 重载后置--运算符(一元运算符)
	Location operator--(int);  // 需要使用占位符
private:
	int x;
	int y;

	friend Location operator+(const Location& l1, const Location& l2);
	friend Location& operator++(Location& l);
	friend Location operator++(Location& l,int);
	friend ostream& operator<<(ostream& out, const Location& l);
};

// 使用友元函数重载<<运算符
ostream& operator<<(ostream& out, const Location& l)
{
	out << "点的坐标是：(" << l.x << " , " << l.y << " )" << endl;

	return out;
}


// 使用友元函数重载+运算符
Location operator+(const Location& l1, const Location& l2)
{
	Location temp(l1.x-l2.x, l1.y-l2.y);

	return temp;
}

// 使用友元函数重载前置++运算符
Location& operator++(Location& l)
{
	l.x ++;
	l.y ++;

	return l;
}

// 使用友元函数重载后置++运算符
Location operator++(Location& l, int)
{
	Location temp(l.x, l.y);

	l.x++;
	l.y++;

	return temp;
}



int main(int argc, char const *argv[])
{
	Location l1(128, 55);
	Location l2(45, 90);

	l1.showLocation();
	l2.showLocation();

	Location l3 = l1-l2;
	l3.showLocation();

	--l1;
	l1.showLocation();

	l1--;
	l1.showLocation();

	++l2;
	l2.showLocation();

	l2++;
	l2.showLocation();

	cout << l1 << l2 << l3;
	cout << endl;

	return 0;
}

// 重载后置--运算符
Location Location::operator--(int)
{
	Location temp(this->x, this->y);
	this->x --;
	this->y --;

	return temp;
}


// 重载前置--运算符
Location& Location::operator--(void)
{
	this->x --;
	this->y --;
	return *this;
}


// 重载-运算符
Location Location::operator-(const Location& nl)
{
	/**
	 * 返回值和返回引用是不同的结果
	 */
	Location temp(this->x-nl.x, this->y-nl.y);

	return temp;
}

