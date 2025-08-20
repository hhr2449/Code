#include <bits/stdc++.h>
using namespace std;
int main() {
    string s = "1  ";
    int i = 0;
    char tmp = s[i];
    while(tmp == ' ' && i < s.size()) {
        i++;
        tmp = s[i];
    }
    //截取子串，从下标i处开始，截取到末尾
    s = s.substr(i);
    cout << s.size() << endl;
}