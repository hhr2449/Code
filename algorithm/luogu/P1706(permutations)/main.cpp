#include<iostream>
#include<vector>
using namespace std;
vector<int> v;//储存序列
int n;
vector<int> vis;//储存访问情况
void print(){//打印输出
    for(int i=1;i<n+1;i++){
        cout << "    " << v[i];
    }
    cout << '\n';
}
void dfs(int x){//深搜，x为当前深搜的位置
    if(x>n){
        print();
        return;
    }
    for(int i=1;i<n+1;i++){
        if(!vis[i]){//若没有访问过，则访问
            vis[i]=1;//记录，表示已经访问
            v[x]=i;//加入序列
            dfs(x+1);//递归到下一步
            vis[i]=0;//回溯，表示未访问
        }
    }
}
int main(){
    cin >> n;
    v.resize(n+1);
    vis.resize(n+1,0);
    dfs(1);
    return 0;
}