#include<iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};
class Solution {
    public:
    //递归做法：一个链表是由一个个节点连接起来的，其子结构仍然是链表（单独处理空情况），所以适合递归
        ListNode* removeElements(ListNode* head, int val) {
           //先单独处理头节点，然后递归处理后面的节点
           if(head==nullptr){
            return nullptr;
           }
           if(head->val==val){
            ListNode* newHead = removeElements(head->next,val);
            return newHead; 
           }
           else{
            head->next = removeElements(head->next,val);
            return head;
           }
        }
    };
int main(){

}