#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(nullptr){}
};

// 1.打印整条链条
void printList(ListNode* head)
{
    ListNode* curr = head;
    while(curr != nullptr)  //只有当curr走到链表末尾 next是nullptr时 才停止
    {
        cout << curr->val;
        if(curr->next != nullptr)
        {
            cout << " -> " ;
        }
        curr = curr -> next; //指针后移 计算机先找到 curr 当前指向的节点，然后从这个节点里把 next 指针存的值，即下一个节点的地址拿出来 赋给左边的curr
    }
    cout <<endl;
}

// 2.头插：返回新的头
ListNode* pushFront(ListNode* head, int x) //返回值：ListNode* 函数需要把新的头指针返回给调用者（main函数等）
{
    ListNode* newNode = new ListNode(x); // 调用结构体里的构造函数 在堆区申请了一块内存 用来存放新节点
    // 新节点的 val 被赋值为 x    用一个名为 newNode 的指针指向这块新申请的内存
    newNode->next = head; // 把新节点的next指针 指向原来链表的头节点 head
    return newNode;
}

// 3.尾插：返回头（注意空链表的情况）
ListNode* pushBack(ListNode* head, int x)
{
    ListNode* newNode = new ListNode(x);
    // 如果链表为空 直接返回新节点作为头
    if(head == nullptr)
    {
        return newNode;
    }
    // 找到最后一个节点：
    ListNode* curr = head; // 定义游标
    while(curr -> next != nullptr)
    {
        curr = curr -> next;
    }
    curr -> next = newNode; // 把原来链表的最后一个节点 指向刚刚创建的新节点
    return head;
}

// 4.删除第一个值为x的节点，返回头
ListNode* removeValue(ListNode* head, int x)
{
    if(head == nullptr) return nullptr;
    //如果要删除的是头节点
    if(head->val == x)
    {
        ListNode* temp = head; // 用一个temp记住原来的头节点
        head = head->next; // 让原来的第二个节点变为头节点
        delete temp;// 原来的头节点被删掉了 就没有用了 必须delete
        return head;

    }

    // 如果要删除的是中间或尾部节点
    ListNode* curr = head;
    while(curr->next != nullptr)
    {
        if(curr->next->val == x)
        {
            ListNode* temp = curr -> next;
            curr -> next = curr -> next -> next; // 直接跳过val=x的节点 指向下一个节点
            delete temp;
            return head; //题目要求只删一个，删除后直接返回
        }
        curr = curr->next;
    }
    return head; //没找到x的节点， 原样返回
}

// 5.返回链表长度
int length(ListNode* head)
{
    int count = 0;
    ListNode* curr = head;
    while(curr != nullptr)
    {
        count++;
        curr = curr->next;
    }
    return count;
}

int main()
{
    //手工建1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    printList(head); // 打印整个链表

    head = pushFront(head, 0); // 把数字 0 插入到链表的最前面（头插），并更新链表的头指针
    printList(head);

    head = pushBack(head, 6);
    printList(head);

    head = removeValue(head, 3);
    printList(head);

    cout << "长度为：" << length(head) <<endl;
    return 0;
}
