/*4.3.2 this指针概念
C++中成员变量和成员函数是分开存储的
每一个非静态成员函数只会诞生一份函数实例，也就是说多个同类型的对象会共用一块代码
那么问题是：这一块代码如何区分哪个对象调用自己的呢？

C++通过提供特殊的对象指针，this指针，解决上述问题。this指针指向被调用的成员函数所属的对象

this指针是隐含在每一个非静态成员函数内的一种指针

this指针不需要定义，直接使用即可

this指针的用途：
  1.当形参和成员变量同名时，可用this指针来区分
  2.在类的非静态成员函数中返回对象本身，可使用return *this
*/
#include <iostream>
using namespace std;

class Person
{
public:
    Person(int age)
    {
        //this 指针指向 被调用的成员函数所属的对象
        this->age = age;//this指向p1 因为p1调用了这个有参构造函数
    }

    int age;

    Person& PersonADDage(Person &p)
    {
        this->age += p.age;//自身的年龄加上传入的p的年龄

        return *this;//this指向p3的指针 *this指向的就是p3的本体
    }
};


//1 解决名称冲突
void test01()
{
    Person p1(18); 
    cout << "p1的年龄为 " << p1.age <<endl;
}

//2 返回对象本身 用 *this
void test02()
{
    Person p2(11);
    Person p3(14);

    p3.PersonADDage(p2).PersonADDage(p2).PersonADDage(p3);//链式编程思想
    cout << "p3的年龄为：" << p3.age <<endl;
}

int main()
{
    test01();
    test02();
    
    return 0;
}