/*4.2.7 类对象作为类成员
C++类中的成员可以是另一个类的对象，我们称该成员为 对象成员
例如：
class A{}
class B
{
    A a;
}
B类中有对象A作为成员，A为对象成员

那么当创建B对象时，A和B的构造和析构顺序是谁先谁后呢？（答案是A，同时，析构和构造的顺序相反）
*/
#include <iostream>
using namespace std;
#include <string>

class Phone
{
public:
    Phone(string pName)//有参构造
    {
        m_PName = pName;
        cout << "Phone的构造函数调用" <<endl;

    }

    //手机品牌
    string m_PName;

};

class Person
{
public:
    //Phone m_Phone = pName 隐式转换法
    Person(string name,string pName):m_Name(name) , m_Phone(pName)//初始化列表,给m_Name等赋初值
    {
        cout << "Person的构造函数调用" <<endl;
   
    }
    //姓名
    string m_Name;
    //手机
    Phone m_Phone;
};

void test01()
{
    Person p( "张三" , "苹果promax");
    cout << p.m_Name << "拿着" << p.m_Phone.m_PName <<endl;
}

int main()
{
    test01();
    
    return 0;
}