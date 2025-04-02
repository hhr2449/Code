#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n,m,s;
vector<vector<int>> graph;
vector<int> vis;
queue<int> q;
void dfs(int cnt, int p){
    if(cnt == n){
        return;
    }
    for(int i=graph[p].size()-1;i>=0;i--){
        if(!vis[graph[p][i]]){
            cout << graph[p][i] << ' ';
            vis[graph[p][i]] = 1;
            dfs(cnt+1,graph[p][i]);
        }
    }
}
void bfs(){
    vis[s] = 1;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        cout << u << ' ';
        q.pop();
        for(int i=graph[u].size()-1;i>=0;i--){
            if(!vis[graph[u][i]]){
                vis[graph[u][i]] = 1;
                q.push(graph[u][i]);
            }
        }
    }
}
int main(){
    cin >> n >> m >> s;
    graph.resize(n+1);
    vis.resize(n+1,0);

    int u,v;
    for(int i=1;i<=m;i++){
        cin >> u >> v;
        graph[u].push_back(v);
    }
    bfs();
    cout << '\n';
    fill(vis.begin(),vis.end(),0);
    cout << s << ' ';
    vis[s] = 1;
    dfs(0,s);
}