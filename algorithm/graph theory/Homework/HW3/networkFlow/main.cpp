#include <bits/stdc++.h>
#define ll long long
using namespace std;
//带点权的问题一般拆用拆点建图，即把一个点拆成一条边，点权即为边权，经过该边就是经过该点
/*
要避免编号冲突和混乱，一般采用如下编号方式：
原点数量：n
节点 i 的 入口编号为 2*i
节点 i 的 出口编号为 2*i+1
i的出口和入口连接一条单向边，边容量为点的容量
节点i的所有入边的终点变成2*i,所有出边的起点变成2*i+1
源点 s = 2*0（原始点 0 的入口）
汇点 t = 2*n+1（原始点 n 的出口）
总共节点数为 2*n，注意包括源和汇。
*/
ll n, m, cap[90][90], flow[90][90], n_, s, t, parent[90], ans = 0;
//使用bfs寻找增流道路
//!注意，不要使用上课时的两种增流道路的做法来思考，这样还要处理边的方向，非常麻烦，应该在后面增流时引入反向边来解决，bfs时只要寻找正常方向的增流道路
bool bfs() {
    int vis[90];//记录点是否访问
    memset(vis, 0, sizeof(vis));
    queue<ll> q;//队列
    q.push(s);
    while(!q.empty()) {
        ll u = q.front();
        q.pop();
        for(int i = 0; i < n_; i++) {
            if(cap[u][i] - flow[u][i] > 0 && vis[i] == 0) {//边的流量还没有满
                q.push(i);
                vis[i] = 1;
                parent[i] = u;//记录路径上节点的父节点，这样可以从汇点回溯获取道路
                if(i == t) {                   
                    return true;
                }
            }
        }
    }
    return false;
}
void edmondsKarp() {
    while(bfs()) {//不停地寻找增流道路，没有增流道路时结束
        ll addFlow = INT_MAX;
        for(int i = t; i != s; i = parent[i]) {
            addFlow = min(addFlow, cap[parent[i]][i] - flow[parent[i]][i]);
        }
        ans += addFlow;
        //!关键:在对正向边进行增流时要将方向边的容量增大相同的量，这样做的目的是给与“反悔的机会”
        //!如果之后走了反向边，那就相当于对原先的正向边进行减流
        for(int i = t; i != s; i = parent[i]) {
            flow[parent[i]][i] += addFlow;
            cap[i][parent[i]] += addFlow;
        }
    }
}
int main() {
    memset(cap, 0, sizeof(cap));
    memset(flow, 0, sizeof(flow));
    cin >> n >> m;
    n_ = 2*n + 3;//有n个中间点，需要拆成两个，源点需要拆成两个，汇点不需要拆
    s = 0;//拆完点后的源点标号
    t = 2*n + 2;//拆完点后的汇点标号
    for(int i = 0; i < n+1; i++) {
        cin >> cap[2*i][2*i+1];
    }
    ll u, v, w;
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;//原本点u连到点v的边应该变成从点u出口连到点v入口的边
        if(w == -1) {
            cap[2*u+1][2*v] = INT_MAX;
        }
        else {
            cap[2*u+1][2*v] += w;
        }
    }
    edmondsKarp();
    cout << ans;
}
//如何在搜索过程中保存搜索路径：
//搜到一个节点的同时保存该节点的父节点，当搜到目标节点时，从目标节点开始回溯就可以找到一条路径