#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
int n, k, x, y;
//用来储存到达某个位置的时候剩余步数,如果为-1，说明没有到达过
vector<vector<int>> map;
//用来保存某个访问路径中的访问情况
vector<vector<bool>> visited;
int ans = 0;
//移动方式
vector<pair<int, int>> move_mode= {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1 ,-2}, {-2, -1}, {-2, 1}, {-1, 2}};
//表示从x,y开始，还能移动n步的移动过程
void move(int x, int y, int k) {
    //如果当前的位置已经访问过并且之前访问的时候剩余步数大于现在剩余的，那么之前的情况一定包含当下的,则不用继续了
    //如果在本次访问路径中已经访问过了这个位置，则不用继续了
    if(k <= map[x][y] || visited[x][y]) {
        return;
    }
    //接下来就是当前格子没有被访问过或是之前访问时剩余次数小于当前
    //如果没有访问，ans++
    if(map[x][y] == -1) {
        ans++;
    }
    map[x][y] = k;
    visited[x][y] = true;
    for(int i = 0; i < move_mode.size(); i++) {
        int target_x = x + move_mode[i].first;
        int target_y = y + move_mode[i].second;
        if(target_x >= 0 && target_x < n && target_y >= 0 && target_y < n) {
            move(target_x, target_y, k - 1);
            //回溯
            visited[target_x][target_y] = false;
        }
    }
}
int main() {
    scanf("%d %d %d %d", &n, &k, &x, &y);
    x--, y--;
    map.resize(n, vector<int>(n, -1));
    visited.resize(n, vector<bool>(n, false));
    move(x, y, k);
    printf("%d\n", ans);
}