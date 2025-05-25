#include <iostream>
#include <cstring>
using namespace std;
int n, m, graph[20][20], color[20], res = 100, colorRes[20];
bool judge(int x, int color_) {
    for(int i = 1; i <= n; i++) {
        if(graph[x][i] == 1 && color[i] == color_) {
            return false;
        }
    }
    return true;
}

void dfs(int x) {
    if(x == n+1) {
        int max_ = 0;
        for(int i = 1; i <= n; i++) {
            max_ = max(max_, color[i]);
            colorRes[i] = color[i];
        }
        res = min(res, max_);
        return;
    }
    for(int i = 1; i < res; i++) {
        if(judge(x, i)) {
            color[x] = i;
            dfs(x+1);
            color[x] = 0;
        }
    }
}
int main() {
    cin >> n >> m;
    int a, b;
    memset(graph, 0, sizeof(graph));
    memset(color, 0, sizeof(color));
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    dfs(1);
    cout << res << '\n';
    for(int i = 1; i <= n; i++) {
        cout << colorRes[i] << ' ';
    }
}