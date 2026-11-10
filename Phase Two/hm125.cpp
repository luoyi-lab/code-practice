/* 4.5.5 关系运算符重载 > < = 等等
作用：重载关系运算符 可以让两个自定义类型的对象进行对比操作（比如两个类比较）
*/
#include <iostream>
using namespace std;
#include <string>

// 重载关系运算符
class Person
{
public:
    Person(string name, int age)
    {
        m_Name = name;
        m_Age = age;
    }
    // 重载关系运算符
    bool operator==(Person &p)
    {
        if(this->m_Name == p.m_Name && this->m_Age == p.m_Age)
        {
            return true;
        }
        return false;
    }

    bool operator!=(Person &p)
    {
        if(this->m_Name == p.m_Name && this->m_Age == p.m_Age)
        {
            return false;
        }
        return true;
    }

    string m_Name;
    int m_Age;
};

void test01()
{
    Person p1("Tom" , 18);

    Person p2("yom" , 18);

    if(p1 == p2)
    {
        cout << "p1和p2是相等的" <<endl;
    }

    if(p1 != p2)
    {
        cout << "p1和p2是不相等的" <<endl;
    }

}

int main()
{
    test01();
}