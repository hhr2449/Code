#include <iostream>
#include <queue> 
using namespace std;
class Nums {
    public:
        int a;
        Nums(int a) {
            this->a = a;
        }

};
bool operator< (const Nums& x, const Nums& y) {
    if(x.a < y.a) {
        return false;
    }
    return true;
}
int main() {
    //队列先进先出
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    //优先队列，这里设置比较规则为greater<int>，所以从队尾到队首是降序
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(3);
    pq.push(0);
    pq.push(-1);
    pq.push(99);
    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    //!默认为大顶堆，也就是升序排列，但是在Nums类的<运算符重载中，设定为a小的大，所以最终显示出来的就是按照a的大小降序排列
    priority_queue<Nums> pq2;
    pq2.push(Nums(3));
    pq2.push(Nums(0));
    pq2.push(Nums(-1));
    pq2.push(Nums(99));
    while(!pq2.empty()) {
        cout << pq2.top().a << " ";
        pq2.pop();
    }

}