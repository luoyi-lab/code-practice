/*4.3.4 const修饰成员函数（const 只读）
常函数：
  成员函数后加const后 我们称这个函数为常函数
  常函数内不可以修改成员属性
  成员属性声明时加关键字 mutable后，在常函数中依然可以修改 常对象中也可以修改

常对象：
  声明对象前加const称该对象为常对象
  常对象只能调用常函数
*/
#include <iostream>
using namespace std;

//常函数
class Person
{
public:
    Person() : m_A(0), m_B(0) 
    {

    }

    //函数里面有一个隐藏的this指针 本质是指针常量 指针的指向地址是不可以修改的 但指向的值是可以修改的 不加const时 函数内可以修改m_A的值
    //const Person * const this;第一个const让值都无法修改（常量指针） 第二个const让指向无法修改（本来就有了 this指针自带的 this指针的本质是一个指针常量） 第一个const就是函数后的那个const
    //在成员函数后面加const，修饰的是this指针，让指针指向的值也不可修改
    //复习：this->m_A 一般出现在 C++ 类里面，意思就是：访问“当前这个对象”的成员变量 m_A。
    void showPerson() const
    {
        //m_A = 100;错误
        //this->m_A;
        m_B = 100;
    }

    void func()
    {
        m_A = 100;
    }

    int m_A;
    mutable int m_B;//特殊变量，即使在常函数或常对象中 也可以修改这个值
};

void test01()
{
    Person p;
    p.showPerson();
}

//常对象
void test02()
{
    const Person p1;//加const 变为常对象
    //p1.m_A = 100;错误
    p1.m_B = 100;

    //常对象只能调用常函数
    p1.showPerson();
    //p1.func(); 错误 非常函数
}

int main()
{
    test01();
    test02();
    return 0;
}