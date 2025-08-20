#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。

如果剩余字符少于 k 个，则将剩余字符全部反转。
如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
*/
//每次跳跃2k，然后选择反转前面k个元素即可

class Solution {
public:
    string reverseStr(string s, int k) {
        //每次加上2k，那么从下标为i开始的k个（或者是到尽头）的元素需要反转
        for(int i = 0; i < s.size(); i+=2*k) {
            //注意前闭后开
            if(i + k > s.size()) {
                reverse(s.begin() + i, s.end());
            }
            else {
                reverse(s.begin() + i, s.begin() + i + k);
            }

        }
        return s;
    }
};
int main() {
    Solution s;
    string str = "abcdefg";
    cout << s.reverseStr(str, 2);
}