#include <string>
#include <vector>
#include <iostream>

using namespace std;
using std::string;
using std::vector;


void vector_init(void);
void iterator_test(void);
void array_diff(void);


int main(int argc, char const *argv[])
{
	vector_init();
	iterator_test();
	array_diff();

	return 0;
}


void vector_init(void)
{
	/**
	 * 字符串，容器vector，迭代器和数组
	 *
	 * 标准库类型vector表示对象的集合，其中所有对象的类型都相同
	 * 
	 * 定义和初始化vector对象：
	 * vector<T>  v1;         
	 * vector<T>  v2(v1);
	 * vector<T>  v2 = v1;
	 * vector<T>  v3(n ,val);
	 * vector<T>  v4(n);
	 * vector<T>  v5{a, b, c...}
	 * vector<T>  v5={a, b, c...}
	 *
	 * vector支持的操作：
	 * v.empty()
	 * v.size()      返回值类型： vector<Type>::size_type
	 * v.push_back(t)
	 * v[n]
	 */
	
	vector<int>  v1;   // 定义一个未知长度的容器
	vector<int>  v2(v1);
	vector<int>  v3 = v1;

	vector<char>  v4(10, 'c');
	vector<char>  v5(8);

	vector<string> v6 {"a", "b", "c", "d"};           // C++11标准
	vector<string> v7 = {"this", "is", "a", "word"};  // C++11标准

	cout << "v7的长度是： " << v7.size() << endl;
	v7.push_back("new world");
	cout << "v7的长度是： " << v7.size() << endl;
}

void iterator_test(void)
{
	/**
	 * 迭代器（指针）：
	 * C++中用来实现访问容器元素的机制
	 *
	 * 返回容器的第一个元素： auto first = vect.begin();
	 * 返回容器的最后一个元素的下一个元素： auto last = vect.end();
	 *
	 * 迭代器函数返回的对象的类型是：
	 * 		vector<Type>::iterator
	 * 		vector<Type>::const_iterator   只读
	 *
	 * 返回只读迭代器类型：vector<Type>::const_iterator
	 * 		cbegin()
	 * 		cend()
	 *
	 * 迭代器操作：
	 * 	*iter        返回迭代器iter所指向的元素
	 * 	iter->mem    相当于(*iter).mem，访问迭代器指向的对象的元素
	 * 	++iter
	 * 	--iter
	 * 	iter +/-(=) n
	 * 	iter1 +/- iter2
	 *
	 * 两个迭代器相减的结果的类型是： difference_type(带符号整型数)
	 */ 
	
	vector<string> vs = {"this", "is", "a", "word"};
	// auto  first = vs.begin();
	// auto  endoff = vs.end();

	vector<string>::iterator first = vs.begin();
	vector<string>::iterator endoff = vs.end();


	cout << "第一个元素是： " << *first << endl;

	while(first != endoff)
	{
		cout << *first << "  ";
		++first;
	}
	cout << endl;
}


void array_diff(void)
{
	/**
	 * 数组：
	 * 与C语言中数组概念差不多
	 *
	 * 新增函数：
	 * 	begin(array): 返回数组的首元素地址
	 * 	end(array): 返回数组的最后一个元素的下一个元素地址
	 */
	int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *first = begin(arr);
	int *endoff = end(arr);

	ptrdiff_t distance;

	distance = endoff-first;
	cout << "尾元素的下一个元素距离第一个元素的距离是： " << distance << endl;
}
