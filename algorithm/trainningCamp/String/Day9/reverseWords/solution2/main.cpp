#include <iostream>
#include <string>
#include <vector>
using namespace std;


//优化solution1中的方法，其实不需要对s进行截取，只需要维护一个pos，用于指向当前遍历到的地方
class Solution {
public:
    string reverseWords(string s) {
        string res;
        vector<string> words;
        //加上空格，方便截取最后一个单词
        s += " ";
        int pos = 0;
        while(1) {
            if(pos >= s.size()) {
                break;
            }
            //跳过前面的空格
            while(pos < s.size() && s[pos] == ' ') {
                pos++;
            }
            int tmp = s.find(" ", pos);
            if(tmp != string::npos) {
                string str = s.substr(pos, tmp - pos);
                words.push_back(str);
                pos = tmp;
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