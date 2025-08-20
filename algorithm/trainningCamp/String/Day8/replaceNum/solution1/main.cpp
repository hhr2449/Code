/*
给定一个字符串 s，它包含小写字母和数字字符，请编写一个函数，将字符串中的字母字符保持不变，而将每个数字字符替换为number。
 例如，对于输入字符串 "a1b2c3"，函数应该将其转换为 "anumberbnumbercnumber"。
*/

#include <iostream>
#include <string>
using namespace std;
//最简单的思路就是开一个新的string，遍历一遍原本的string 即可
int main() {

    string s;
    cin >> s;
    string str;
    for(int i = 0; i < s.size(); i++) {
        char c = s[i];
        if(c >= 48 && c <= 57) {
            str += "number";
        }
        else {
            str += c;
        }
    }
    cout << str;
}