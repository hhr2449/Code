#include<iostream>
#include<vector>
using namespace std;
vector<vector<long long>> matrixMulti(vector<vector<long long>> matrix1,vector<vector<long long>> matrix2,int n){
    vector<vector<long long>> matrixTemp(matrix1.size(),vector<long long>(matrix2[0].size(),0));
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            for(int k = 1;k<=n;k++){
                matrixTemp[i][j] += ((matrix1[i][k]%1000000007)*(matrix2[k][j]%1000000007))%1000000007;
                matrixTemp[i][j] %= 1000000007;
            }
        }
    }
    return matrixTemp;
}//实现矩阵乘法
vector<vector<long long>> fastMatrixPower(vector<vector<long long>> matrix,long long power,long long n){
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
    long long n,k;
    cin >> n >> k;
    vector<vector<long long>> matrix(n+1,vector<long long>(n+1,0));
    for(int i=1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cin >> matrix[i][j];
        }
    }
     matrix = fastMatrixPower(matrix,k,n);
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}