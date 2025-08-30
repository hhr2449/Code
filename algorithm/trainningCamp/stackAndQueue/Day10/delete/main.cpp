// 给出由小写字母组成的字符串 s，重复项删除操作会选择两个相邻且相同的字母，并删除它们。

// 在 s 上反复执行重复项删除操作，直到无法继续删除。

// 在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。

//思路：维护一个栈，将字符放入栈中，只要和栈顶字符相同就消除
//类似于消消乐游戏，靠在一起就要消除
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        for(int i = 0; i < s.size(); i++) {
            //如果栈为空或是当前字符和栈顶字符不相同，则入栈
            if(stk.empty() || s[i] != stk.top()) {
                stk.push(s[i]);
            }
            else {
                stk.pop();
            }
        }
        
        //消除完成后，将栈中的元素重新组合为字符串
        string res;
        while(!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    string s = "abbaca";
    Solution sol;
    cout << sol.removeDuplicates(s) << endl;
    return 0;

}