#include <queue>
#include <iostream>
using namespace std;
struct Node {
    int x,y;
    bool operator < (const Node& a) const {
        int sum1 = x+y;
        int sum2 = a.x + a.y;
        return sum1 < sum2;
    }
};
int main() {
    priority_queue<int> q;//创建一个int类型的优先队列
    q.push(1);              //操作与普通队列类似，但是会自动排序，默认是从大到小排序
    q.push(100);
    q.push(-1);
    q.push(19);
    while(!q.empty()) {
        cout << q.top() << '\n';//注：返回顶部元素使用top()函数，而不是front()函数
        q.pop();
    } 
    cout << "-------------------" << '\n';
    int a[6] = {1,100,-1,1,-11,9};
    priority_queue<int,vector<int>,less<int> > q2;//这是一个从大到小排列的优先队列，less<int>表示从大到小排序，priority_queue<int>默认就是这个
    for(int i = 0; i < 6; i++) {
        q2.push(a[i]);
    }
    while(!q2.empty()) {
        cout << q2.top() << '\n';
        q2.pop();
    }
    cout << "-------------------" << '\n';
    priority_queue<int,vector<int>,greater<int> > q3;//使用greater代表从小到大排列
    for(int i = 0; i < 6; i++) {
        q3.push(a[i]);
    }
    while(!q3.empty()) {
        cout << q3.top() << '\n';
        q3.pop(); 
    }
    cout << "-------------------" << '\n';
    //可以使用自定义的数据类型来创建优先队列，但是要注意自定义数据类型必须重载 < 运算符，之后优先队列会按照重载的规则进行从大到小排列
    priority_queue<Node> q4;
    Node a1 = {1,1};
    Node a2 = {-100,20};
    Node a3 = {30,3};
    Node a4 = {10,10};
    Node a5 = {1000,-1022029};
    q4.push(a1);
    q4.push(a2);
    q4.push(a3);
    q4.push(a5);
    while(!q4.empty()) {
        cout << '(' << q4.top().x << ',' << q4.top().y << ')' << '\n';
        q4.pop();
    }
}