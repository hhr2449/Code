#include <iostream>
#include <set>
using namespace std;

//判断链表里面是不是有环
//思路1：使用set，遍历链表并且将节点指针放入set中，如果有一个指针重复出现说明有环，并且重复的指针就是环的入口

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> isInList;
        ListNode* cur = head;
        while(cur != nullptr) {
            if(isInList.count(cur)) {
                return true;
            }
            isInList.insert(cur);
            cur = cur->next;
        }
        return false;
    }
};


int main() {
    ListNode* head = new ListNode(0);
    head->next = new ListNode(0);
    Solution solution;
    cout << solution.hasCycle(head);
}