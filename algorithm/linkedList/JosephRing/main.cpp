#include<iostream>
using namespace std;
struct linkedNode{
    int val;
    linkedNode* next;
    linkedNode(int x):val(x),next(nullptr){}
};
linkedNode* r = nullptr;//维护一个指针r，他是后面操控的p指针的前置指针
linkedNode* initCircleList(int n){
    linkedNode* head = new linkedNode(1);
    linkedNode* p = head;
    for(int i=2;i<=n;i++){
        p->next = new linkedNode(i);
        p = p->next;
    }
    p->next = head;
    r = p;
    return head;
}
void deleteNode(linkedNode* objNode){
    linkedNode*p = objNode->next;
    objNode->next = p->next;
    delete p;
}
int findTheWinner(int n, int k) {
    linkedNode* head = initCircleList(n);
    linkedNode* p = head;
    while(p!=p->next){//注意这个条件，p==p->next时，说明只有一个节点了
        for(int i = 2;i<=k;i++){
            r = r->next;//r是p的前置指针，用于删除节点
            p = p->next;//其实也可以不使用p，使用r->next来代表p
        }   
		cout << "淘汰了" << p->val << " ";
        deleteNode(r);
        p = r->next;
    }
    return p->val;
}
int main(){
    int res = findTheWinner(3,1);
    cout << "胜者是" << res << endl;
}