#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
给你一个字符串 s ，请你反转字符串中 单词 的顺序。

单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。

返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。

注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。
*/



//思路：使用find函数查找空格，使用substr函数分割子串
/*
 find和rfind都包含pos本身
 find(str):从下标0处开始查找子串str，返回子串在字符串中的下标,如果没有返回string::npos
 find(str, pos):从下标pos开始查找子串str，返回子串在字符串中的下标，如果没有返回string::npos

 rfind(str):从字符串的最右侧开始查找
 rfind(str, pos):从pos开始反向查找

 substr(pos,count):截取从pos开始(含pos本身)的长度为count的子串，如果长度超过或者未指定则截取到末尾
*/
class Solution {
public:
    string reverseWords(string s) {
        string res;
        vector<string> words;
        //加上空格，方便截取最后一个单词
        s += " ";
        while(1) {
            //后移指针i，直到i指向的字符不为空或是i移动到末尾
            int i = 0;
            char tmp = s[i];
            while(tmp == ' ' && i < s.size()) {
                i++;
                tmp = s[i];
            }
            //截取子串，从下标i处开始，截取到末尾
            s = s.substr(i);
            if(s.size() == 0) {
                break;
            }
            //上面实现了去除前方的空格

            //从0开始查找空格,此时0处就是单词的第一个字母
            int pos = s.find(" ");
            //截取出单词，放入vector
            if(pos != string::npos) {
                string temp = s.substr(0, pos);
                words.push_back(temp);
                //把单词去除
                s = s.substr(pos);
            }
        }
        for(int i = words.size() - 1; i >= 0; i--) {
            res += words[i];
            if(i != 0) {
                res += " ";
            }
        }
        return res;
    }
};
int main() {

    string s = "the sky is blue";
    Solution so;
    cout << so.reverseWords(s) + "|";

}