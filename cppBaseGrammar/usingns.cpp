#include <iostream>
#include "drink.h"


using namespace std;

/**
 * 命名空间的使用：
 *
 * 1. using namespace xxxx;
 * 2. using xxxxx:****;
 */
using namespace kedaierboluo;
using kedaierboluo::User;


int main(int argc, char const *argv[])
{
	cout << "使用标准命名空间" << endl;
	
	User anoy;
	anoy.name = "ilib0x00000000";
	anoy.sex = 'f';
	anoy.age = 18;
	cout << "User的属性： name<" << anoy.name << "> sex<" << anoy.sex << "> age<" << anoy.age << ">" << endl;


	kedaierboluo::User vip;
	vip.name = "alex";
	vip.sex = 'm';
	vip.age = 20;
	cout << "User的属性： name<" << vip.name << "> sex<" << vip.sex << "> age<" << vip.age << ">" << endl;

	system("pause");
	return 0;
}