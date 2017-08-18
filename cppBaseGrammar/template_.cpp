#include <iostream>

using namespace std;

/**
 * @Coding  : utf-8
 * @Date    : 2017-08-18 11:04:38
 * @Author  : ilib0x00000000
 * @Email   : ilib0x00000000@aliyun.com
 * @Link    : https://github.com/ilib0x00000000
 * @Version : 0.1
 */

/**
 * 函数模板语法： template <typename XXXX> return_ func_name(XXXX a, XXXX *b, XXXX &c) { }
 * 函数模板使用： 
 * 		1. 显示调用              func_name<type>(....);
 * 		2. 自动识别调用          func_name(.....);
 */

template <typename T>void swap_(T& a, T& b)
{
	T c;
	c = a;
	a = b;
	b = c;
}

/**
 * 完成一个数组的排序和输出
 */
template <typename ElementType, typename LengthType> int sort_(ElementType *array, LengthType size)
{
	ElementType temp;

	if(!array)
	{
		return -1;
	}

	for(LengthType i=0; i<size; i++)
	{
		for(LengthType j=i+1; j<size; j++)
		{
			if(array[i] < array[j])
			{
				swap_<ElementType>(array[i], array[j]);   // 交换两个元素				
			}
		}
	}
	return 0;
}

template <typename ElementType> void print_(ElementType *array, int size)
{
	for(int i=0; i<size; i++)
	{
		cout << array[i] << " ";
	}
}


int main(int argc, char const *argv[])
{
	int a = 10;
	int b = 20;
	swap_<int>(a, b);
	cout << a << "-----" << b << endl;

	double c = 1.1;
	double d = 9.9;
	swap_<double>(c, d);
	cout << c << "-----" << d << endl;


	bool x = false;
	bool y = true;
	swap_(x, y);
	cout << x << "----" << y << endl;


	int *pi = new int[10];
	pi[0] = 452;
	pi[1] = 15;
	pi[2] = 91;
	pi[3] = 644;
	pi[4] = 2;
	pi[5] = 72;
	pi[6] = 33;
	pi[7] = 2;
	pi[8] = 64;
	pi[9] = 80;
	sort_<int, int>(pi, 10);
	print_<int>(pi, 10);
	delete [] pi;

	cout << "---------------------------------------------------------------------------------------------------------" << endl;


	double pd[] = {1.215, 510.3, 465, 3.0, 6.45, 713, 34.8, 8.46, 9.22};
	sort_<double, int>(pd, sizeof(pd)/sizeof(double));
	print_<double>(pd, sizeof(pd)/sizeof(double));


	system("pause");
	return 0;
}