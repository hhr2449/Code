#include <iostream>
#include <string>
#include <vector>
using namespace std;


//思路：
//1.调整格式，去除前面，后面的空格，单词之间仅保留一个空格
//2.直接将整个字符串进行反转
//3.再对每个单词进行反转

//!技巧：如何对一个字符串的格式进行调整
//!有一个常用的方法就是使用双指针剔除指定元素，这样可以实现o(1)的空间复杂度和o(n)的时间复杂度
//!同时可以在剔除的过程中融入其他操作，比如这里可以在剔除空格的同时加上引入单词间空格

//!字符串（数组）处理的技巧：1. 使用快慢指针   2.先进行扩容，然后从后往前遍历       这两种方法均可以实现o(1)的时间复杂度

class Solution {
public:
    //左闭右闭的反转
    void reverse(string& s, int start, int end) {
        while(start < end) {
            swap(s[start++], s[end--]);
        }
    }
    string reverseWords(string s) {
        //使用双指针来处理字符串
        //维护一个快指针和一个慢指针，使用快指针来遍历字符串
        //如果不是空格，就丢进慢指针的位置处，同时当一个单词结束的时候丢入一个空格
        int slow = 0, fast = 0;
        for(; fast < s.size(); fast++) {
            //非空格和单词后面的空格保留
            //注意要处理最后一个单词和fast=0的情况
            if(fast == 0 && s[0] == ' ') {
                fast++;
            }
            if(!(s[fast] == ' ' && s[fast - 1] == ' ')) {
                s[slow++] = s[fast]; 
            }
        }
        if(s[slow - 1] == ' ') {
            slow--;
        }
        //注意要resize，修改后的大小由slow决定
        s.resize(slow);

        //反转整个字符串
        reverse(s, 0, s.size() - 1);

        //反转单词
        int start = 0, end = 0;
        while(start < s.size() && end < s.size()) {
            //start之后的第一个空格
            while(end < s.size() && s[end] != ' ') {
                end++;
            }
            //此时end有两种可能，可能处于整个串的末尾的后面，也可能处于单词后面的空格
            reverse(s, start, end - 1);
            if(end >= s.size()) {
                break;
            }
            //start一定是在下一个要反转的单词的开头
            end++;
            start = end;
        }
        return s;
    }
};
int main() {

    string s = "  hello world  ";
    Solution so;
    cout << so.reverseWords(s) + "|";

}