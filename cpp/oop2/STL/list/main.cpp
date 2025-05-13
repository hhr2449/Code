//list的底层是双向链表
//不支持下标访问
//主要使用迭代器进行访问
//插入和删除操作不会导致迭代器失效（因为底层是链表，各个元素的储存地址是不连续的，所以插入和删除某个元素不会改变其他元素的储存地址）
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
//使用迭代器来遍历列表
void print1(list<int> &l) {
    for(list<int>::iterator it = l.begin(); it != l.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;
}
//同样可以遍历列表，但是列表同时会被清空
void print2(list<int> &l) {
    //l.empty(),判断是否为空
    while(!l.empty()) {
        //l.front(),返回列表的头部元素
        cout << l.front() << ' ';
        //l.pop_front(),删除列表的头部元素
        l.pop_front();
    }
    cout << endl;
}
int main() {
    list<int> l1;//空列表
    list<int> l2(5);//5个元素的列表,初始元素为0
    list<int> l3(5, 10);//5个元素的列表,初始元素为10
    list<int> l4 = {1, 2, 3, 4, 5};//直接初始化
    print1(l4);
    l4.push_back(6);//在列表后方插入
    l4.push_front(0);//在列表前方插入
    l4.insert(l4.begin(),9);//l.insert(pos,val)，指定位置插入元素（插入后,val的位置为Pos）
    //插入，删除元素效率高
    print1(l4);
    list<int>::iterator it = find(l4.begin(), l4.end(), 3);
    //可以使用find函数查找元素，但是还注意find不是list的成员函数，而是algorithm中的函数
    cout << *it << endl;
    print2(l4);
    cout << l4.size();
}