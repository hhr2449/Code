#include <iostream>
#include <set>
using namespace std;

//寻找链表里面环的入口
//思路1：使用set，遍历链表并且将节点指针放入set中，如果有一个指针重复出现说明有环，并且重复的指针就是环的入口（使用set会很好解决，但是空间复杂度高）

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> isInList;
        ListNode* cur = head;
        while(cur != nullptr) {
            if(isInList.count(cur)) {
                return cur;
            }
            isInList.insert(cur);
            cur = cur->next;
        }
        return nullptr;
    }
};


int main() {
    ListNode* head = new ListNode(0);
    head->next = new ListNode(0);
    Solution solution;
    cout << solution.detectCycle(head);
}