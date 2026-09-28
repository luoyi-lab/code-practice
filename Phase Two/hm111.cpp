/*4.2.6 初始化列表
作用：
C++ 提供了初始化列表语法，用来初始化属性

语法：构造函数():属性1(值1)，属性2(值2) ... {}
*/
#include <iostream>
using namespace std;
#include <string>

class Person
{
public:

    //传统初始化操作
    /*Person(int a , int b ,int c)
    {
        m_A = a;
        m_B = b;
        m_C = c;
    }*/
    
    //初始化列表初始化属性
    /*Person():m_A(10),m_B(20),m_C(30)
    {

    }
     以上是第一种无法修改值*/
    Person(int a , int b , int c):m_A(a),m_B(b),m_C(c)//更灵活
    {

    }
    
    int m_A;
    int m_B;
    int m_C;
};

void test01()
{
    //Person p(10 , 20 ,30); 传统初始化操作
    Person p(20 , 40 , 80);
    cout << "m_A=" << p.m_A <<" m_B=" << p.m_B << " m_C=" << p.m_C <<endl;
}

int main()
{
    test01();

    return 0;
}