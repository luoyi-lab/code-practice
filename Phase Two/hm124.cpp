/* 4.5.4 赋值运算符重载
C++ 编译器至少给一个类添加4个函数
  1.默认构造函数（无参，函数体为空）
  2.默认析构函数（无参，函数体为空）
  3.默认拷贝构造函数，对属性进行值拷贝
  4.赋值运算符 operator= ，对属性进行值拷贝

  如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝的问题
  关于深浅拷贝的问题：
  浅拷贝就是：两个变量对象指向是用一个内存地址 有一个delete之后另一个再delete就会崩溃报错（即堆区内存重复释放的问题）
  深拷贝就是new一个全新的内存地址 两个变量的内容一样 但是内存地址不一样 这样就不会出现崩溃的问题
*/
#include <iostream>
using namespace std;
#include <string>

//赋值运算符的重载
class Person
{
public:
    Person(int age)
    {
        m_Age = new int(age); //向堆区申请了一块内存地址 用来装一个int类型数据 即传进来的age 然后把这个地址交给m_Age指针来保管
    }

    ~Person()
    {
        if (m_Age != NULL)   //在析构函数释放堆区内存
        {
            delete m_Age;
            m_Age = NULL;
        }
    }

    //重载 赋值运算符=
Person& operator= (Person &p)
{
    //编译器是浅拷贝 即m_Age = p.m_Age  即把旧指针指向的内存地址原封不动给了新的对象

    //应该先判断是否有属性在堆区，如果有，先释放干净，然后再进行深拷贝
    if(m_Age != NULL)
    {
        delete m_Age; // 把 p2 原来指向的 0x222 拆了
        m_Age = NULL;
    }

    //深拷贝
    m_Age = new int( *p.m_Age);

    //返回对象本身
    return *this;
}

    int* m_Age;
};


void test01()
{
    Person p1(18);
    Person p2(20); //  等价于p2.operator=(p1)
    Person p3(30);

    p3 = p2 = p1;

    cout << "p1的年龄为：" << *p1.m_Age <<endl;
    cout << "p2的年龄为：" << *p2.m_Age <<endl;
    cout << "p3的年龄为：" << *p3.m_Age <<endl;

}

int main()
{
    test01();
    return 0;
}