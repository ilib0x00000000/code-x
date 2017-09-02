#include <set>
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

/**
 * @Coding  : utf-8
 * @Date    : 2017-08-25 10:51:00
 * @Author  : ilib0x00000000
 * @Email   : ilib0x00000000@aliyun.com
 * @Link    : https://github.com/ilib0x00000000
 * @Version : 0.1
 */


/**
 * set： 集合  元素唯一  自动排序  红黑树
 *
 * api:
 *      .insert()     返回值：对组
 *      .begin()
 *      .end()
 *      .empty()
 *      .erase()
 *      .find()         返回迭代器
 *      .count()        返回1或0
 *      .lower_bound(element)  返回第一个>=element元素的迭代器
 *      .upper_bound(element)  返回第一个>element元素的迭代器
 *      .equal_range(element)  返回一个对组，每个元素都是迭代器
 */

class Object
{
public:
    Object(char *name, int value) : value(value)
    {
        strcpy(this->name, name);
    }
public:
    char name[64];
    int value;
};


// 仿函数： 就是一个重载了()运算符的类
class ObjectCompile
{
public:
    bool operator()(const Object& obj1, const Object& obj2)
    {
        if(obj1.value > obj2.value)
        {
            return true;
        }

        return false;
    }
};


void set_demo(void)
{
    set<int> st;                // 默认集合是按从小到大排序的
    set<int, less<int>> desc;   // 相当于上面

    st.insert(rand());
    st.insert(rand());
    st.insert(rand());
    st.insert(rand());
    st.insert(rand());

    for(set<int>::iterator it=st.begin(); it!=st.end(); it++)
    {
        cout << *it << "  ";
    }
    cout << endl;


    set<int, greater<int>> dest;        // 从大到小排序的集合

    dest.insert(rand());
    dest.insert(rand());
    dest.insert(rand());
    dest.insert(rand());

    // clion + MinGW下可以编译通过
    // vs2015编译错误
    for(set<int, greater<int>>::iterator it=dest.begin(); it!=dest.end(); it++)
    {
        cout << *it << "  ";
    }
    cout << endl;


    // 自定义一个集合的排序方法
    Object obj1("obj1", 12);
    Object obj2("obj2", 34);
    Object obj3("obj3", 16);
    Object obj4("obj4", 84);
    Object obj5("obj5", 60);

    set<Object, ObjectCompile>  so;   // 这个集合中的元素是Object对象，排序方法是ObjectCompile

    so.insert(obj1);
    so.insert(obj2);
    so.insert(obj3);
    so.insert(obj4);
    so.insert(obj5);

    for(set<Object, ObjectCompile>::iterator it=so.begin(); it!=so.end(); it++)
    {
        cout << "Object<" << it->name << "  " << it->value << ">" << endl;
    }

    // 插入函数的返回值
    // std::pair<iterator, bool>
    Object objs("objs", 34);         // 仿函数中对比的是value值，所以value值相同的对象不会再插入集合中
    pair<set<Object, ObjectCompile>::iterator, bool> pib = so.insert(objs);
    if(pib.second)
    {
        cout << "successed!" << endl;
    } else
    {
        cout << "failed" << endl;
    }
}

void set_opt_demo(void)
{
    set<int> st;

    for(int i=0; i<10; i++)
    {
        st.insert(i+1);
    }

    set<int>::iterator it = st.find(8);
    cout << *it << endl;

    cout << "元素6出现的次数是： " << st.count(6) << endl;
    cout << "元素60出现的次数是： " << st.count(60) << endl;

    set<int>::iterator gt = st.lower_bound(5);   // >=5
    cout << *gt << endl;

    set<int>::iterator gr = st.upper_bound(5);   // >5
    cout << *gr << endl;

    pair<set<int>::iterator, set<int>::iterator> pii = st.equal_range(6);
    set<int>::iterator pf = pii.first;           // >=6
    cout << *pf << endl;

    set<int>::iterator pl = pii.second;          // >6
    cout << *pl << endl;

}


int main(int argc, char const *argv[])
{
    set_demo();
    set_opt_demo();

    // system("pause");
    // _CrtCheckMemory();
    return 0;
}