#include <iostream>
#include <vector>
using namespace std;
//定理：设s长为n，最大公共前后缀长为l
//则s是由重复子串构成的字符串的充要条件是l>0且n%(n-l)=0，同时重复子串就是公共前后缀的余子串
//必要性：假设重复子串长度为k，则n=mk,l=(m-1)k，则n-l=k
//充分性：见图片

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


    bool repeatedSubstringPattern(string s) {
        vector<int> next = getNext(s);
        int n = s.size();
        int l = next[n];
        if(l == 0) {
            return false;
        }
        if(n%(n-l) == 0) {
            return true;
        }
        else {
            return false;
        }
        
        
         
    }
};
int main() {
    Solution s;
    string str = "aba";
    cout << s.repeatedSubstringPattern(str);
}