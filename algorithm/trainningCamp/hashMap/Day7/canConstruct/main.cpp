#include <iostream>
#include <string>
using namespace std;

//其实就是magazine中的代码能否构成ransonNote
//与之前异位词的那道题很相似，可以直接采用数组进行字母的统计，先遍历magazine，然后再遍历ransomNote
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        //这里的数组其实就是一个哈希表，哈希函数为h(key) = key-97
        int note[26];
        for(int i = 0; i < magazine.length(); i++) {
            note[magazine[i]-97]++;
        }
        for(int i = 0; i < ransomNote.length(); i++) {
            note[ransomNote[i]-97]--;
        }
        for(int i = 0; i < 26; i++) {
            if(note[i] < 0) {
                return false;
            }
        }
        return true;
        
    }
};

int main(){
    
}