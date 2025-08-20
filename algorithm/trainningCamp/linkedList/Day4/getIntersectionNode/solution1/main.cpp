#include <set>
#include <iostream>
using namespace std;

//寻找两个链表的交点
//直接的思路：先遍历一个链表，将指针放入集合，然后再遍历另外一个链表，如果指针出现过，说明是交点
//时间复杂度o(n),时间复杂度o(m+n)

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> isHave;
        ListNode* curA = headA;
        ListNode* curB = headB;
        while(curA != nullptr) {
            isHave.insert(curA);
            curA = curA->next;
        }
        while(curB != nullptr) {
            if(isHave.count(curB)) {
                return curB;
            }
            curB = curB->next;
        }
        return nullptr;

    }
};
// 创建两个有交点的链表
void createIntersectingLists(ListNode*& headA, ListNode*& headB, ListNode*& intersection) {
    // 创建链表A的独有部分: 1 -> 2 -> 3
    headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    
    // 创建链表B的独有部分: 4 -> 5
    headB = new ListNode(4);
    headB->next = new ListNode(5);
    
    // 创建公共部分: 6 -> 7 -> 8 (交点从6开始)
    intersection = new ListNode(6);
    intersection->next = new ListNode(7);
    intersection->next->next = new ListNode(8);
    
    // 连接公共部分到两个链表
    headA->next->next->next = intersection;  // A: 1->2->3->6->7->8
    headB->next->next = intersection;        // B: 4->5->6->7->8
}

// 创建两个无交点的链表
void createNonIntersectingLists(ListNode*& headA, ListNode*& headB) {
    // 链表A: 1 -> 2 -> 3 -> 4
    headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = new ListNode(4);
    
    // 链表B: 5 -> 6 -> 7
    headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(7);
}

// 创建其中一个链表为空的情况
void createOneEmptyList(ListNode*& headA, ListNode*& headB, bool isAEmpty) {
    if (isAEmpty) {
        headA = nullptr;
        // 链表B: 1 -> 2 -> 3
        headB = new ListNode(1);
        headB->next = new ListNode(2);
        headB->next->next = new ListNode(3);
    } else {
        headB = nullptr;
        // 链表A: 1 -> 2 -> 3
        headA = new ListNode(1);
        headA->next = new ListNode(2);
        headA->next->next = new ListNode(3);
    }
}

// 创建两个链表完全相同的情况（从头部开始相交）
void createIdenticalLists(ListNode*& headA, ListNode*& headB) {
    // 创建公共链表: 1 -> 2 -> 3 -> 4
    ListNode* common = new ListNode(1);
    common->next = new ListNode(2);
    common->next->next = new ListNode(3);
    common->next->next->next = new ListNode(4);
    
    headA = common;
    headB = common;  // 两个链表完全相同
}

// 打印链表
void printList(ListNode* head, const string& name) {
    cout << name << ": ";
    ListNode* cur = head;
    while (cur != nullptr) {
        cout << cur->val << " -> ";
        cur = cur->next;
    }
    cout << "nullptr" << endl;
}

// 释放链表内存（注意处理相交部分只释放一次）
void freeLists(ListNode* headA, ListNode* headB, ListNode* intersection = nullptr) {
    // 释放链表A的独有部分
    ListNode* cur = headA;
    while (cur != nullptr && cur != intersection) {
        ListNode* temp = cur;
        cur = cur->next;
        delete temp;
    }
    
    // 释放链表B的独有部分
    cur = headB;
    while (cur != nullptr && cur != intersection) {
        ListNode* temp = cur;
        cur = cur->next;
        delete temp;
    }
    
    // 释放公共部分
    cur = intersection;
    while (cur != nullptr) {
        ListNode* temp = cur;
        cur = cur->next;
        delete temp;
    }
}

// 测试用例1：有交点的情况
void testCase1() {
    cout << "=== 测试用例1：有交点的链表 ===" << endl;
    ListNode* headA = nullptr;
    ListNode* headB = nullptr;
    ListNode* intersection = nullptr;
    
    createIntersectingLists(headA, headB, intersection);
    printList(headA, "链表A");
    printList(headB, "链表B");
    
    Solution solution;
    ListNode* result = solution.getIntersectionNode(headA, headB);
    
    if (result == intersection) {
        cout << "测试通过：找到交点，值为 " << result->val << endl;
    } else {
        cout << "测试失败：未正确找到交点" << endl;
    }
    
    freeLists(headA, headB, intersection);
    cout << endl;
}

// 测试用例2：无交点的情况
void testCase2() {
    cout << "=== 测试用例2：无交点的链表 ===" << endl;
    ListNode* headA = nullptr;
    ListNode* headB = nullptr;
    
    createNonIntersectingLists(headA, headB);
    printList(headA, "链表A");
    printList(headB, "链表B");
    
    Solution solution;
    ListNode* result = solution.getIntersectionNode(headA, headB);
    
    if (result == nullptr) {
        cout << "测试通过：无交点，返回nullptr" << endl;
    } else {
        cout << "测试失败：不应有交点但返回了值" << endl;
    }
    
    freeLists(headA, headB);
    cout << endl;
}

// 测试用例3：其中一个链表为空
void testCase3() {
    cout << "=== 测试用例3：一个链表为空 ===" << endl;
    ListNode* headA = nullptr;
    ListNode* headB = nullptr;
    
    createOneEmptyList(headA, headB, true);  // 链表A为空
    printList(headA, "链表A");
    printList(headB, "链表B");
    
    Solution solution;
    ListNode* result = solution.getIntersectionNode(headA, headB);
    
    if (result == nullptr) {
        cout << "测试通过：空链表与其他链表无交点" << endl;
    } else {
        cout << "测试失败：处理空链表错误" << endl;
    }
    
    freeLists(headA, headB);
    cout << endl;
}

// 测试用例4：两个链表完全相同（从头部开始相交）
void testCase4() {
    cout << "=== 测试用例4：两个链表完全相同 ===" << endl;
    ListNode* headA = nullptr;
    ListNode* headB = nullptr;
    
    createIdenticalLists(headA, headB);
    printList(headA, "链表A");
    printList(headB, "链表B");
    
    Solution solution;
    ListNode* result = solution.getIntersectionNode(headA, headB);
    
    if (result == headA && result == headB) {
        cout << "测试通过：找到交点，值为 " << result->val << endl;
    } else {
        cout << "测试失败：未正确识别完全相同的链表" << endl;
    }
    
    freeLists(headA, headB, headA);  // 整个链表都是公共部分
    cout << endl;
}

// 测试用例5：其中一个链表是另一个链表的子集
void testCase5() {
    cout << "=== 测试用例5：一个链表是另一个的子集 ===" << endl;
    // 链表A: 1 -> 2 -> 3 -> 4
    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = new ListNode(4);
    
    // 链表B: 3 -> 4 (是A的子集，从3开始相交)
    ListNode* headB = headA->next->next;
    
    printList(headA, "链表A");
    printList(headB, "链表B");
    
    Solution solution;
    ListNode* result = solution.getIntersectionNode(headA, headB);
    
    if (result == headB) {
        cout << "测试通过：找到交点，值为 " << result->val << endl;
    } else {
        cout << "测试失败：未正确识别子集情况" << endl;
    }
    
    // 只需要释放headA，因为headB是headA的一部分
    ListNode* cur = headA;
    while (cur != nullptr) {
        ListNode* temp = cur;
        cur = cur->next;
        delete temp;
    }
    cout << endl;
}

int main() {
    testCase1();
    testCase2();
    testCase3();
    testCase4();
    testCase5();
    return 0;
}
