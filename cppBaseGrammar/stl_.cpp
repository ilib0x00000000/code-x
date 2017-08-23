#include <iostream>

using namespace std;

/**
 * @Coding  : utf-8
 * @Date    : 2017-08-23 09:25:30
 * @Author  : ilib0x00000000
 * @Email   : ilib0x00000000@aliyun.com
 * @Link    : https://github.com/ilib0x00000000
 * @Version : 0.1
 */

class Object
{
public:
	Object(char *name, int value)
	{
		sprintf(this->name, name);
		this->value = value;
	}

	void print_()
	{
		cout << "Object<" << this->name << "> value: " << this->value << endl;
	}
private:
	int value;
	char name[64];
};


/**
 * 容器使用
 * 迭代器是与容器相关的，所以在声明迭代器时，要指定容器类型（以及容器中元素的类型）
 */
void vector_demo(void)
{
	vector<int>   vt;    // 创建一个元素类型是int的容器对象

	vt.push_back(111);   // 向容器中添加一个元素
	vt.push_back(222);
	vt.push_back(333);

	// 使用迭代器输出容器元素
	for (vector<int>::iterator it = vt.begin(); it != vt.end(); it++)
	{
		cout << *it << "    ";
	}

	// 使用算法接口，查找元素个数
	int all = count(vt.begin(), vt.end(), 222);
	cout << "元素222共出现： " << all << "次" << endl;


	Object fruit("水果", 36);
	Object vegetables("蔬菜", 14);
	Object tea("茶叶", 82);

	vector<Object> food;      // 创建一个元素是Object类型的容器
	food.push_back(fruit);
	food.push_back(vegetables);
	food.push_back(tea);

	// 使用迭代器遍历容器
	for (vector<Object>::iterator it = food.begin(); it != food.end(); it++)
	{
		it->print_();
	}


	Object *pobj1 = &fruit;
	Object *pobj2 = &vegetables;
	Object *pobj3 = &tea;

	vector<Object *> pfd;        // 容器元素是指针类型
	pfd.push_back(pobj1);
	pfd.push_back(pobj2);
	pfd.push_back(pobj3);

	// 使用迭代器遍历容器
	for (vector<Object *>::iterator it = pfd.begin(); it != pfd.end(); it++)
	{
		(*it)->print_();
	}

}


int main(int argc, char const *argv[])
{
	vector_demo();

	system("pause");
	_CrtCheckMemory();
	return 0;
}