#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:

    //该函数的功能：实现以head为头的链表的两两交换
    //使用递归
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* cur = head;
        ListNode* t1 = cur->next;
        ListNode* t2 = t1->next;
        t1->next = cur;
        cur->next = swapPairs(t2);
        return t1;
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

// 测试用例1：偶数个节点
void testCase1() {
    cout << "=== 测试用例1：偶数个节点 ===" << endl;
    int arr[] = {1, 2, 3, 4};
    ListNode* head = createList(arr, 4);
    
    cout << "交换前：";
    printList(head);
    
    Solution solution;
    ListNode* result = solution.swapPairs(head);
    
    cout << "交换后：";
    printList(result);
    
    freeList(result);
    cout << endl;
}

// 测试用例2：奇数个节点
void testCase2() {
    cout << "=== 测试用例2：奇数个节点 ===" << endl;
    int arr[] = {1, 2, 3, 4, 5};
    ListNode* head = createList(arr, 5);
    
    cout << "交换前：";
    printList(head);
    
    Solution solution;
    ListNode* result = solution.swapPairs(head);
    
    cout << "交换后：";
    printList(result);
    
    freeList(result);
    cout << endl;
}

// 测试用例3：空链表
void testCase3() {
    cout << "=== 测试用例3：空链表 ===" << endl;
    ListNode* head = nullptr;
    
    cout << "交换前：";
    printList(head);
    
    Solution solution;
    ListNode* result = solution.swapPairs(head);
    
    cout << "交换后：";
    printList(result);
    cout << endl;
}

// 测试用例4：单个节点
void testCase4() {
    cout << "=== 测试用例4：单个节点 ===" << endl;
    int arr[] = {1};
    ListNode* head = createList(arr, 1);
    
    cout << "交换前：";
    printList(head);
    
    Solution solution;
    ListNode* result = solution.swapPairs(head);
    
    cout << "交换后：";
    printList(result);
    
    freeList(result);
    cout << endl;
}

// 测试用例5：两个节点
void testCase5() {
    cout << "=== 测试用例5：两个节点 ===" << endl;
    int arr[] = {10, 20};
    ListNode* head = createList(arr, 2);
    
    cout << "交换前：";
    printList(head);
    
    Solution solution;
    ListNode* result = solution.swapPairs(head);
    
    cout << "交换后：";
    printList(result);
    
    freeList(result);
    cout << endl;
}

int main() {
    testCase1();  // 偶数个节点
    testCase2();  // 奇数个节点
    testCase3();  // 空链表
    testCase4();  // 单个节点
    testCase5();  // 两个节点
    
    return 0;
}
    