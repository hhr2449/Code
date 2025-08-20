#include <iostream>
using namespace std;


//使用单链表进行设计
//1. 一般会使用虚拟头节点设计单链表，这样方便对于链表的一些操作
//2. 定义节点结构体
//3. 维护dummyHead的指针和链表的size
//4. 注意dummyHead只是一个虚拟的头节点，不是真正的头节点，dummyHead->next才是真正的头节点，虚拟头节点不属于链表
class MyLinkedList {

//节点结构体
struct Node
{
    int val;
    Node* next;
    Node(int val_) : val(val_), next(nullptr) {} 
};


private:
//维护虚拟头节点的指针和链表的大小
Node* dummyHead_;
int size_;

public:
    //初始化虚拟头节点和size
    MyLinkedList() {
        dummyHead_ = new Node(0);
        size_ = 0;
    }
    
    //获取下标为index的节点的值
    //注意dummyHead->next下标为0
    int get(int index) {
        //如果下标不合法，返回-1
        if(index >= size_ || index < 0) {
            return -1;
        }
        //如果合法，则通过for循环来获取节点
        //获取头节点
        Node* cur = dummyHead_ -> next;
        //后移cur指针
        //因为之前已经处理了index不合法的情况，所以可以不用处理空指针之类的
        for(int i = 0; i < index; i++) {
            cur = cur -> next;
        }
        return cur -> val;
    }
    
    //添加节点，使其作为头节点
    //这里就显示出了dummyHead的优势，可以直接更改头节点，如果成员变量里面直接维护头节点，那么这里还要改变成员变量
    void addAtHead(int val) {
        Node* head = new Node(val);
        head->next = dummyHead_->next;
        dummyHead_->next = head;
        size_++;
    }
    
    //在链表最后添加节点
    void addAtTail(int val) {
        //需要获取末尾节点，然后使其指向新建的节点即可
        //注意这里应该从dummyHead开始，防止空链表问题
        Node* cur = dummyHead_;
        //获取末尾节点
        while(cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = new Node(val);
        size_++;
    }
    
    //将节点插入第index个节点之前
    //需要获取第index-1个节点
    //不妨将dummyHead设置为初始节点，然后后移index个单位,这样就可以获得第index-1个节点，然后在后面插入即可
    void addAtIndex(int index, int val) {
        if(index > size_) {
            return;
        }
        if(index < 0) {
            index = 0;
        }
        Node* cur = dummyHead_;
        for(int i = 0; i < index; i++) {
            cur = cur->next;
        }
        Node* newNode = new Node(val);
        newNode->next = cur->next;
        cur->next = newNode;
        size_++;
    }
    
    //删除掉下标为index的节点
    //注意删除节点也要获取前面的节点
    void deleteAtIndex(int index) {
        if(index >= size_ || index < 0) {
            return;
        }
        //获取虚拟头节点（可以统一头节点和普通节点的删除操作）
        Node* cur = dummyHead_;
        for(int i = 0; i < index; i++) {
            cur = cur->next;
        }
        //现在的cur指向的是目标结点的前置节点
        //保存要删除的节点，然后让前置节点指向后面的节点
        Node* target = cur->next;
        cur->next = target->next;
        delete target;
        size_--;
    }

    //打印链表
    void printLinkedList() {
        Node* cur = dummyHead_->next;
        while(cur != nullptr) {
            cout << cur->val << ' ';
            cur = cur->next;
        }
        cout << endl;
    }

    int getSize() {
        return size_;
    }

};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */


// 测试函数
void testCase1() {
    cout << "=== 测试用例1：基本操作 ===" << endl;
    MyLinkedList* obj = new MyLinkedList();
    
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1, 2);  // 链表变为 1->2->3
    
    cout << "链表内容: ";
    obj->printLinkedList();  // 应输出 1 2 3
    
    cout << "获取索引1的值: " << obj->get(1) << endl;  // 应输出 2
    
    obj->deleteAtIndex(1);  // 现在链表是 1->3
    cout << "删除索引1后: ";
    obj->printLinkedList();  // 应输出 1 3
    
    cout << "获取索引1的值: " << obj->get(1) << endl;  // 应输出 3
    
    delete obj;
    cout << endl;
}

void testCase2() {
    cout << "=== 测试用例2：边界条件 ===" << endl;
    MyLinkedList* obj = new MyLinkedList();
    
    // 测试空链表get
    cout << "空链表获取索引0: " << obj->get(0) << endl;  // 应输出 -1
    
    // 测试添加到头部
    obj->addAtHead(5);
    obj->addAtHead(4);
    obj->addAtHead(3);
    cout << "添加多个头节点后: ";
    obj->printLinkedList();  // 应输出 3 4 5
    
    // 测试删除头节点
    obj->deleteAtIndex(0);
    cout << "删除头节点后: ";
    obj->printLinkedList();  // 应输出 4 5
    
    // 测试添加到尾部
    obj->addAtTail(6);
    obj->addAtTail(7);
    cout << "添加多个尾节点后: ";
    obj->printLinkedList();  // 应输出 4 5 6 7
    
    // 测试删除尾节点
    obj->deleteAtIndex(3);
    cout << "删除尾节点后: ";
    obj->printLinkedList();  // 应输出 4 5 6
    
    delete obj;
    cout << endl;
}

void testCase3() {
    cout << "=== 测试用例3：索引边界 ===" << endl;
    MyLinkedList* obj = new MyLinkedList();
    
    obj->addAtHead(10);
    obj->addAtHead(20);
    obj->addAtHead(30);  // 30->20->10
    
    cout << "链表内容: ";
    obj->printLinkedList();
    
    // 测试无效索引get
    cout << "获取索引-1: " << obj->get(-1) << endl;  // -1
    cout << "获取索引3: " << obj->get(3) << endl;    // -1
    
    // 测试无效索引删除
    obj->deleteAtIndex(-1);
    obj->deleteAtIndex(5);
    cout << "删除无效索引后: ";
    obj->printLinkedList();  // 不变
    
    // 测试在索引0前添加
    obj->addAtIndex(0, 40);  // 40->30->20->10
    cout << "在索引0前添加后: ";
    obj->printLinkedList();
    
    // 测试在超出当前长度的索引添加（应忽略）
    obj->addAtIndex(10, 50);
    cout << "在超出长度的索引添加后: ";
    obj->printLinkedList();  // 不变
    
    delete obj;
    cout << endl;
}

void testCase4() {
    cout << "=== 测试用例4：完整删除 ===" << endl;
    MyLinkedList* obj = new MyLinkedList();
    
    obj->addAtHead(1);
    obj->addAtTail(2);
    obj->addAtTail(3);
    obj->addAtTail(4);  // 1->2->3->4
    
    cout << "初始链表: ";
    obj->printLinkedList();
    
    // 逐步删除所有节点
    obj->deleteAtIndex(0);  // 2->3->4
    obj->deleteAtIndex(0);  // 3->4
    obj->deleteAtIndex(0);  // 4
    obj->deleteAtIndex(0);  // 空
    
    cout << "删除所有节点后: ";
    obj->printLinkedList();  // 空
    
    // 测试在空链表添加
    obj->addAtTail(5);
    cout << "空链表添加节点后: ";
    obj->printLinkedList();  // 5
    
    delete obj;
    cout << endl;
}

int main() {
    testCase1();
    testCase2();
    testCase3();
    testCase4();
    
    return 0;
}
