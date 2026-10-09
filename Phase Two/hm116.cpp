/*4.3.3 空指针访问成员函数
C++中空指针也是可以调用成员函数的，但是也要注意有没有用到this指针
如果用到this指针 需要加以判断保证代码的健壮性
*/
#include <iostream>
using namespace std;

class Person
{
public:
    Person(int age)
    {
        m_Age = age;
    }

    void showClassName()
    {
        cout << "this is Person class" <<endl;
    }  

    void showPersonAge()
    {
        cout << "age = " << m_Age <<endl;
    }
    int m_Age;
};

void test01()
{
    Person p1(18); 
    Person * p = &p1;
    p->showClassName();
    p->showPersonAge();
} 

int main()
{
    test01();
    return 0;
}