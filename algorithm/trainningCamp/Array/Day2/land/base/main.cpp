//思路：可以求出行和列的前缀和
//将一行或是一列当成一个整体
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> land(n, vector<int>(m, 0));
    //分别是行和列的前缀和
    vector<int> row(n);
    vector<int> column(m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> land[i][j];
        }
    }
    int sum = 0;
    //求行的前缀和，i代表第i行
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            sum += land[i][j];
        }
        row[i] = sum;
    }
    //总面积
    int sumAll = sum;
    //求列的前缀和
    sum = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            sum += land[j][i];
        }
        column[i] = sum;
    }

    //面积之差其实就是总的减去2倍的第i个前缀和
    int res = INT_MAX;
    for(int i = 0; i < n-1; i++) {
        res = min(res, abs(sumAll - 2*row[i]));
    }
    for(int i = 0; i < m-1; i++) {
        res = min(res, abs(sumAll - 2*column[i]));
    }
    cout << res;


}