/*4.4.3 成员函数做友元
*/
#include <iostream>
using namespace std;
#include <string>

class Building;

class GoodGay
{
public:
    GoodGay();

    void visit1();//让visit1函数可以访问Building中私有成员
    void visit2();//让visit2函数不可以访问Building中私有成员

    Building * building;
};

class Building
{
friend void GoodGay :: visit1();//友元声明

public:
    Building();
public:
    string m_SittingRoom;

private:
    string m_BedRoom;

};

//类外实现成员函数
Building :: Building()
{
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
}

GoodGay :: GoodGay()
{
    building = new Building;
}

void GoodGay :: visit1()
{
    cout << "visit1函数正在访问：" << building->m_SittingRoom <<endl;
    cout << "visit1函数正在访问：" << building->m_BedRoom <<endl;
}

void GoodGay :: visit2()
{
    cout << "visit2函数正在访问：" << building->m_SittingRoom <<endl;
    //cout << "visit2函数正在访问：" << building->m_BedRoom <<endl; 不可访问私有

}

void test01()
{
    GoodGay gg;
    gg.visit1();
    gg.visit2();
}

int main()
{
    test01();
    return 0;
}