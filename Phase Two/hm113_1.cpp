/*4.2.8 静态成员
静态成员就是在成员变量和成员函数前加上关键字static，称为静态成员
静态成员分为：
  静态成员变量：
    1.所有对象共享同一份数据（一个改了，全都变了）
    2.在编译阶段分配内存（在双击之前，内存在全局区）
    3.类内声明，类外初始化
  
  静态成员函数：
    1.所有对象共享同一个函数
    2.静态成员函数只能访问静态成员变量
*/
#include <iostream>
using namespace std;

class Person
{
public:
    //静态成员变量
    static int m_A;

    //静态成员变量也是有访问权限的
private:
    static int m_B;
};

int Person :: m_A = 100;//类外初始化
int Person :: m_B = 200;

void test01()
{
    Person p1;
    cout << p1.m_A <<endl;

    Person p2;
    p2.m_A = 200;
    cout << p1.m_A <<endl;//p2变了，p1也变
}

void test02()
{
    //静态成员变量 不属于某个对象上 所有对象都共享同一份数据
    //因此静态成员变量有两种访问方式

    //1.通过对象进行访问
    Person p;
    cout << p.m_A <<endl;

    //2.通过类名进行访问(不需要创建一个具体对象了)
    cout << Person :: m_A <<endl;
    
    //cout << Person :: m_B <<endl;  错误代码 因为是private

}

int main()
{
    //test01();
    test02();

    return 0;
}