#include <iostream>
#include <stack>
using namespace std;
// 请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：

// 实现 MyQueue 类：

// void push(int x) 将元素 x 推到队列的末尾
// int pop() 从队列的开头移除并返回元素
// int peek() 返回队列开头的元素
// boolean empty() 如果队列为空，返回 true ；否则，返回 false

//思路：可以这样想，对于一列元素，队列对于不改变其顺序，栈则会使顺序反转
//模拟队列，想要使元素顺序不变，则可以使用两个栈，经过两次入栈反转，顺序不变
//维护一个入栈和一个出栈，当push的时候将元素放入入栈中，当pop的时候如果出栈为空，则将入栈的元素全部放入出栈中再弹出，否则直接弹出
class MyQueue {
public:
    stack<int> inStack;
    stack<int> outStack;
    MyQueue() {
        
    }
    
    void push(int x) {
        inStack.push(x);
    }
    
    int pop() {
        if(outStack.empty()) {
            while(!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        int res = outStack.top();
        outStack.pop();
        return res;
    }
    
    int peek() {
        if(outStack.empty()) {
            while(!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        return outStack.top();
    }
    
    bool empty() {
        if(inStack.empty() && outStack.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
int main() {
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    cout << obj->peek();
    cout << obj->pop();
}