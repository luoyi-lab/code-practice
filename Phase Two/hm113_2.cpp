/*
  静态成员函数：
    1.所有对象共享同一个函数
    2.静态成员函数只能访问静态成员变量
*/
#include <iostream>
using namespace std;
#include <string>

class Person
{
public:
    static void func()
    {
        m_A = 100;//静态成员函数只能访问静态成员变量
        //m_B = 200; 无效 因为静态成员函数只能访问静态成员变量（可以直接通过类名访问） 而非静态成员变量是必须创建一个对象才可以去访问的
        cout << "static void func 调用" <<endl;
    }

    static int m_A;//静态成员变量
    int m_B;//非静态成员变量

    //静态成员函数也是有访问权限的
private:
    static void func2()
    {
        cout << "static void func2 调用" <<endl;
    }
};

int Person :: m_A = 0;//类外初始化

void test01()
{
    //1.通过对象进行访问
    Person p1;
    p1.func();

    //2.通过类名进行访问
    Person :: func();

    //Person :: func2(); 调用不了 类外访问不到私有的静态成员函数
}

int main()
{
    test01();
    return 0;
}