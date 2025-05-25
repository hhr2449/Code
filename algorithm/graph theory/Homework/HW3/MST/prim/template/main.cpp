#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
int m, n, ans = 0, cnt = 0;
bool vis[5005] = {false};//用于确认节点是否在树中
vector<int> dist;
struct Node {
    int id;
    int dis = INT_MAX;
    bool operator < (const Node& n) const {
        return dis > n.dis;
    }
};
struct Edge {
    int to, w;
};
vector<vector<Edge>> v;
priority_queue<Node> q;
void prim() {
    q.push((Node){1, 0});
    while(!q.empty()&&cnt < n) {
        Node t = q.top();
        q.pop();
        if(vis[t.id]) {
            continue;
        }
        vis[t.id] = true;
        cnt++;
        ans += dist[t.id];//添加节点
        for(auto i : v[t.id]) {//i是Edge
            if(!vis[i.to]) {
                if(i.w < dist[i.to]) {//更新相连的边并且添加到队列中
                    dist[i.to] = i.w;
                    q.push({i.to, i.w});
                }
            }
        }
    }
}
int main() {
    cin >> n >> m;
    v.resize(n+1);
    dist.resize(n+1, INT_MAX);
    dist[1] = 0;
    for (int i = 1; i <= m; i++) {
        int x, y, w;
        cin >> x >> y >>w;
        v[x].push_back(Edge{y, w});
        v[y].push_back(Edge{x, w});
    }
    prim();
    if(cnt < n) {
        cout << "orz" << '\n';
    }
    else {
        cout << ans << '\n';
    }
}

//prim算法：每次将距离树最近的节点和边加上如树中