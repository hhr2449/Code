#include <iostream>
#include <queue>
using namespace std;
// 请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。

// 实现 MyStack 类：

// void push(int x) 将元素 x 压入栈顶。
// int pop() 移除并返回栈顶元素。
// int top() 返回栈顶元素。
// boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。

//思路：队列和栈不同，队列不会改变元素的顺序，所以不能使用两次操作实现栈的顺序
//这里的思路就是先将前面的元素移开，获取到最后一个元素，然后再将前面的元素还回去
class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int size = q1.size();
        //将q1中前面的元素移开，在q2中进行临时储存
        for(int i = 0; i < size - 1; i++) {
            q2.push(q1.front());
            q1.pop();
        }
        //将q1中剩余的一个元素pop出去
        int res = q1.front();
        q1.pop();
        //将q2中的元素重新放回q1中
        q1 = q2;
        //注意要将q2清空
        while(!q2.empty()) {
            q2.pop();
        }
        return res;
    }
    
    int top() {
        int size = q1.size();
        //将q1中前面的元素移开，在q2中进行临时储存
        for(int i = 0; i < size - 1; i++) {
            q2.push(q1.front());
            q1.pop();
        }
        //记录剩余元素
        int res = q1.front();
        //恢复原来的结构
        q1.pop();
        q2.push(res);
        q1 = q2;
        //注意要将q2清空
        while(!q2.empty()) {
            q2.pop();
        }
        return res;
    }
    
    bool empty() {
        if(q1.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
int main() {

}