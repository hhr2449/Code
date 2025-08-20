#include <iostream>
#include <vector>
using namespace std;


//前缀和思想：可以计算出数组的前缀和，这样在求区间和的时候可以直接调用前缀和进行相减，相比于每次进行累加，复杂度大大减少
//一般用于求区间和
int main() {

    int n, a, b, sum = 0;
    cin >> n;
    vector<int> v(n);
    //这里可以不用储存具体的某一个值，只需要设置变量sum，边累加边记录前缀和即可
    for(int i = 0; i < n; i++) {
        cin >> a;
        sum += a;
        v[i] = sum;
    }

    //注意求解区间，如果要求[a,b]区间和，应该使用v[b]-v[a-1]，并且讨论a==0的情况
    while(cin >> a >> b) {
       if(a == 0) {
        cout << v[b] << '\n';
       }
       else {
        cout << v[b] - v[a - 1] << '\n';
       }
    }



}