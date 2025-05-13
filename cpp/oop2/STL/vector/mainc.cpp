#include <iostream>
#include <vector>
using namespace std;
//迭代器：
//一种检查容器内元素并遍历容器内元素的数据类型
//使用上类似于指针，可以解引用
//begin()返回的是指向vector首元素的迭代器,end()返回的是指向末元素的后一个元素的迭代器（前闭后开）
void print(vector<int> vec) {
    //vector<int>::iterator代表的就是vector<int>类型的迭代器
    for(vector<int>::iterator i = vec.begin(); i != vec.end(); ++i) {
        cout << *i << ' ';
    }
    cout << '\n';
}
//迭代器失效：
//1.当调用insert/erase函数时，原有元素的位置会发生改变，导致迭代器失效（删除/增加元素处及之后的迭代器）
//2.掉用Push_back函数时，可能会发生失效
//vector的原理：vector创建时会预留出capacity大小的空间，此为最大容量限制
//当size超过capacity时，vector会重新申请一片2*capacity的空间，导致原来的迭代器失效
void iteratorFailure(vector<int> vec) {
    for(vector<int>::iterator i = vec.begin(); i != vec.end(); ++i) {
        cout << *i << ' ';
        vec.push_back(*i);
        //边输出，边放入，使得size大于capacity，最后出现迭代器失效
    }
}
int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    cout << vec.size() << '\n';
    print(vec);
    cout << *(vec.begin() + 3) << '\n';
    //iteratorFailure(vec);
    auto i = vec.begin() + 2;
    vec.erase(vec.begin() + 1);
    cout << *i << '\n';
    
}
//原则：不要在改变容器之后使用原来的迭代器