#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    //求解next数组
    vector<int> getNext(string needle) {
        int n = needle.size();
        //注意next数组的设定：
        //1. 0处特殊初始化为-1
        //2. next[i]表示[0,i-1]这个子串的最大公共前后缀长度
        //3. 搜索的时候，如果第j个字符处发生适配，那么j应该移动到next[j]
        vector<int> next(n);
        next[0] = -1;
        //j表示前缀子串的结束字符（指向-1说明为空），i表示当前字符串的结束字符（其实是在求next[i+1]）
        //注意j=-1的情况需要特殊处理
        int j = -1, i = 0;
        while(i < n - 1) {
            if(j == -1 || needle[i] == needle[j]) {
                j++;
                i++;
                //注意一定要先移动在设置next的值，因为当前我们的字符串是[0,i]（i自增前），那么对应的是next中的i+1
                next[i] = j;
            }
            else {
                //回退的原理：
                //假设此时[0,j-1]和[i-a+1,i-1]相同，但是j和i不匹配
                //j回退到next[j]，其实就是回到[0,j-1]这个子串的最大公共前后缀的前缀后一个单位
                //回退后的j满足[0,j-1]和[i-j,i-1]相同，此时只要i,j匹配就可以找到最大公共前后缀
                j = next[j];
            }
        }
        return next;


    }
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        vector<int> next = getNext(needle);

        //使用next数组进行匹配
        int i = 0;//txt的指针
        int j = 0;//par的指针
        while(i < m) {
            //如果相等则i,j均前进，如果不相等则j根据next进行回退
            //j=-1代表par[0]和txt[i]也不匹配，此时应该移动i,j
            if(j == -1 || haystack[i] == needle[j]) {
                i++;
                j++;
                //如果指针j到达needle的末尾的后一个单位，则完全匹配
                if(j == n) {
                    return i - n;
                }
            }
            else {
                //注意此时i不能前进，j改变后还要和当前的i进行比较
                j = next[j];
            }
        }
        return -1;
    }
};
int main() {
    Solution s;
    string haystack = "sadbutsad", needle = "sad";
    cout << s.strStr(haystack, needle);
}   