#include <iostream>
#include <vector>
using namespace std;

//学会将问题拆分！！！
//首先先建模，可以用二维的vector来表示这个螺旋矩阵，那么vector中的下标对应的就是矩阵中格子的坐标
//直接思考如何画出螺旋矩阵很难，
//但是可以将画矩阵的过程进行拆分，发现画矩阵的过程可以拆成若干个画圈的过程
//只要给出起点坐标，起点数，圈的边长就可以绘制出一个圈
//循环一下就可以得到矩阵

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int>(n, 0));
        int num = 1, len = n;
        for(int i = 0; i < (n+1)/2; i++) {
            generateCircle(i, i, num, len, v);
            len -= 2;
        }
        return v;
    }

    void generateCircle(int x, int y, int& num, int len, vector<vector<int>> &v) {
        if(len == 1) {
            v[x][y] = num;
        }
        for(int i = 0; i < len - 1; i++) {
            v[x][y] = num;
            num++;
            y++;
        }
        for(int i = 0; i < len - 1; i++) {
            v[x][y] = num;
            num++;
            x++;
        }
        for(int i = 0; i < len - 1; i++) {
            v[x][y] = num;
            num++;
            y--;
        }
        for(int i = 0; i < len - 1; i++) {
            v[x][y] = num;
            num++;
            x--;
        }
    }
};

int main() {

    Solution s;
    int n = 3;
    vector<vector<int>> v(n, vector<int>(n, 0));
    v = s.generateMatrix(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;

}