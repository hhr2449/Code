#include<iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};
class Solution {
    public:
    //虚拟头节点法：
    //之前处理的麻烦之处在于头节点需要单独处理，那么可以虚设一个虚拟头节点，
        ListNode* removeElements(ListNode* head, int val) {
            ListNode* dummyNode = new ListNode(-1);
            dummyNode->next = head;
            ListNode* cur = dummyNode;
            while(cur->next!=nullptr){
                if(cur->next->val==val){
                    ListNode* temp = cur->next;
                    cur->next = cur->next->next;
                    delete temp;
                }
                else{
                    cur = cur->next;
                }
            }
          return dummyNode->next;
        }
    };
int main(){

}