#include <iostream>
#include <regex>
using namespace std;
int main() {
    string s1 = "simple";
    regex r1("simpl.");
    cout << regex_match(s1, r1) << '\n';//regex_match是匹配**整个**字符序列，如果满足要求则返回true
    regex r2("simp..");//.是通配符，代表任意单个字符
    cout << regex_match(s1, r2) << '\n';
    regex r3("simp...");
    cout << regex_match(s1, r3) << '\n';
    // regex_match可以用作单纯的匹配判断,也可以匹配获得具体的结果
  	// 匹配的结果存放在smatch中.smatch中0索引存放完整匹配的结果,1存放第1个()匹配的结果
  	// 从smatch中取元素,既可以用[],也可以用str(idx)
  	smatch res1;//存放匹配结果
    regex r4("(foot)(ball)\\.(txt)");//()表示捕获组，可以匹配并获取括号中的东西
    //  \\.代表实际上的一个字符.，因为.是通配符，所以要转义为\\.
    s1 = "football.txt";
    cout << regex_match(s1, res1, r4) << '\n';//可以在验证字符序列是否符合要求的同时获取匹配的结果，存放在smatch中
    //res1[0]存放的是整个匹配的结果，res1[1]存放的是第一个()匹配的结果，res1[2]存放的是第二个()匹配的结果，以此类推。
    cout << res1[0] << ' ' << res1[1] << ' ' << res1[2] << ' ' << res1[3] << '\n';
    //量词：*，+，？
    //  '*'代表前面的字符（a），分组((ab))或字符集([a-c])可以出现任意次
    //  '+'代表至少出现一次
    //  '?'代表出现0次或1次
    regex r5("a*b");
    s1 = "b";//a出现0次
    cout << regex_match(s1, r5) << '\n';
    s1 = "aaaab";//a出现4次
    cout << regex_match(s1, r5) << '\n';
    regex r6("(ab)+c");//ab出现1次或多次，c出现1次,可以匹配abc,ababc,abababc
    s1 = "abc";
    cout << regex_match(s1, r6) << '\n';
    s1 = "ababc";
    cout << regex_match(s1, r6) << '\n';
    regex r7("[a-b]?c");
    s1 = "ac";
    cout << regex_match(s1, r7) << '\n';
    s1 = "abc";
    cout << regex_match(s1, r7) << '\n';
    
}