/*C++ 的 map（键值对字典）
核心概念：
map 存储的是 Key-Value（键值对）。它会自动根据 Key 进行排序（底层通常是红黑树）。对应 Python 的 dict（字典 也是存储键值对）
输出的顺序不会是插入顺序，而是按 Key 的字母顺序（ASCII 码）自动排好序
注意： map 的 Key 必须唯一，且 Key 和 Value 的类型都在声明时固定。
*/
#include <iostream>
#include <map> // 1. 必须包含的头文件
#include <string>
using namespace std;

int main()
{
    //2.声明：Key 是 string，Value 是 int
    map<string,int> scores;//scores是变量名

    //3.插入/修改元素
    scores["Tom"] = 100;
    scores["Jerry"] = 200;
    // scores.insert(make_pair("Spike", 85)); // 另一种插入方式，但不如 [] 直观

    //4.访问元素
    cout << scores["Tom"] <<endl; // 如果 Tom 不存在，会创建一个默认值 0 并返回（小心！）
    cout << scores.at("Jerry") <<endl;// 推荐：如果 Jerry 不存在，直接抛出异常

    //5.判断 Key 是否存在（重要！）
    if (scores.find("Tom") != scores.end())//nd() 指向最后一个元素后面的位置 意思是查找的结果不等于最后一个再后一个 也就是找到了
    {
        cout << "Tom 存在" << endl;
    }

    //6.删除元素
    scores.erase("Jerry");// 根据 Key 删除

    //7.遍历
    for (auto it = scores.begin() ; it != scores.end() ; ++it )
    {
        cout << "Key: " << it->first << ", Value" << it->second <<endl;
    }
    //scores.begin() 返回一个迭代器，指向字典里的第一个元素
    //auto it 自动推导类型，it 现在就代表这个迭代器
    //it != scores.end() 意思是：只要 it 还没走到尽头，就继续循环
    //++it 让迭代器向后移动一位，指向下一个元素
    /*
    it->first：取出当前元素的 Key（键）
    it->second：取出当前元素的 Value（值）

    为什么是 first 和 second？ 
    因为 map 内部存储的每一个元素，本质上是一个 std::pair（键值对）
    pair 的第一个成员叫 first（存 Key），第二个成员叫 second（存 Value）

    为什么用 ->？ 因为 it 是一个迭代器，行为像指针，所以用 -> 访问它指向的 pair 的成员。
    */

    //8. 范围 for 循环（C++17 结构化绑定，极其优雅，强烈推荐）
    for (const auto& [name, score] : scores) 
    {
        cout << "Key: " << name << ", Value: " << score << endl;
    }

    /*在 [ ] 里写两个变量名 [name, score]，C++ 会自动帮你拆包：
    把元素的 Key（first）自动绑定给 name。
    把元素的 Value（second）自动绑定给 score。
    */
    //auto：自动推导类型。编译器知道 scores 里的元素是 pair<string, int>，所以自动推导出 name 是 string，score 是 int
    //: 读作“in”。整个意思是：“对于scores中的每一个元素，把它取出来
    //& 引用 避免拷贝
    return 0;
}