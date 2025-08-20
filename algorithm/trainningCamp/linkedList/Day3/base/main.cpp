#include <iostream>
using namespace std;

//Node是链表的基本节点，里面包含两个部分，一个是节点中的数据，另一个是指向后节点的指针（如果是双向链表的话还会指向前面的节点）
struct Node {
    int data;
    Node* next;
    Node(int data_) : data(data_), next(nullptr) {}
};

//初始化链表
//建立一个Node节点，然后使用前面的节点的next指向它，并且获取新的节点
//最后返回指向头节点的指针
Node* init() {
    //创建头节点
    Node* head = new Node(0);
    //p是指向当前尾节点的指针，在链表的操作中经常使用
    Node* p = head;
    //创建后续节点
    //1. 创建节点并且使用当前尾节点的next指针指向它
    //2. 改变p，使其指向当前的尾节点
    for(int i = 1; i < 10; i++) {
        p -> next = new Node(i);
        //经常使用 p = p -> next 来进行链表的遍历
        p = p -> next;
    }
    return head;
}

//遍历链表
//同样使用p指针，访问当前指向的节点，然后指向下一个节点
//直到p是空，停止
void traval(Node* head) {
    Node* p = head;
    while(p != nullptr) {
        //访问当前节点
        cout << p -> data << ' ';
        //后移指针
        p = p ->next;
    }
    cout << endl;
}

//访问链表中特定位置的节点
//实际上就是for循环遍历
void accessNode(int index, Node* head) {
    if(index < 0) {
        cout << "out of range" << endl;
    }
    Node* p = head;
    //设定下标从0开始
    for(int i = 0; i < index; i++) {
        //注意我们是先检测，后移动，所以应该检查p -> next是否为空，要保证p指向的一定不是空
        if(p -> next == nullptr) {
            cout << "out of range" << endl;
            return;
        }
        else {
            //将p指针后移
            p = p -> next;
        }
    }
    cout << p -> data << endl;;
}

//查找对应data的节点
//实际上就是遍历检测
Node* findNode(int data, Node* head) {
    Node* p = head;
    while(p != nullptr) {
        if(p -> data == data) {
            return p;
        }
        p = p -> next;
    }
    return nullptr;

}

//插入节点
//使插入的节点成为索引为index的节点
//因为可能有头结点的改变，所以head要传引用
void insert(int data, int index, Node* & head) {
    Node* p = head;
    //如果index为0，就需要将新节点设置为头节点
    if(index == 0) {
        //头节点指针指向新的节点
        head = new Node(data);
        head -> next = p;
        return;
    }
    //如果不为0，应该先获得第index-1个节点
    //让新节点next指针指向该节点next指向的节点，然后让该节点的next指针指向新节点
    if(index > 0) {
        for(int i = 0; i < index - 1; i++) {
            if(p -> next == nullptr) {
                cout << "out of range" << endl;
            }
            else {
                p = p -> next;
            }
        }
        Node* newNode = new Node(data);
        newNode->next = p -> next;
        p -> next = newNode;
        return;
    }
}

//在指定节点后面插入节点
void insert2(Node* obj, int data) {
    Node* newNode = new Node(data);
    newNode->next = obj->next;
    obj->next = newNode;
}

//删除指定节点后面的节点
//应该先保存要删除节点后面的节点的指针
//将节点删除掉，然后用next指针指向预先保存的节点指针
//! 注意删除节点需要获取的使该节点的前面一个节点，只有该节点的指针是无法删除的
void deleteNode(Node* obj) {
    Node* target = obj->next;
    Node* p = target->next;
    delete target;
    obj->next = p;
}

int main() {
    //初始化链表，获取链表头head
    Node* head = init();
    //遍历链表
    traval(head);
    //访问特定索引的节点
    accessNode(9, head);
    //寻找特定data的节点
    Node* p = findNode(0, head);
    cout << p -> data << endl;
    //插入节点
    insert(10, 0, head);
    traval(head);
    insert(11, 10, head);
    traval(head);
    insert(12, 12, head);
    traval(head);
    //插入节点
    insert2(p, 13);
    traval(head);
    p = findNode(12, head);
    insert2(p, 14);
    traval(head);
    //删除节点
    deleteNode(p);
    traval(head);
    p = findNode(2, head);
    deleteNode(p);
    traval(head);
}