/*4.4.2 类做友元
*/
#include <iostream>
using namespace std;
#include <string>

class Building;

class GoodGay
{
public:
    GoodGay();

public:
    void visit();//参观函数 访问Building中的属性（公共或私有）
    
    Building * building;//定义了一个公开的成员变量，是一个指向 Building 对象的指针
};

class Building 
{
friend class GoodGay;//GoodGay类可以访问本类中的私有成员

public:
    Building();
public:
    string m_SittingRoom;//客厅
    
private:
    string m_BedRoom;//卧室
};

//类外写成员函数
Building :: Building()
{
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
}

GoodGay :: GoodGay()
{
    //创建建筑物对象
    building = new Building;//new Building 就是在堆区（Heap）动态创建一个 Building 对象
}

void GoodGay :: visit()
{
    cout << "好基友正在访问" << building->m_SittingRoom <<endl;//building是一个指针
    cout << "好基友正在访问" << building->m_BedRoom <<endl;
}

void test01()
{
    GoodGay gg;
    gg.visit();
}

int main()
{
    test01();
    return 0;
}