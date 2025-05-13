#include <string>
#include <iostream>
#include <map>
using namespace std;
//map的元素是pair<key, val>,类型的，即键值对，可以通过key来查询对应的值
//map中的key值必须不同（val可以相同）
int main() {
    map<string, int> s;
    s.insert(make_pair("Monday", 1));
    //可以使用key来访问对应的值
    cout << "key:Monday" << "对应的值是" << s["Monday"] << '\n'; 
    s["Monday"] = 10086;
    cout << "key:Monday" << "对应的值是" << s["Monday"] << '\n'; 
    //如果没有对应的key，则会建立一个新的键值对
    s["Tusday"] = 2;
    cout << "key:Tusday" << "对应的值是" << s["Tusday"] << '\n'; 
    //使用find查询键为key的元素，返回迭代器
    map<string, int>::iterator it = s.find("Monday");
    cout << (*it).first << (*it).second << '\n';
    cout << s.count("Monday") << '\n';
}