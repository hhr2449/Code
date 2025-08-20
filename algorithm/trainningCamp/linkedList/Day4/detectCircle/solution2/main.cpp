#include <iostream>
#include <set>
using namespace std;

//寻找链表里面环的入口
//!公式推导:
/*
延续之前双指针找环的思路，设头指针到环入口的距离为x，环入口到相遇节点的距离为y，相遇节点到环入口的距离为z
那么slow的移动距离为x+y(注意slow一定会在第一圈相遇)
fast的移动距离为x+y+n(y+z)
fast的速度是slow的两倍，则x+y+n(y+z)=2(x+y)
则x=(n-1)(y+z)+z
y+z正好是圈的长度，那么从相遇点处和头指针处同时出发两个速度为1的指针，一定会在环的入口处相遇
*/

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
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            //找到相遇点
            if(fast == slow) {
                ListNode* index1 = head;
                ListNode* index2 = fast;
                while(index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;
            }
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