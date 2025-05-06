#include <iostream>
#include <algorithm>
#include <queue>
const int MAXN = 20;
const int INF = 1000000;
using namespace std;
int costH[MAXN][MAXN];//回合数消耗
int costF[MAXN][MAXN];//法力值消耗
int n, m;
int flag = 0;
struct Road {
    int node[MAXN];
    int k;
    int e;
    int sumH;
    int sumF;
    int lb;
    bool visited[MAXN];
    bool operator < (const Road& other) const {
        return other.lb < lb;
    }               
};
int up = INF;
bool dfsVisited[MAXN];
priority_queue<Road> pq;
Road minRoad;//记录最短路
int getLb(const Road& r) {//求解当前道路衍生出来的H道路的长度下界，用于剪枝（如果下界小于当前的界值，直接剪枝）
    int res = 2*r.sumH;//两倍的原道路长
    int min1 = INF, min2 = INF, max1 = 0;
    //最短的当前道路终点出边
    for(int i = 1;i <= n;i++) {
        if(!r.visited[i] && i != r.e) {
            min1 = min(min1, costH[r.e][i]);
        }
    }
    res += min1;
    //没有访问过的点分别找最短出边和最短入边
    for(int i = 1;i<=n;i++) {
        if(!r.visited[i]) {
            min1 = INF, min2 = INF;
            for(int j = 1;j<=n;j++){
                if(j != i && costH[j][i] < min1) {
                    min1 = costH[j][i];
                }
            }
            for(int j = 1;j<=n;j++){
                if(j != i && costH[i][j] < min2) {
                    min2 = costH[i][j];
                }
            }
            max1 = max(max(min1,min2),max1);//由于找的是道路，所以不用找回到终点的边，但是这样会导致当前算法中边多算了一条，所以选择减去最大的一条（下界计算宁小不大）
            res += min1+min2;
        }
    }
    res -= max1;
    return (1 + res)/2;
}
int solution() {
    for(int s = 1;s <= n;s++){//遍历所有起点可能
        while (!pq.empty()) pq.pop(); 
        Road r;
        r.e=s;
        r.sumH = 0;
        r.sumF = 0;
        r.k = 1;
        r.lb = getLb(r);
        r.node[1] = s;
        for (int i = 1; i<=n; i++) {
            r.visited[i] = false;
        }
        r.visited[s] = true;
        pq.push(r);
        while (!pq.empty()) {
            Road tem = pq.top();
            pq.pop();
            if(tem.k == n-1) {
                int p;
                for(int i = 1;i <= n;i++){
                    if(!tem.visited[i]) {
                        p = i;
                        break;
                    }
                }
                if(costH[tem.e][p] + tem.sumH < up && costF[tem.e][p] + tem.sumF <= m) {
                    up = costH[tem.e][p] + tem.sumH;
                    tem.node[tem.k + 1] = p;
                    minRoad = tem;
                    flag = 1;
                }
                continue;
            }
            Road next;
            for(int i = 1; i<=n; i++) {//遍历当前点的所有后继节点
                if(!tem.visited[i]) {
                    next = tem;
                    next.e = i;
                    next.k++;
                    next.sumH += costH[tem.e][i];
                    next.sumF += costF[tem.e][i];
                    next.visited[i] = true;
                    next.lb = getLb(next);
                    next.node[next.k] = i;
                    if(next.lb < up && next.sumF < m) {//只有后继节点的下界小于当前的上界，且消耗法力值小于m才需要将其放入队列
                        pq.push(next);
                    }
                }
            }
        }
    }
    return up;
}

int main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            cin >> costH[i][j];
        }
    }
    for (int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            cin >> costF[i][j];
        }
    }
    int ans = solution();
    if(flag == 0) {
        cout << -1;
        return 0;
    }
    cout << ans << '\n';
    for(int i = 1;i <= n;i++) {
        cout << minRoad.node[i] << ' ';
    }
}