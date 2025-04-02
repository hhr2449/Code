#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    //push函数将元素压入队列尾部
    //队列遵循先进先出原则
    cout << "队列的大小为" << q.size() << '\n';
    cout << q.front() << '\n';//front()函数返回头部元素
    cout << q.back() << '\n';//back()函数返回尾部元素
    //从头至尾遍历队列
    while(!q.empty()){
        cout << q.front() << ' ';
        q.pop();//pop()函数将头部函数弹出
    }
}