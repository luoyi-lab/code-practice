/*4.3 C++对象模型和this指针

4.3.1 成员变量和成员函数分开存储
  在C++中，类内的成员变量和成员函数分开存储
  只有非静态成员变量才属于类的对象上
*/
#include <iostream>
using namespace std;

//成员变量和成员函数分开存储
class Person
{
    int m_A;//非静态成员变量 属于类的对象上

    static int m_B;//静态成员变量 不属于某个对象上 所以对象内存空间没有它

    void func(){}//非静态成员函数 不属于类的对象上
    
    static void func2(){}//静态成员函数 不属于类的对象上 二三四这两个都属于大家共享 一份 不属于某个对象上

};

int Person :: m_B = 0;

/*void test01()
{
    Person p1;

    cout << sizeof(p1) <<endl;// class里啥都没有的空对象 占用内存空间为1 是为了区分空对象占内存的位置 每个空对象也有自己独一无二的内存地址

}*/

void test02()
{
    Person p2;

    cout << sizeof(p2) <<endl;//不是空的 class里有啥就按啥来分配内存

}

int main()
{
    //test01();
    test02();
    return 0;
}