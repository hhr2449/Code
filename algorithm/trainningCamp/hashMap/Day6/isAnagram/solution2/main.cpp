#include <iostream>
#include <algorithm>
using namespace std;

//更简单的思路：直接对两个字符串进行排序，排完相等就返回true
class Solution {
public:

    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s == t) {
            return true;
        }
        else {
            return false;
        }
    }
};
int main() {
    Solution s;
    cout << s.isAnagram("anagram", "naragma");
}