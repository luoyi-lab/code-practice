/*4.4 友元
生活中你的家有客厅(Public)，有你的卧室(Privae)
客厅所有来的客人都可以进去，但是你的卧室是私有的，也就是说只有你能进去
但是呢，你也可以允许你的好闺蜜好基友进去。

在程序里，有些私有属性 也想让类外特殊的一些函数或者类进行访问，就需要用到友元的技术

友元的目的就是让一个函数或者类 访问另一个类中私有成员
友元的关键字为 friend

友元的三种实现
  1.全局函数做友元（全局函数：定义在类外面的普通函数）
  2.类做友元
  3.成员函数做友元

4.4.1 全局函数做友元
*/
#include <iostream>
using namespace std;

class Building
{
friend void goodGay(Building &building);//友元声明 goodGay可以访问building中私有的成员

public:
    Building()// 构造函数 在创建对象的时候，自动给对象的属性赋初始值。 当你写 Building b; 的时候，编译器会自动调用这个函数。执行完之后，b 对象的 m_SittingRoom 就是“客厅”，m_BedRoom 就是“卧室”。
    {
        m_SittingRoom = "客厅";
        m_BedRoom = "卧室";
    }

public:
    string m_SittingRoom;//客厅

private:
    string m_BedRoom;//卧室
};

//全局函数
void goodGay(Building &building)
{
    cout << "好基友全局函数正在访问：" << building.m_SittingRoom <<endl;//当左边是一个指针时，才用 -> 访问它的成员。
    cout << "好基友全局函数正在访问：" << building.m_BedRoom <<endl;
}

void test01()
{
    Building building;
    goodGay(building);
}

int main()
{
    test01();
    return 0;
}