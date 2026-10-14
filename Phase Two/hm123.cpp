/*4.5.3 递增运算符重载 ++ 
作用：通过重载递增运算符 实现自己的整型数据递增 
int a = 10;
cout << ++a <<endl; //11 先递增再输出
cout << a <<endl;   //11

int b =10;
cout << b++ <<endl; //10 先输出再递增
cout << b <<endl;   //11 
*/

#include <iostream>
using namespace std;
#include <string>

//重载递增运算符

//自定义整型变量
class MyInteger
{
friend ostream& operator<<(ostream& cout,MyInteger myint);

public:
    MyInteger()
    {
        m_Num = 0; //初始化为0
    }

    //重载前置 ++ 运算符
    MyInteger& operator++() // 返回引用是为了一直对一个数据进行递增操作
    {
        //先进行++运算
        m_Num ++;
        //再将自身返回
        return *this;
    }

    //重载后置 ++ 运算符
    MyInteger operator++(int)// int代表占位参数 可以用来区分前置和后置递增
    {
        //先 记录当时的结果
        MyInteger temp = *this;   //temp 是函数内部的局部变量。函数执行完，temp 就销毁了。如果返回值类型写成引用 MyInteger&，那么返回的就是这个局部变量 temp 的引用 错误用法
        //后 递增 
        m_Num ++;
        //最后将记录结果做一个返回的操作
        return temp;
    }




private:
    int m_Num;
};

//重载<<运算符
ostream& operator<<(ostream& cout,MyInteger myint)
{
    cout<< myint.m_Num <<endl;
    return cout; //保证链式法则
}

void test01()
{
    MyInteger myint;

    cout << ++myint <<endl;
    cout << ++(++myint) <<endl;
    cout << myint <<endl;
}

void test02()
{
    MyInteger myint;
    cout << myint++ <<endl;
    cout << myint <<endl;

}

int main()
{
    test01();
    test02();
    return 0;
}