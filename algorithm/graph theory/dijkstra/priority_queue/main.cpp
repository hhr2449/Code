//这里使用了优先队列进行优化
//思路类似，只是在寻找最短距离的非永久节点时使用优先队列来降低查找的时间
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Edge{
    int to, w;//to是边的终点，w是边权
};
struct Node{//节点结构体，包含节点编号和距离
    int id, dis;
    bool operator < (const Node& a) const {
        return a.dis < dis;
    }
};
priority_queue<Node> q;//优先队列，用于储存节点
const int MaxN = 100005;
const int INF = 2147483647;
int n, m, s;
int IsPerma[MaxN];
int dis[MaxN];
vector<vector<Edge>> graph;//graph[i]表示节点i的邻接表
void dijkstra() {
    q.push((Node){s,0});//将起点入队
    while(!q.empty()){
        Node tem = q.top();//取出队首元素（即队列中距离最小的节点）
        q.pop();
        int k = tem.id;
        if(IsPerma[k]) {//检验取出的节点是否为永久节点，如果是则跳过
            continue;
        }
        IsPerma[k] = 1;//将k标注为永久节点
        //松弛操作
        for(int i = 0;i < graph[k].size();i++) {
            if(!IsPerma[graph[k][i].to] && dis[k] + graph[k][i].w < dis[graph[k][i].to]) {
                dis[graph[k][i].to] = dis[k] + graph[k][i].w;
                q.push((Node){graph[k][i].to,dis[graph[k][i].to]});//将松弛后的节点重新入队
            }
        }
    }
}
int main() {
    cin >> n >> m >> s;
    graph.resize(n+1);
    int u,v,w;
    //注意图的储存方法，这里用了邻接表储存，vector[i]储存第i个点的后继节点
    for(int i = 1;i <= m;i++){
        cin >> u >> v >> w;
        graph[u].push_back((Edge){v,w});
    }
    for(int i = 1;i <= n;i++){
        IsPerma[i] = 0;
    }
    for(int i = 1;i <= n;i++){
        dis[i] = INF;
    }
    dis[s] = 0;
    dijkstra();
    for(int i = 1;i <= n;i++){
        cout << dis[i] << " ";
    }
    
}

