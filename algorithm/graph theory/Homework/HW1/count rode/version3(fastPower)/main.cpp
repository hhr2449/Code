//快速幂思想：
//将n^k表示为n^(2^0),n^(2^1),n^(2^2),n^(2^3)....n^(2^m)的乘积
//根据n^(2^m) = (n^(2^(m-1)))^2的性质，可以快速计算出n^k
//首先将幂次拆分为二进制，如果二进制的第i为为1，则将n^(2^(i-1))乘到结果中
#include<iostream>
#include<vector>
using namespace std;
//数的快速幂
int fastPower(int base,int power){
    int res = 1;//储存结果
    //从低位到高位遍历幂次power的二进制
    //如果当前查看的位为1，则成base（base就是当前二进制位对应的拆分项）
    //base自乘，power右移一位
    while(power > 0){
        if(power & 1){
            res *= base;
        }
        power >>= 1;
        base *= base;
    }
    return res;
}
void test(){
    int base1 = 2;
    int base2 = 3;
    int power1 = 10;
    cout << fastPower(base1,power1) << endl;
    cout << fastPower(base2,power1) << endl;
}

//矩阵快速幂跟数的快速幂原理相同，只是把数的乘法改成了矩阵的乘法，1改成单位矩阵
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
vector<vector<long long>> fastMatrixPower(vector<vector<long long>> matrix,int power,int n){
    vector<vector<long long>> res(n+1,vector<long long>(n+1,0));
    for(int i = 1;i<=n;i++){
        res[i][i] = 1;
    }
    while(power > 0){
        if(power & 1){
            res = matrixMulti(res,matrix,n);
        }
        power >>= 1;
        matrix = matrixMulti(matrix,matrix,n);
    }
    return res;
}
int main(){
    int n,m,s,t,k;
    cin >> n >> m >> s >> t >> k;
    vector<vector<long long>> matrix1(n+1,vector<long long>(n+1,0));
    vector<vector<long long>> matrix2(n+1,vector<long long>(n+1,0));
    int u,v;
    for(int i=0;i<m;i++){
        cin >> u >> v;
        matrix1[u][v] += 1;
        matrix2[u][v] += 1;
    } 
    matrix1 = fastMatrixPower(matrix1,k,n);
    long long res = matrix1[s][t];
    cout << res % 1000003;
}