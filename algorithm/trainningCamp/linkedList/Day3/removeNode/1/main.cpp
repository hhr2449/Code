#include <iostream>
using namespace std;

//移除链表中的指定val的节点
//思路很简单，就是遍历链表，如果后一个节点的val是要求移除的就进行删除（注意删除节点需要的是节点前面的节点）
//但是这样就没有办法处理头节点的删除
//!涉及节点删除的问题中的头节点删除方法
// 1. 单独处理头节点，只需要移动head直到head指向的节点不需要删除
//! 2. 虚拟头节点：设置一个dummyHead指向head节点，然后将dummyHead当成头节点进行处理，最后返回dummyHead->next

//!关键点：
//1.头节点的处理，需要跳过不符合要求的头节点，同时注意处理空指针的情况
//2.p指针的移动，注意当没有删除节点的时候才需要手动移动p指针，否则遇到连续需要移除的情况会出错
//3.删除节点需要的是目标节点的前一个节点，只有指向目标节点的指针是不能移除的

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    //单独处理头节点
    ListNode* removeElements(ListNode* head, int val) {
        //后移head指针，直到head指向的节点无需删除
        //注意要考虑空指针的情况
        if(head == nullptr) {
            return nullptr;
        }
        while(head != nullptr && head->val == val) {
            head = head->next;
        }
        ListNode* p = head;
        while(p != nullptr && p -> next != nullptr) {
            ListNode* target = p -> next;
            //如果等，那么target就是要删除的节点
            if(target->val == val) {
                p -> next = target -> next;
                delete target;
            }
            //后移p指针
            //!注意只有没有删除节点的时候才要手动后移p指针，因为删除了节点就相当于后移一位了，如果再后移就会漏
            else {
                p = p -> next;
            }
            
        }
        return head;
    }
};
// 根据数组创建链表
ListNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    
    for (int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    
    return head;
}

// 打印链表
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

// 释放链表内存
void freeList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // 测试用例1: 普通情况，有多个需要删除的节点
    int arr1[] = {1, 2, 6, 3, 4, 5, 6};
    ListNode* list1 = createList(arr1, 7);
    cout << "测试用例1 - 原始链表: ";
    printList(list1);
    
    Solution solution;
    ListNode* result1 = solution.removeElements(list1, 6);
    cout << "测试用例1 - 删除6后的链表: ";
    printList(result1);
    freeList(result1);
    
    // 测试用例2: 头节点需要删除
    int arr2[] = {6, 1, 2, 3, 6};
    ListNode* list2 = createList(arr2, 5);
    cout << "\n测试用例2 - 原始链表: ";
    printList(list2);
    
    ListNode* result2 = solution.removeElements(list2, 6);
    cout << "测试用例2 - 删除6后的链表: ";
    printList(result2);
    freeList(result2);
    
    // 测试用例3: 所有节点都需要删除
    int arr3[] = {6, 6, 6, 6};
    ListNode* list3 = createList(arr3, 4);
    cout << "\n测试用例3 - 原始链表: ";
    printList(list3);
    
    ListNode* result3 = solution.removeElements(list3, 6);
    cout << "测试用例3 - 删除6后的链表: ";
    printList(result3);
    freeList(result3);
    
    // 测试用例4: 空链表
    ListNode* list4 = nullptr;
    cout << "\n测试用例4 - 原始链表: ";
    printList(list4);
    
    ListNode* result4 = solution.removeElements(list4, 6);
    cout << "测试用例4 - 删除6后的链表: ";
    printList(result4);
    
    // 测试用例5: 没有需要删除的节点
    int arr5[] = {1, 2, 3, 4, 5};
    ListNode* list5 = createList(arr5, 5);
    cout << "\n测试用例5 - 原始链表: ";
    printList(list5);
    
    ListNode* result5 = solution.removeElements(list5, 6);
    cout << "测试用例5 - 删除6后的链表: ";
    printList(result5);
    freeList(result5);
    
    return 0;
}
