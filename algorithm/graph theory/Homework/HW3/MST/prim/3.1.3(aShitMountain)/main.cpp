#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
核心思路：
1. 使用朴素的Prim算法构建初始最小生成树
2. 对每个虫洞查询，通过BFS找到u到v的路径
3. 在路径中找到最大权值的边，决定是否用虫洞替换
4. 动态维护最小生成树的总权值
*/

int main() {
    // 关闭同步流加速输入输出（注意：使用后不能混用C和C++的输入输出函数）
    ios::sync_with_stdio(false);
    cin.tie(nullptr);//这样更快

    int n, q;
    cin >> n >> q;
    vector<pair<ll, ll>> coord(n+1);  // 储存星系坐标，下标从1开始

    // 读取星系坐标（注意：坐标可能为负数）
    for (int i = 1; i <= n; i++) {
        cin >> coord[i].first >> coord[i].second;
    }

    // ------ 第一阶段：构建初始最小生成树 ------
    const ll INF = (ll)4e18;  // 定义一个足够大的无穷大值
    vector<ll> dist(n+1, INF);  // 储存各节点到MST的最小距离
    vector<int> in_mst(n+1, 0);  // 标记节点是否已加入MST
    vector<int> prim_par(n+1, -1);  // 记录Prim算法的父节点（用于构建邻接表）
    dist[1] = 0;  // 从第一个星系开始构建MST
    ll total_cost = 0;  // 总成本

    // Prim算法主循环
    for (int it = 1; it <= n; it++) {
        // 寻找当前距离MST最近的节点（类似Dijkstra算法）这个思路参考了https://www.luogu.com.cn/problem/solution/P3366的题解
        int u = -1;
        ll best = INF;
        for (int i = 1; i <= n; i++) {
            if (!in_mst[i] && dist[i] < best) {
                best = dist[i];
                u = i;
        }
        }

        in_mst[u] = 1;  // 将节点u加入MST
        total_cost += best;  // 累加总成本

        // 松弛操作：更新所有未加入MST的节点的最小距离
        for (int v = 1; v <= n; v++) {
            if (!in_mst[v]) {
                // 计算超空间道路成本（注意使用三次方绝对值）
                ll dx = llabs(coord[u].first - coord[v].first);
                ll dy = llabs(coord[u].second - coord[v].second);
                ll w = dx*dx*dx + dy*dy*dy;  // 计算公式
                
                if (w < dist[v]) {  // 发现更小的距离
                    dist[v] = w;
                    prim_par[v] = u;  // 记录父节点用于构建邻接表
                }
            }
        }
    }

    // 构建MST的邻接表（用于后续查询路径）
    vector<vector<pair<int, ll>>> adj(n+1);  // adj[u]储存{u的邻居, 边权}
    for (int v = 2; v <= n; v++) {  // 注意从2开始，因为1是根节点
        int u = prim_par[v];
        // 重新计算边权保证一致性（避免浮点误差）
        ll dx = llabs(coord[u].first - coord[v].first);
        ll dy = llabs(coord[u].second - coord[v].second);
        ll w = dx*dx*dx + dy*dy*dy;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});  // 无向图双向添加
    }

    // 输出初始MST的总成本（没有使用任何虫洞）
    cout << total_cost << "\n";

    // ------ 第二阶段：处理虫洞查询 ------
    vector<int> parent(n+1);  // BFS查找路径时的父节点数组
    vector<ll> pw(n+1);       // 记录到父节点的边权
    vector<int> que(n);       // 手工实现的队列（比queue更快）
    
    while (q--) {
        int u, v;
        ll c;
        cin >> u >> v >> c;  // 读取虫洞参数

        // 使用BFS查找u到v在MST中的路径（树是联通的，所以一定能找到）
        fill(parent.begin(), parent.end(), -1);
        int qh = 0, qt = 0;    // 队列头尾指针
        que[qt++] = u;         // 初始节点入队
        parent[u] = 0;         // 标记u的父节点为0（特殊值）
        
        while (qh < qt && parent[v] == -1) {  // BFS直到找到v
            int x = que[qh++];  // 取出队列头
            for (auto &e : adj[x]) {  // 遍历所有邻接边
                int y = e.first;
                if (parent[y] == -1) {  // 未访问过的节点
                    parent[y] = x;
                    pw[y] = e.second;   // 记录边权
                    que[qt++] = y;      // 入队
                    if (y == v) break;  // 提前终止条件
                }
            }
        }

        // 回溯路径找出最大边（类似找环法）
        ll maxw = -1;
        int mxnode = -1;  // 记录最大边对应的子节点
        
        // 从v回溯到u，比较路径上的边权
        for (int x = v; x != u; x = parent[x]) {
            if (pw[x] > maxw) {  // 发现更大的边权
                maxw = pw[x];
                mxnode = x;  // 记录子节点（因为pw[x]是x到parent[x]的边权）
            }
        }

        // 决策是否替换边（虫洞成本更低时替换）
        if (c < maxw) {
            total_cost += (c - maxw);  // 更新总成本
            
            // 删除原最大边（双向删除）
            int a = mxnode, b = parent[mxnode];
            
            // 从a的邻接表中删除b
            auto &va = adj[a];
            for (auto it = va.begin(); it != va.end(); ++it) {
                if (it->first == b) {
                    va.erase(it);
                    break;
                }
            }
            
            // 从b的邻接表中删除a
            auto &vb = adj[b];
            for (auto it = vb.begin(); it != vb.end(); ++it) {
                if (it->first == a) {
                    vb.erase(it);
                    break;
                }
            }

            // 添加虫洞边（双向添加）
            adj[u].push_back({v, c});
            adj[v].push_back({u, c});
        }

        cout << total_cost << "\n";  // 输出当前总成本
    }

    return 0;
}
//!注意这道题的数据非常大，所以一定要使用long long，否则会溢出
//每次添加虫洞都会在原来的最小生成树的基础上形成一个环，只需要找到这个环并且将环的最长边删掉就可以得到最小生成树