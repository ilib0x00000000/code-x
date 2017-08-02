#include"iostream"

using namespace std;

class Circle
{
public:
	Circle();
	~Circle();

private:
	int radius;   // 半径
	double perimeter;  // 周长
	double area;

public:
	void setRadius(int r)
	{
		radius = r;
		return ;
	}

	int getRadius(void)
	{
		return radius;
	}

	double getPerimeter(void)
	{
		return 3.14 * 2 * radius;
	}

	double getArea(void)
	{
		return 3.14 * radius * radius;
	}
};

Circle::Circle()
{
}

Circle::~Circle()
{
}

void main()
{
	Circle c;   // 创建一个实例对象
	int radius;

	cout << "请输入半径值： " << endl;
	cin >> radius;

	c.setRadius(radius);

	cout << "圆的半径是： " << c.getRadius() << endl;
	cout << "圆的周长是： " << c.getPerimeter() << endl;
	cout << "圆的面积是： " << c.getArea() << endl;

	system("pause");
}