/*C++ 的vector 动态数组
核心概念：
vector 是一个可以动态扩容的数组。它底层是一块连续的内存，所以支持快速的随机访问（通过下标 []）。对应 Python 的 list
注意： C++ 的 vector 是强类型的，声明时就必须规定里面装什么类型，而且不能混装。
*/
#include <iostream>
#include <vector> // 1. 必须包含的头文件
#include <algorithm> // 用于 max_element 等算法
using namespace std;

int main()
{
    //2.声明与初始化
    vector<int> v1;//空数组 装int
    vector<int> v2 = {1,2,3};//初始化列表
    vector<int> v3(5,100);//创建5个100：{100, 100, 100, 100, 100}

    //3.添加元素
    v1.push_back(10);// 尾部追加 10
    v2.push_back(20);
    v1.emplace_back(30);// C++11 引入，比 push_back 效率更高（推荐）

    //4.访问元素
    cout << v1[0] <<endl;// 像数组一样，用 [] 访问（越界不会报错，很危险！）
    cout << v1.at(1) <<endl;// 推荐用 .at()，越界会抛出异常，安全
    cout << v1.front() <<endl;//第一个元素 下标0
    cout << v1.back() <<endl;//最后一个元素

    //5.获取大小和判空
    cout << "大小为 " << v1.size() <<endl;
    cout << "是否为空" << v1.empty() <<endl;// 空返回 true(1)，不空返回 false(0)

    //6.遍历 两种方法
    // 方式一：普通 for 循环（最像 C/C++ 数组）
    for(int i = 0 ; i < v2.size() ; i++)
    {
        cout << v1[i] << " " <<endl;
    }

    //方式二：范围 for 循环（C++11 起，极其像 Python！）
    //这里的 num 是拷贝，加 & 变成引用可以避免拷贝提高效率 （如果不需要修改，加 const 更安全）
    for (const auto& num : v1)
    {
        cout << num << " " <<endl;
    }
    //const auto& num : v1 解析：
    // : 读作“in”。整个意思是：“对于 v1 中的每一个元素，把它取出来，命名为 num”
    // auto：自动类型推导。编译器会根据 v1 的类型，自动推断出 num 应该是什么类型
    /*&（引用）：这是效率的关键。如果不加 &，每次循环都会把 v1 里的元素拷贝一份给 num。
    如果 v1 里存的是很长的字符串或者大对象，拷贝会非常耗时。
    加上 &，num 就只是 v1 里那个元素的“别名”，不产生拷贝。
    */
    //const：这是安全的关键。加上 const，表示 num 是只读的。

    //7.删除元素
    v1.pop_back();
    v1.erase(v1.begin());

    return 0;
}