/*4.5.2 左移运算符重载
作用：可以输出自定义数据类型 Person p1; p1.m_A = 10; p1.m_B = 20;  cout << p1 << endl;
*/
#include <iostream>
using namespace std;
#include <string>

class Person 
{
friend ostream & operator<<(ostream &cout , Person p);
friend void test01();

private:
    //利用成员函数重载左移运算符  p.operator<<(cout) 简化形式为 p << cout 错误的
    //cout.operator<<(p1) 也不行 让 cout 去调用它自己的 << 函数，把 p1 当作参数传进去 不行 cout属于C++自定义的类 不能自己乱改
    //故不能利用成员函数重载左移运算符
    /*void operator<< (cout)
    {

    }*/

    int m_A;
    int m_B;
};

//全局函数为什么能完美解决？
//全局函数最大的特点就是：没有 this 指针，没有主调对象，所有东西都是平等的参数。全局函数的翻译规则是：直接把左边和右边按顺序塞进括号里。
ostream & operator<<(ostream &cout , Person p)//本质 operator<<(cout , p) 简化形式为：cout << p   &cout为什么要用引用的方式 因为cout这个对象全局只能有一个  因为是引用 所以也可以&out 引用是起别名
{
    cout << "m_A=" << p.m_A <<" m_B=" << p.m_B <<endl;
    return cout;//返回的时候，也绝对不能拷贝，必须把原本的 cout 原封不动地交回去 ostream &
}

void test01()
{
    Person p;
    p.m_A = 10;
    p.m_B = 20;

    cout << p <<endl;
}

int main()
{
    test01();
    return 0;
}