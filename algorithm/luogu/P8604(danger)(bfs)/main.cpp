//1.邻接表的表示
//2.bfs
//3.队列的使用
//整体思路：引入一个变量delP来表示删掉的节点，使用bfs来判断在删除delP节点时两点之间是否存在道路
//如果不存在道路，则说明时危险节点，只要遍历所有节点就可以得到答案
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n,m;
int isRoad = 0;
int ans = 0;
vector<vector<int>> graph;//储存图（邻接表）
vector<int> vis;//记录节点是否被访问
queue<int> q;//队列
void clear(){
    while(!q.empty()){
        q.pop();
    }
}
//使用dfs来判断两个节点之间是否存在道路
bool bfs(int start,int end,int delP){
    q.push(start);
    vis[start] = 1;//起点先入队列
    while(!q.empty()){//直到队列为空
        int u = q.front();
        q.pop();//将队列中最前面的节点弹出
        //遍历弹出节点的所有相邻节点，如果其没有被访问或者删除，则加入队列
        for(int i=0;i<graph[u].size();i++){
            if(graph[u][i] == end){//如果此时相邻节点是终点，则说明两个节点之间存在道路
                clear();
                return true;
            }
            if(vis[graph[u][i]]||graph[u][i] == delP){
                continue;
            }
            q.push(graph[u][i]);
            vis[graph[u][i]] = 1;
        }
    }
    return false;
}
int main(){
    cin >> n >> m;
    graph.resize(n+1);
    vis.resize(n+1,0);
    int u,v;
    for(int i = 1;i<=m;i++){
        cin >> u >> v;//输入两个节点，表示两个节点之间有道路
        //这里是无向图，所以两个节点之间是双向的，所以要将两个节点都加入到对方的邻接表中
        graph[u].push_back(v);//将点v加入到u的邻接表中
        graph[v].push_back(u);//将点u加入到v的邻接表中
    }
    //邻接表的表示：可以使用链表，但是比较麻烦，所以这里使用二维的向量来表示
    //graph[i]是一个向量，表示的是节点i的邻接节点
    cin >> u >> v;
    if(!bfs(u,v,0)){//不删除节点的情况下，如果两个节点之间没有道路，则返回-1
        cout << -1;
        return 0;
    }
    else{
        for(int i=1;i<n+1;i++){//遍历节点1~n
            if(i != u && i != v){//不包含始点和终点
                fill(vis.begin(),vis.end(),0);//每次要重新初始化访问数组
                if(!bfs(u,v,i)){//如果删除节点i后，两个点之间不存在道路，则说明i是一个危险节点
                    ans++;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
//dfs步骤：
//1.起点入队列，并记录已经访问
//2.构建循环，直到队列为空
//3.取出队列中的第一个元素
//4.遍历该元素的所有相邻节点，如果没有被访问，则加入队列，并记录已经访问
//如果相邻节点为终点，则说明有道路，如果循环结束还没有到达，则说明没有道路