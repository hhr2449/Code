//只要能确定每位数的可能性有多少种，再把每位数的可能性乘起来就是最后的结果（注意变化的时候每位数是分别变化的，不是所有相同的数一起变化）
//要确定每位数的可能性，只需要确定0~9这10个数的变化的可能性就可以了
//进一步，如果把10个数看成节点，把变化规则看成有向边，那么问题就成了从一个节点出发能够到达其他节点的个数
//可以采用warshall算法求解，得到可达矩阵之后再统计行上1的个数即可
//!这种涉及状态及其转移的题目可以考虑抽象成图论求解
#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<int> multi(const vector<int> &a,int n){//高精度乘法
    vector<int> c;
    int t = 0;
    for(int i = 0;i<a.size()||t;i++){
        if(i<a.size()){
            t += a[i]*n;
        }
        c.push_back(t%10);
        t /= 10;
    }
    return c;
}
int main(){
    string n;
    int k;
    int a[10][10]={0};
    int b,c;
    cin >> n >> k;
    vector<int> v;
    for(int i=0;i<k;i++){//得到邻接矩阵
        cin >> b >> c;
        a[b][c]=1;
    }
    //warshall算法求可达矩阵
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<10;k++){
                if(a[j][k]==1||(a[j][i]==1&&a[i][k]==1)){
                    a[j][k]=1;
                }
            }
        }
    }
    for(int i = 0;i<10;i++){
        a[i][i] = 1;
    }//这道题目中保持自己也是一种，所以对角元为1
    
    int res[10] = {0};
    for(int i = 0;i<10;i++){
        for(int j = 0;j<10;j++){
            res[i]+=a[i][j];
        }
    }//得到每一种数字的变化可能数
    v = {1};
    for(int i = 0;i < n.size();i++){//遍历每一位，进行乘法
        v = multi(v,res[n[i]-'0']);
    }
    for(int i = v.size()-1;i>=0;i--){
        cout << v[i];
    }
}

