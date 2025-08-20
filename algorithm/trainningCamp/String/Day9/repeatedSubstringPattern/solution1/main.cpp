#include <iostream>
#include <vector>
using namespace std;
//给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。

//思路：如果可以由一个重复字符串构成，那么这个重复字符串一定是公共前后缀
//这样我们只用遍历所有公共前后缀进行验证即可
//如何获得公共前后缀：
//!引理：s的任何一个公共前后缀都是s的最长公共前后缀的公共前后缀
//那么next[n]->next[next[n]]->……->0这个链条中就一定包含了所有公共前后缀

//这种方法比暴力硬算简便一点，但是还是o(n^2)的复杂度
class Solution {
public:
    vector<int> getNext(string& s) {
        int n = s.size();
        vector<int> next(n+1);
        int i = 0;
        int j = -1;
        next[0] = -1;
        while(i < n) {
            if(j == -1 || s[i] == s[j]) {
                i++;
                j++;
                next[i] = j;
            }
            else {
                j = next[j];
            }
        }
        return next;
    }


//!错误的思路---------------------------------------------

    // //!求解最小公共前后缀
    // //!这里利用了next数组，next[i]代表[0,i-1]这个子串的最大公共前后缀长度
    // //!实际上，s的最大公共前后缀的前缀的公共前后缀也是s的公共前后缀，而且长度一定会变小
    // //!这样可以利用next[n]->next[next[n]]->……这样不断迭代，寻找这个链条中的最小正整数即为最小公共前后缀
    // int minCommonPrefixSuffixLinear(string& s) {
    //     //获取next数组
    //     vector<int> next = getNext(s);
    //     int res = INT_MAX, i = s.size();
    //     while(i > 0) {
    //         if(next[i] > 0) {
    //             res = min(res, next[i]);
    //         }
    //         else {
    //             break;
    //         }
    //         i = next[i];
    //     }
    //     return res == INT_MAX ? 0 : res;

    // }

//!错误的思路---------------------------------------------

    bool repeatedSubstringPattern(string s) {
        vector<int> next = getNext(s);
        int i = next[s.size()];
        bool flag = false;
        while(i > 0) {
            //验证
            int len = i;
            string sub = s.substr(0, len);
            int cnt = s.size()/len;
            string res = "";
            for(int i = 0; i < cnt; i++) {
                res += sub;
            }
            if(res == s) {
                flag = true;
            }
            //验证完成
            i = next[i];
        }

        return flag;
        
        
         
    }
};
int main() {
    Solution s;
    string str = "aba";
    cout << s.repeatedSubstringPattern(str);
}