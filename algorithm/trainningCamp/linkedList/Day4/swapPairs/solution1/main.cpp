#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//交换链表中两两相邻的节点
//只需要获取要交换的两个相邻节点前面的一个节点就可以进行交换
//比如：d->A->B->C->D 当前cur指向d，然后让t1,t2,t3分别指向A,B,C
//1. cur指向t2
//2. t2指向t1
//3. t1指向t3，此时完成A,B的交换，形成d->B->A->C->D
//然后让cur = t1，重复进行即可

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        //虚拟头节点，方便操作
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        ListNode* t1;
        ListNode* t2;
        ListNode* t3;
        //每一次循环交换cur后面两个节点
        //只要cur后面的两个节点都不为空就可以进行
        while(cur->next != nullptr && cur->next->next != nullptr) {
            t1 = cur->next;
            t2 = t1->next;
            t3 = t2->next;
            cur->next = t2;
            t2->next = t1;
            t1->next = t3;
            cur = t1;
        }
        return dummyHead->next;
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
    