#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//思路：首先找到尾节点，统计出节点的总个数

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //使用虚拟头节点，统一头节点和普通节点的删除方法
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = head;
        //总共有cnt个节点
        int cnt = 0;
        while(cur != nullptr) {
            cur = cur->next;
            cnt++;
        }
        //从虚拟头节点开始移动res，就可以到达目标节点的前面一个节点
        int res = cnt - n;
        cur = dummyHead;
        for(int i  = 0; i < res; i++) {
            cur = cur->next;
        }
        ListNode* target = cur->next;
        cur->next = target->next;
        delete target;
        return dummyHead->next;

    }
};

//使用数组创建链表
ListNode* createList(int arr[], int n) {
    if(n == 0) {
        return nullptr;
    }
    //创建头节点
    ListNode* head = new ListNode(arr[0]);
    ListNode* cur = head;
    for(int i = 1; i < n; i++) {
        ListNode* newNode = new ListNode(arr[i]);
        cur->next = newNode;
        cur = cur->next;
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

int main() {
    int arr[] = {1, 2, 3, 4};
    ListNode* head = createList(arr, 4);
    Solution solution;
    ListNode* result = solution.removeNthFromEnd(head,4);
    printList(result);
}