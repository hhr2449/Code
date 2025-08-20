#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//反转链表的思路
//很直接的思路就是让每个节点的next指针指向它的前置节点
//使用三个指针pre,cur,tmp
//cur是指向当前需要改变指向的节点的指针，pre就是前置节点，tmp用于保存后置节点（因为改变指向之后会丢失后置节点）
//每次将cur的next指向pre，完成一个节点的反转，然后让pre移动到cur的位置，cur移动到tmp的位置，tem移到当前cur的next的位置
//直到改变完最后一个节点的指向结束

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre;
        ListNode* cur;
        ListNode* tmp;
        pre = nullptr;
        cur = head;
        tmp = cur->next;
        while(cur != nullptr) {
            cur->next = pre;
            pre = cur;
            cur = tmp;
            tmp = cur->next;
        }
    }
};

int main() {

}