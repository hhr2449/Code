#include<iostream>
#include<vector> 
using namespace std;
class Solution {
    public:
        vector<vector<int>> generateMatrix(int n) {
            vector<vector<int>> res(n,vector<int>(n,0));
            int s_num = 1;
            //外层循环遍历圈
            for(int i=0;i<=n/2;i++){
                //内层循环遍历每一圈的四条边
                //只要确定了一条边的开始位置，数字个数，初始值就可以绘出一个圈
                for(int j=0;j<n-2*i-1;j++){//按照左闭右开的方式绘制
                    res[i][i+j] = s_num;
                    res[i+j][i+n-2*i-1] = s_num+n-2*i-1;
                    res[i+n-2*i-1][i+n-2*i-1-j] = s_num+2*(n-2*i-1);
                    res[i+n-2*i-1-j][i] = s_num+3*(n-2*i-1);
                    //最好还是拆成四个for循环，然后每次s_num都++，更符合绘制的思路，同时避免了初始值的计算
                    s_num++;
                }
                s_num+=3*(n-2*i-1);
            }
            if(n%2==1){
                res[n/2][n/2] = n*n;
            }
            return res;
        }
    };
int main(){
    Solution s;
    vector<vector<int>> res = s.generateMatrix(4);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}