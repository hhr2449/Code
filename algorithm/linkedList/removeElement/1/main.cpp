//!链表操作的两种方式：

//*1.直接使用原来的链表来进行操作。
//*2.设置一个虚拟头结点再进行操作。
//虚拟头发可以统合头节点和其他节点，在涉及使用前驱节点时更优（比如删除头节点，在头节点前面插入节点）

#include<iostream>
using namespace std;
//注意两个问题：
//1.链表头节点的处理：删除头节点时，需要特殊处理，因为头节点没有前驱节点。
//2.删除节点时需要使用前驱节点
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};
class Solution {
    public:
        ListNode* removeElements(ListNode* head, int val) {
            ListNode* p = head;
            //先处理头节点
            while(head!=nullptr&&head->val == val){
                p = head;
                head = head->next;
                delete p;
            }
            //使用循环，直到头节点为空或者头节点满足条件
            p = head;
            //注意这里的p有可能是空的（删完了）
            while(p!=nullptr&&p->next!=nullptr){
                //这里的p是要处理节点的前驱节点
                if(p->next->val == val){
                    ListNode* q = p->next;
                    p->next=p->next->next;
                    delete q;
                }
                else{
                    p = p->next;
                }
            }
            return head;
        }
    };
int main(){

}