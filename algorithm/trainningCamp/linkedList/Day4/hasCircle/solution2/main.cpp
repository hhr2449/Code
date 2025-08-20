#include <iostream>
#include <set>
using namespace std;

//判断链表里面是不是有环
//!思路2:快慢指针的典型应用：
//!使用快慢指针，fast每次移动的单位数多于slow（也就是fast的移动速度快于slow）
//!不断移动下去，如果两个指针相遇了，说明有环。如果fast到链表的末尾，则没有环
//!可以将环想象成一个圈，一快一慢两个人同时跑，则快的一定会套慢的的圈，如果没有环，则fast一定会到达终点
//以slow处于环的入口为起点，则每次移动fast都会向slow接近一个单位，所以一定会在slow的一圈内实现相遇

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
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) {
                return true;
            }
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