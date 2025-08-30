#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main() {
    stack<int, vector<int>> sv;
    sv.push(1);
    sv.push(2);
    sv.push(3);
    //pop()用于移除栈顶元素，top()用于获取栈顶元素，empty()用于判断栈是否为空
    //常常结合起来对stack进行遍历
    //注意栈不支持迭代器和随机访问
    while(!sv.empty()) {
        cout << sv.top() << ' ';
        sv.pop();
    }
    return 0;
}