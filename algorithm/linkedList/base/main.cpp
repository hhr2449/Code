#include<iostream>
using namespace std;
//链表中的元素是Node对象，其中包含一个数据和一个Node类型的指针
//第一个节点成为头节点，最后一个节点称为尾节点，每个节点的指针指向下一个节点，尾节点的指针指向空
struct linkedNode{
    int val;//储存的数据
    linkedNode* next;//指向下一个节点的指针
    linkedNode(int x):val(x),next(nullptr){}
};
linkedNode* initList(int n){
    linkedNode* head = new linkedNode(0);//创建一个头节点
    linkedNode* p = head;//创建一个指针指向头节点（用于创建和链接后面的节点，因为头节点不能动，所以要创建一个副本p）
    for(int i=1;i<n;i++){//n是链表的长度，在头节点之后要创建n-1个节点
        p->next = new linkedNode(i);//在这里，p指向的是目前最后的节点，此时创建一个新的节点，让p代表的节点指向这个新的节点，相当于将新节点插在链表的尾部
        p = p->next;//p指向刚刚创建的新节点，保证p指向的是末尾节点
    }
    return head;//返回头节点
}
//只有头节点是有名字的，其他的节点需要通过头节点来遍历链表访问
//通常可以使用头节点来代表整个链表
void printList(linkedNode* head){
    linkedNode* p = head;
    //遍历链表的方式：创建头节点的副本p，p访问一个节点后指向下一个节点，直到p指向空
    while(p!=nullptr){
        cout << p->val << ' ';
        p=p->next;
    }
    cout << endl;
}
//访问链表的索引为index的节点
//链表的访问必须从头节点开始，所以复杂度为O(n)
linkedNode* accessNode(linkedNode* head,int index){
    linkedNode* p = head;
    for(int i=1;i<=index;i++){
        if(p==nullptr){
            cout << "Index out of range" << endl;
            return nullptr;
        }
        else{
            p = p->next;//执行完这一行时，p指向下表为i的节点
        }
    }
    return p;
}
//查找值为val的节点,复杂度为O(n)
linkedNode* findNode(linkedNode* head,int val){
    linkedNode* p = head;
    while(p!=nullptr){
        if(p->val==val){
            return p;
        }
        p = p->next;
    }
    return nullptr;
}
//这种根据下标在链表中插入节点的方法，时间复杂度为O(n)，因为需要融入访问节点的操作
void insertNode(linkedNode* head,int index,int val){
    //在index位置插入一个值为val的节点（下标为index）
    linkedNode* p = head;
    //如果Index=0，那么应该创建一个新的节点，让新的节点指向头节点，再让新节点成为头节点
    if(index==0){
        linkedNode* newNode = new linkedNode(val);
        newNode->next = head;
        head = newNode;
    }
    else{
        for(int i=1;i<index;i++){
            if(p==nullptr){
                cout << "Index out of range" << endl;
                return;
            }
            p = p->next;

        }
        //此时p指向的是index-1的节点
        linkedNode* newNode = new linkedNode(val);//创建新节点
            newNode->next = p->next;//先要让新节点指向index的节点，再让index-1的节点指向新节点，否则会链表断裂
            p->next = newNode;

    }
}
//在指定节点后面插入节点
//这种方法的时间复杂度为O(1)
void insertNode2(linkedNode* objNode,int val){
    linkedNode* newNode = new linkedNode(val);//创建节点
    newNode->next = objNode->next;
    objNode->next = newNode;
}
//删除指定节点后的节点
//这种方法的时间复杂度为O(1)
//如果要删除指定位置的节点，方法和插入节点类似，先找到前一个节点，再让前一个节点指向后一个节点
void deleteNode(linkedNode* objNode){
    linkedNode* p = objNode->next;
    objNode->next = p->next;
    delete p;
}
int getLen(linkedNode* head){
    linkedNode* p = head;
    int res = 0;
    while(p!=nullptr){
        res++;
        p = p->next;
    }
    return res;
}
int main(){
    linkedNode* head = initList(10);
    printList(head);
    insertNode(head,3,100);
    printList(head);
    cout << accessNode(head,3)->val << endl;
    linkedNode* findRes = findNode(head,100);
    cout << findRes->val << endl;
    insertNode2(findRes,200);
    printList(head);
    deleteNode(findRes);
    printList(head);
    cout << getLen(head) << endl;
    return 0;
}