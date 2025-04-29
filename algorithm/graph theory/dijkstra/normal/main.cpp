/*    dijksqtra的板子
void dijkstra(){
    for(int i=1;i<=n;i++){
        int k = -1;
        for(int j=1;j<=n;j++){
            if(!isPerma[j]&&dis[j]!=INT_MAX){
                if(k == -1||dis[j]<dis[k]){
                    k = j;
                }
            }
        } //!找出最小的非永久节点
        if(k == -1){
            return;
        } //!如果找不到非永久节点了，说明所有可达节点都已经永久化了
        isPerma[k] = 1;
        ///!对后继节点进行松弛操作
        for(int a = 0;a<graph[k].size();a++){
            int v = graph[k][a];
            if(!isPerma[v]&&dis[k]+1<dis[v]){
                dis[v] = dis[k]+1;
            }
        }
    }
}
*/
#include <iostream>
#include <vector>
using namespace std;
struct Node{
    int to, w;//to是边的终点，w是边权
};
const int MaxN = 100005;
const int INF = 1000000000;
int n, m, s;
int IsPerma[MaxN];
int dis[MaxN];
vector<vector<Node>> graph;//graph[i]表示节点i的邻接表
void dijkstra() {
    for(int i = 1;i <= n;i++) {
        int k = -1;//!找出最小的非永久节点
        //遍历所有节点，找出最小的非永久节点k
        for(int j = 1;j <= n;j++) {
            if(!IsPerma[j] && dis[j] != INF) {
                if(k == -1 || dis[j] < dis[k]) {//k为-1或是当前节点的距离小于k的距离，则更新k
                    k = j;
                }
            }
        }
        if (k == -1){//找不到非永久节点了，说明所有节点都已经变成永久的了，结束
            return;
        }
        IsPerma[k] = 1;//将k标注为永久节点
        //松弛操作
        for(int i = 0;i < graph[k].size();i++) {
            if(!IsPerma[graph[k][i].to] && dis[k] + graph[k][i].w < dis[graph[k][i].to]) {
                dis[graph[k][i].to] = dis[k] + graph[k][i].w;
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
        graph[u].push_back((Node){v,w});
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
        if(dis[i] == INF){
            cout << 2147483647 << " ";
            continue;
        }
        cout << dis[i] << " ";
    }
}

