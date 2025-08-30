// 给你一个字符串数组 tokens ，表示一个根据 逆波兰表示法 表示的算术表达式。

// 请你计算该表达式。返回一个表示表达式值的整数。
//逆波兰表达式：对于E1 op E2 表达式， E1 和 E2 都是逆波兰表达式，op 是一个运算符，其逆波兰表达式是E1 E2 op

//思路：使用栈，对于E1 E2 op可以计算为：E1 op E2,那么就可以使用栈来对这个过程进行模拟
//从左向右将表达式中的元素入栈，如果遇到运算符，则将栈顶的两个元素用该运算符进行运算，并且入栈

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto i:tokens) {
            //如果是运算符，则弹出栈顶的两个元素进行运算，并且将结果入栈
            if(i == "+" || i == "-" || i == "*" || i == "/") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                if(i == "+") s.push(a + b);
                else if(i == "-") s.push(b - a);
                else if(i == "*") s.push(a * b);
                else if(i == "/") s.push(b / a);
            }
            else {
                s.push(stoi(i));
            }
        }
        return s.top();
    }
};
int main() {
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    Solution s;
    cout << s.evalRPN(tokens) << endl;
    return 0;
}