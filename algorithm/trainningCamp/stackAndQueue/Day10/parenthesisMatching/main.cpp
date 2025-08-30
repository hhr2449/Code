// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

// 有效字符串需满足：

// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。
// 每个右括号都有一个对应的相同类型的左括号。

//分析：先思考怎么样的括号串是正确的
//对于一个括号串，从左往右数第一个右括号，他的左边的括号一定是和他匹配的
//可以从左往右遍历括号串，对于右括号，如果和其左边的括号匹配就消去，否则返回false，知道整个括号串都消去，返回true
//这个过程可以使用栈，从左往右进行入栈，如果入栈的是右括号，且和栈顶括号匹配，就pop，最终如果空，则返回true

//!或者可以这样思考：每一个左括号都必须要一个右括号进行匹配，并且后遇到的左括号要先进行闭合，这与栈后进先出的特性是一致的
//!所以可以从左向右进行遍历，后面遇到的左括号放入栈顶，遇到右括号就和栈顶的的括号进行匹配
//!匹配问题经常使用栈进行解决，特别是后遇到的先匹配
#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> s1;
        for(int i = 0; i < s.size(); i++) {
            //左括号入栈
            char c = s[i];
            if(c == '(' || c == '{' || c == '[') {
                s1.push(c);
            }
            //右括号验证
            else {
                //如果当前栈空，则一定无法匹配
                if(s1.empty()) {
                    return false;
                }
                //如果当前栈顶括号是和当前的右括号匹配的，则消去这一对括号
                if(c == ')' && s1.top() == '(') {
                    s1.pop();
                }
                else if(c == '}' && s1.top() == '{') {
                    s1.pop();
                }
                else if(c == ']' && s1.top() == '[') {
                    s1.pop();
                }
                else {
                    return false;
                }
            }
        }
        //如果最后栈空，则返回true
        if(s1.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
};
int main() {
    string s = "()[]{}";
    Solution s1;
    cout << s1.isValid(s) << endl;
    return 0;
}