#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    vector<int> b(n+1,0);
    vector<int> s(n+1,0);
    vector<int> m(n+2,0);
    vector<int> s_a(n+1,0);
    vector<int> s_b(n+1,0);
    int sum = 0;
    for(int i=0;i<n+1;i++){
        cin >> a[i];
        sum += a[i];
        s_a[i] = sum;
    }//a的前缀和
    sum = 0;
    for(int i=1;i<n+1;i++){
        cin >> b[i];
        sum += b[i];
        s_b[i] = sum;
    }//b的前缀和
    int min_all = 0;
    int x = 0;
    for(int i=0;i<n+1;i++){
        x -=a[i];
        if(x<0){
            min_all += -x;
            x = 0;
        }
        x +=b[i+1];
    }//求没有坏点时至少需要的能量
    for(int i = n;i>0;i--){
        m[i] = max(max(a[i],m[i+1]+a[i]-b[i+1]),0);
    }//求到达某个点时至少要有的能量
    for(int i=1;i<n+1;i++){
        cout << max(min_all,m[i]+s_a[i-1]-s_b[i-1]) << ' ';
    }
}
//思考其中的不变量：无论那个点出问题，“要求”是不变的，也就是想要通过后面的点，必须在第i个点至少具有的能量是固定的，某个点出问题影响的只是实际走的时候能够得到的能量
//设m(i)为第i个点处至少需要的能量（吃掉了b(i)），m(i) = max{a(i),m(i+1)+a(i)+b(i+1),0}
//则能够通过第i-n个点的充要条件是在第i个点处能量为m(i)
//求出没有坏点是至少需要的能量，实际上第i个点坏掉不会影响前面的点的情况，也就是通过前面1~i-1的充要条件是能量至少为min_all
//综合起来可以得到第i个点坏掉时w(i) = max{min_all, m(i)+sum_a(i-1)-sum_b(i-1)}