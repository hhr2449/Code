#include <iostream>
#include <unordered_map>
using namespace std;


//给定两个字符串，判断两个字符串是否是字母异位词
//实际上就是判断两个字符串的字符出现的种类和次数是否相同
//可以使用一个hashMap,key是
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> note;
        if(s.length() != t.length()) {
            return false;
        }
        //1. 注意如果访问note中没有的key，那么会自动建立一个键值对，而且value是默认值0
        //这里我们就可以同时遍历两个字符串，一个进行加，一个进行减，遍历完成后再遍历这个note，如果里面每个键值对的value都是0，说明是anagram
        for(int i = 0; i < s.length(); i++) {
            note[s[i]]++;
            note[t[i]]--;
        }
        //可以通过迭代器来遍历map
        for(auto i = note.begin(); i != note.end(); i++) {
            if(i->second != 0) {
                return false;
            }
        }
        return true;
        
    }
};
int main() {
    Solution s;
    cout << s.isAnagram("anagram", "naragma");
}