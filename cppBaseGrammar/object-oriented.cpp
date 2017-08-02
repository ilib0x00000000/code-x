#include"iostream"

using namespace std;

class Circle
{
public:
	Circle();
	~Circle();

private:
	int radius;   // �뾶
	double perimeter;  // �ܳ�
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
	Circle c;   // ����һ��ʵ������
	int radius;

	cout << "������뾶ֵ�� " << endl;
	cin >> radius;

	c.setRadius(radius);

	cout << "Բ�İ뾶�ǣ� " << c.getRadius() << endl;
	cout << "Բ���ܳ��ǣ� " << c.getPerimeter() << endl;
	cout << "Բ������ǣ� " << c.getArea() << endl;

	system("pause");
}