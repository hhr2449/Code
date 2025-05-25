#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cmath>
#define ll  long long
using namespace std;
//还是堆优化的prim算法，但是采用了数组模拟的链式前向星：
//使用edge矩阵来储存所有的边（无向图，所以有两倍大小），head[i]表示节点i的第一条邻接边的索引，从head[u]开始遍历可以获取所有以u为起点的边
//Edge中的next表示的是下一条边的索引
struct Edge {
    int to, next;
    ll w;
    //to是边的终点，w是边的权值，next是下一条边的索引
    //比如说head[u] = k,那么e[k]就是以u为起点的第一条边，e[k].next就是以u为起点的第二条边的索引
}edge[18000000];
int head[5005], vis[5005], k, n, cnt;//dis储存的是节点到当前的树的最短距离，这是动态更新的，树每增加一个节点都要更新
long long ans, dis[5005];
priority_queue<pair<ll, int>,vector<pair<ll, int>>, greater<pair<ll, int>>> q;//使用pair代表一个节点，前一个是节点编号，后一个是节点距离树的距离
void add(int u, int v, ll w) {
    k++;//k是边的索引
    edge[k].to = v;//e[k]的终点是v
    edge[k].w = w;//权值为w
    edge[k].next = head[u];//使用头插法，将e[k]作为u的第一条邻接边，这样e[k]的下一条边就是u的当前第一条邻接边
    //链表终点的next为-1，这是由后面初始化head为-1来决定的
    head[u] = k;//u的第一条邻接边索引为k
}
void prim() {
    ans = 0, cnt = 0;
    q.push(make_pair(0, 1));
    while(!q.empty()&&cnt < n) {
        ll w = q.top().first;
        int u = q.top().second;
        q.pop();
        if(vis[u]) {
            continue;
        }
        vis[u] = 1;
        ans += w;
        cnt++;
        for(int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].to;
            ll w = edge[i].w;
            if(!vis[v]) {
                if(w < dis[v]) {
                    dis[v] = w;
                    q.push(make_pair(w, v));
                }
            }
        }
    }
}
int main() {
    memset(head, -1, sizeof(head));//注意一定要初始化head为-1，这样才有终点
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    memset(vis, 0, sizeof(vis));
    int a, b;
    pair<int, int> p[3005];//储存点
    cin >> n;
    //这是一个完全图，采取输入一个点，建立该点与其他所有点之间的边的方式建图
    for(int i = 1; i <= n; i++) {
        cin >> a >> b;
        p[i] = make_pair(a, b);
        for(int j = 1; j < i; j++) {
            ll dx = p[i].first - p[j].first;
            ll dy = p[i].second - p[j].second;
            ll tmp_w = abs(dx*dx*dx) + abs(dy*dy*dy);
            add(i, j, tmp_w);
            add(j, i, tmp_w);//注意因为是无向图，所以需要添加两次
        }
    }
    prim();
    cout << ans << '\n';

}
//!注意这道题的数据非常大，所以一定要使用long long，否则会溢出