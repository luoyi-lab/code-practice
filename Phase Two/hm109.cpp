/*4.2.4 构造函数调用规则
默认情况下，C++编译器至少给一个类添加三个函数
  1.默认构造函数（无参，函数体为空）
  2.默认析构函数（无参，函数体为空）
  3.默认拷贝构造函数，对属性进行值拷贝

构造函数调用规则如下：
  如果用户定义有参构造函数，C++不再提供默认无参构造，但是会提供默认拷贝构造
  如果用户定义拷贝构造函数，C++不会再提供其他构造函数

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

    Person(int age)//有参构造函数
    {
        m_Age = age;
        cout << "Person的有参构造函数调用" <<endl;
    }

    Person (const Person & p)//拷贝构造函数
    {
        m_Age = p.m_Age;
        cout << "Person的拷贝构造函数调用" <<endl;
    }

    ~Person()
    {
        cout << "Person的析构函数调用" <<endl;
    }

    int m_Age;
};

/*void test01()
{
    Person p1;//调用默认构造函数
    p1.m_Age  = 18;

    Person p2(p1);//就算没写拷贝构造函数，编译器也会加一个默认拷贝构造函数
    cout << "p2年龄为" << p2.m_Age <<endl;
}*/

void test02()
{
    Person p1(28);

    Person p2(p1);

    cout << "p2年龄为" << p2.m_Age <<endl;
}

int main()
{
    //test01();
    test02();

    
    return 0;
}