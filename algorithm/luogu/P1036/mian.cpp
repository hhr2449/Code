#include<iostream>
#include<vector>
using namespace std;
int n,k,count=0;
vector<int> v(n);
bool isPrime(int n){//判断是否是素数
    if(n==1){
        return true;
    }
    for(int i = 2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
//关键在于怎么找到所有的数的组合
//考虑采用递增的选取方式，当前选取了第i个数，剩下的数只能从i+1开始,同时记录递归的变量为位置和选到了第几个数
void dfs(int chooseStep,int sum,int curPosition){
    if(chooseStep>k){
        if(isPrime(sum)){
            count++;
        }
        return;
    }
    for(int i=curPosition;i<n-k+chooseStep;i++){
        sum += v[i];
        dfs(chooseStep+1,sum,i+1);
        sum -= v[i];
    }
}

int main(){
    cin >> n >> k;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    dfs(1,0,0);
    cout << count << endl;
    return 0;
}