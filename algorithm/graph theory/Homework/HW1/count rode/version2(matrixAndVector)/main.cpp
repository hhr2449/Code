//例如A=（a1,a2,a3）则A^2 = A(a1,a2,a3) = (Aa1,Aa2,Aa3)
//以此类推，A^k = (A^(k-1)a1,A^(k-1)a2,A^(k-1)a3)
//所以我们想要得到i,j元并不需要计算A^k，只需要计算A^(k-1)aj即可
#include<iostream>
#include<vector>
using namespace std;
vector<long long> vectorMulti(vector<vector<long long>> matrix1,vector<long long> vector1,int n){
    vector<long long> vectorTemp(n+1,0);
    for(int i = 1;i<=n;i++){//得到向量的每一个元素
        for(int j = 1;j<=n;j++){
            vectorTemp[i] += ((matrix1[i][j]%1000003)*(vector1[j]%1000003))%1000003;
            vectorTemp[i] %= 1000003;
        }

    }
    return vectorTemp;
}//实现矩阵和向量的乘法

int main(){
    int n,m,s,t,k;
    cin >> n >> m >> s >> t >> k;
    vector<vector<long long>> matrix1(n+1,vector<long long>(n+1,0));
    vector<long long> vector1(n+1,0);
    int u,v;
    for(int i=0;i<m;i++){
        cin >> u >> v;
        matrix1[u][v] += 1;
        if(v == t){
            vector1[u] += 1;
        }
    } 
    for(int i=1;i<k;i++){
        vector1 = vectorMulti(matrix1,vector1,n);
    }
    long long res = vector1[s];
    cout << res % 1000003;
}