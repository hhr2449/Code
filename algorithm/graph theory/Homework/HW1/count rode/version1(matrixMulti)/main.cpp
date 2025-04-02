#include<iostream>
#include<vector>
using namespace std;
vector<vector<long long>> matrixMulti(vector<vector<long long>> matrix1,vector<vector<long long>> matrix2,int n){
    vector<vector<long long>> matrixTemp(matrix1.size(),vector<long long>(matrix2[0].size(),0));
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            for(int k = 1;k<=n;k++){
                matrixTemp[i][j] += ((matrix1[i][k]%1000003)*(matrix2[k][j]%1000003))%1000003;
                matrixTemp[i][j] %= 1000003;
            }
        }
    }
    return matrixTemp;
}//实现矩阵乘法
int main(){
    int n,m,s,t,k;
    cin >> n >> m >> s >> t >> k;
    //在数据比较大时，最好使用long long
    vector<vector<long long>> matrix1(n+1,vector<long long>(n+1,0));
    vector<vector<long long>> matrix2(n+1,vector<long long>(n+1,0));
    int u,v;
    //基本原理：A^k中的i,j元几位经过k条边从节点i到节点j的路径数
    //但是这里有重边和自环，自环不用单独处理，但是重边会造成影响
    //所以在生成邻接矩阵时，直接将重边的数量记录在矩阵中
    //原理：A[i][k]*A[k][j]的结果代表的就是i->k->j的路径数，如果有重边，比如A[i][k] = 2，那么就有两条i->k的路径
    for(int i=0;i<m;i++){
        cin >> u >> v;
        matrix1[u][v] += 1;
        matrix2[u][v] += 1;
    } 
    for(int i=1;i<k;i++){
        matrix1 = matrixMulti(matrix1,matrix2,n);
    }
    long long res = matrix1[s][t];
    cout << res % 1000003;
}
//求模的方法：(a+b)%c = (a%c+b%c)%c
//           (a*b)%c = (a%c*b%c)%c
//           (a-b)%c = (a%c-b%c+c)%c
//根据求模的运算性质可以在计算的过程中求模，避免数据溢出