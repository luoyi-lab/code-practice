/*4.5 运算符重载
  概念：对已有的运算符重新进行定义 赋予其另一种功能 以适应不同的数据类型

4.5.1 加号运算符重载
  作用：实现两个自定义数据类型相加的运算
*/
#include <iostream>
using namespace std;
#include <string>

//加号运算符重载
//1.成员函数重载+号
//2.全局函数重载+号
class Person
{
public: 
    //1.成员函数重载+号
    Person operator+ (Person &p)//Person：参数的数据类型  &：引用传递 意味着参数 p 是传入对象（p2）的一个别名，而不是一份拷贝 
    {
        Person temp;
        temp.m_A = this->m_A + p.m_A;
        temp.m_B = this->m_B + p.m_B;
        return temp;
    }

    int m_A;
    int m_B;
};

//2.全局函数重载+号  需要传两个值
Person operator+ (Person &p1 , Person &p2)
{
    Person temp;
    temp.m_A = p1.m_A + p2.m_A;
    temp.m_B = p1.m_B + p2.m_B;
    return temp;
}

//函数重载的版本 在同一个作用域内，允许存在多个名字相同，但参数列表不同的函数。
Person operator+ (Person &p1 , int num)
{
    Person temp;
    temp.m_A = p1.m_A + num;
    temp.m_B = p1.m_B + num;
    return temp;
}

void test01()
{
    Person p1;
    p1.m_A = 10;
    p1.m_B = 20;

    Person p2;
    p2.m_A = 30;
    p2.m_B = 40;

    Person p3 = p1 + p2;//编译器强制翻译为Person p3 = p1.operator+(p2); （1.成员函数） 或者 Person p3 = operator+(p1, p2); （2.全局函数）
    cout << "p3.m_A = " << p3.m_A <<endl;
    cout << "p3.m_B = " << p3.m_B <<endl;

    //运算符重载 也可以发生函数重载
    Person p4 = p1 + 100;//Person + int 
    cout << "p4.m_A = " << p4.m_A <<endl;
    cout << "p4.m_B = " << p4.m_B <<endl;
}

int main()
{
    test01();
    return 0;
}