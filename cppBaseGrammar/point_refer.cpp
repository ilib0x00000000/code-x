#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

/**
* @Coding  : utf-8
* @Date    : 2017-08-06 08:09:49
* @Author  : ilib0x00000000
* @Email   : ilib0x00000000@aliyun.com
* @Link    : https://github.com/ilib0x00000000
* @Version : 0.1
*/

/*指针引用*/

struct User 
{
	char name[64];
	int age;
};

void create_user(struct User *&vip)
{
	/**
	 * 形参是一个指针的引用，即可用把形参当做实参使用，但形参的本质是升阶了
	 */
	vip = (struct User *)malloc(sizeof(struct User));
	vip->age = 100;
	strcpy(vip->name, "ilib0x00000000");

	return ;
}

int main(int argc, char const *argv[])
{
	struct User *vip = NULL;

	create_user(vip);

	cout << "用户名是： " << vip->name << endl;
	cout << "用户年龄是： " << vip->age << endl;



	system("pause");
	return 0;
}