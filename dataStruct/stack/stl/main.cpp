#include<iostream>
#include<stack>
#include<list>
#include<vector>
using namespace std;
int main(){
    stack<int> s;
    stack<int, list<int>> s2;
    stack<int, vector<int>> s3;
    //stack是一个容器适配器，会将特定类封装为底层容器，来实现特定的数据结构
    //其有两个参数，第一个时存储元素的类型，第二个时底层容器的类型，默认是deque(也可以使用vector和list)
    //栈遵循后进先出的原则，只能在栈顶进行入栈和出栈
    //成员函数：push(),pop(),top(),empty(),size(),swap()
    for(int i=0;i<5;i++){
        s.push(i);//使用push()函数将元素压入栈顶
    }
    cout << "栈的大小为" << s.size() << '\n';
    cout << "栈顶元素为" << s.top() << '\n';
    //从顶到底遍历栈
    while(!s.empty()){
        cout << s.top() << ' ';//top()函数会返回栈顶元素
        s.pop();//pop()函数会将栈顶元素弹出
    }
}