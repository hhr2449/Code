#include<iostream>
#include<vector> 
using namespace std;
//这种题就是直接模拟，仿照人的做法
//找太多数学关系可能反而混乱
class Solution {
    public:
        vector<vector<int>> generateMatrix(int n) {
            vector<vector<int>> res(n,vector<int>(n,0));
            int x = 0,y = 0;//模拟一支笔，它的坐标是x,y
            int num = 1;
            int lenInCircle = n;
            while(lenInCircle > 1){
                for(int i = 0;i<lenInCircle-1;i++){
                    res[x][y+i] = num++;
                }
                y += lenInCircle - 1;
                for(int i = 0;i<lenInCircle-1;i++){
                    res[x+i][y] = num++;
                }
                x += lenInCircle - 1;
                for(int i = 0;i<lenInCircle-1;i++){
                    res[x][y-i] = num++;
                }
                y -= lenInCircle - 1;
                for(int i = 0;i<lenInCircle-1;i++){
                    res[x-i][y] =num++;
                }
                x -= lenInCircle - 2;
                y++;
                lenInCircle-=2;
            }
            if(lenInCircle == 1){
                res[x][y] = num;
            }
            return res;
        }
    };
int main(){
    Solution s;
    vector<vector<int>> res = s.generateMatrix(5);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}