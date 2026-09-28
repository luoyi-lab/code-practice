/*4.2.5 深拷贝与浅拷贝
深浅拷贝是面试经典问题 也是常见的一个坑

  浅拷贝：简单的赋值拷贝操作
  深拷贝：在堆区重新申请空间，进行拷贝操作
*/
#include <iostream>
using namespace std;
#include <string>

class Person
{
public:
    Person()
    {
        cout << "Person的默认构造函数调用" <<endl;
    }

    Person(int age , int height)
    {
        m_Age = age;

        m_Height = new int(height);//在堆区申请了一块 int 大小的内存，存入 height 的值（比如180），并把这个内存的地址返回给指针 m_Height
        cout << "Person的有参构造函数调用" <<endl;
    }

    //自己实现拷贝构造函数 解决浅拷贝带来的问题
    Person(const Person &p)
    {
        cout << "Person的拷贝构造函数调用" <<endl;
        m_Age = p.m_Age;
        //m_Height = p.m_Height 这是编译器默认实现的代码，两个对象的指针指向同一个堆区地址 

        m_Height = new int (*p.m_Height);//取出 p 指向的堆区里的值（180）。然后在堆区重新申请一块新地址，把这个值（180）放进去，把新地址交给自己的 m_Height
    }

    ~Person()
    {
        //析构代码，将堆区开辟的数据做释放操作
        if(m_Height != NULL)//如果不为空
        {
            delete m_Height;
            m_Height = NULL;//明确告诉后续的代码：“这个指针现在不指向任何地方了，千万别用它”
        }
        cout << "Person的析构函数调用" <<endl;
    }

    int m_Age;//年龄 存在栈区，随对象生随对象死
    int* m_Height;//身高 指针 指向堆区的一块内存
};

void test01()
{
    Person p1(18 , 180);
    cout << "p1的年龄为" << p1.m_Age <<endl;
    cout << "p1的身高为" << *p1.m_Height <<endl;// 内存状态：p1.m_Age = 18, p1.m_Height 指向堆区地址 A（存着 180）


    Person p2(p1);//当没有自己写构造函数时 编译器提供默认拷贝构造函数  浅拷贝
    cout << "p2的年龄为" << p2.m_Age <<endl;
    cout << "p2的身高为" << *p2.m_Height <<endl;// p2.m_Height 指向堆区地址 B（存着 180，这是全新申请的地址，和 A 不同！）
    //浅拷贝带来的问题：堆区的内存被重复释放 p2释放了一次，p1又释放一次。要利用深拷贝进行解决，堆区开辟一块新地址内存，东西一样，地址不一样，避免重复释放
}

int main()
{
    test01();

    return 0;
}