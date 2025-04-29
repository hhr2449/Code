#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
const int MaxN = 1005;
const int INF = 2147483647;
using namespace std;
struct Node {//节点结构体，储存节点编号和到该节点的最短距离
    int id, dis;
    bool operator<(const Node& a) const {//重载<，使得优先队列按照dis从小到大排序
        return a.dis < dis;
    }
};
struct Edge {//边结构体，to是终点，w是权值
    int to, w;
};
vector<vector<Edge>> graph;
int dis[MaxN];
int IsPerma[MaxN];
int pre[MaxN]; 
int n, m;
priority_queue<Node> q;//优先队列
void dijkstra() {
    q.push((Node){0,0});
    while(!q.empty()) {
        Node tem = q.top();//取出队列中的首元素，其具有最小的距离
        q.pop();
        int k = tem.id;
        if(IsPerma[k]) {//验证取出的节点是否为永久标记的节点
            continue;
        }
        IsPerma[k] = 1;//如果不是永久节点，则标记为永久，并且对其后继进行松弛
        for(int i = 0; i < graph[k].size();i++) {
            int to = graph[k][i].to;
            int w = graph[k][i].w;
            if(dis[k] + w < dis[to]) {
                dis[to] = dis[k] + w;
                pre[to] = k; //记录前驱节点
                q.push((Node){to,dis[to]});//如果后继节点得到更新，则要进入队列
            }
        }
        if(IsPerma[n-1]) {
            break;
        }
    }
}
int main(){
    cin >> n >> m;
    graph.resize(n+1);
    int u, v, w;
    for(int i = 0; i < m;i++){//使用vector构造边列表，graph[u]里面储存的是u节点为起点的边
        cin >> u >> v >> w;
        graph[u].push_back((Edge){v,w});
    }
    for(int i = 0; i < n;i++) {
        dis[i] = INF;
        pre[i] = -1;
    }
    dis[0] = 0;
    for(int i = 0; i < n;i++) {
        IsPerma[i] = 0;
    }
    dijkstra();
    cout << dis[n-1] << '\n';
    if(dis[n-1] != INF) {
        vector<int> path;
        for(int at = n-1; at != -1; at = pre[at]) {
            path.push_back(at);
        }
        reverse(path.begin(), path.end());
        for(int node : path) {
            cout << node << " ";
        }
    }
}