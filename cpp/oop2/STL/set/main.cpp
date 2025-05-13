#include <iostream>
#include <set>
using namespace std;
int main() {
    //set用于元素的查找，插入，删除很高效
    //适用于储存元素唯一的情况，或是用于查找是否存在某种元素，也可用于去重
    set<int> s;
    //插入元素
    s.insert(1);
    s.insert(10);
    s.insert(12);
    s.insert(13);
    s.insert(20);
    s.insert(20);
    //1.元素唯一，插入多个相同元素，集合最终只会保留一个
    //2.集合中元素储存默认升序，而不是按照插入的顺序
    for(int num : s) {
        cout << num << ' ';
    }
    cout << '\n';
    //同样可以使用迭代器遍历set
    for(set<int>::iterator it = s.begin(); it != s.end(); ++it) {
        cout << *it << ' ';
    }
    cout << '\n';
    //s.find(val)，用于查询某值在set中的位置，注意如果查询到了会返回对应值的迭代器，如果没有，则返回s.end()
    if(s.find(20) != s.end()) {
        cout << "20 is in this set" << '\n';
    }
    if(s.find(100) == s.end()) {
        cout << "100 is not in this set" << '\n';
    }
    //删除集合中的元素
    s.erase(20);
    for(int num : s) {
        cout << num << ' ';
    }
    cout << '\n';
    //s.count(val),统计val存在的个数（实际上只会是0/1）
    cout << s.count(20);
}