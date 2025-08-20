/*
给定一个字符串 s，它包含小写字母和数字字符，请编写一个函数，将字符串中的字母字符保持不变，而将每个数字字符替换为number。
 例如，对于输入字符串 "a1b2c3"，函数应该将其转换为 "anumberbnumbercnumber"。
*/

#include <iostream>
#include <string>
using namespace std;
//现在思考能否不使用额外的空间来完成这个问题
//如果按照之前的想法从前向后遍历，那么每次插入number都需要对字符串进行分割和拼接，效率低下
//!数组，字符串填充问题的常见解题技巧：
//!先求得填充后的数组大小，然后预先对于数组进行扩容
//!然后从后向前对于数组进行填充
int main() {

    string s;
    cin >> s;
    int cnt = 0;
    //该指针用于遍历原本的字符串
    //从后往前进行遍历
    int sOldIndex = s.size() - 1;
    //统计使用的空间数，对于数组进行扩容
    for(int i = 0; i < s.size(); i++) {
        char c = s[i];
        if(c >= 48 && c <= 57) {
            cnt += 6;
        }
        else {
            cnt++;
        }
    }
    s.resize(cnt);
    //该指针用于填充新的字符串
    //从后往前进行填充
    int sNewIndex = s.size() - 1;
    while(sOldIndex >= 0) {
        char c = s[sOldIndex];
        if(c >= 48 && c <= 57) {
            s[sNewIndex--] = 'r';
            s[sNewIndex--] = 'e';
            s[sNewIndex--] = 'b';
            s[sNewIndex--] = 'm';
            s[sNewIndex--] = 'u';
            s[sNewIndex--] = 'n';
        }
        else {
            s[sNewIndex--] = c;
        }
        sOldIndex--;
    }
    cout << s;
}