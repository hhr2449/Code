#include<cstdio>
#include<vector>
#include<climits>
using namespace std;
int n;
int flag = 0;
vector<int> a;
vector<int> k;
vector<int> isPerma;
vector<int> dis;
int read(){
    int x = 0,w = 1;
    char ch = 0;
    while(ch<'0'||ch>'9'){
        if(ch == '-'){
            w = -1;
        }
        ch = getchar();
    }
    while(ch>='0'&&ch<='9'){
        x = x*10+ch-'0';
        ch = getchar();
    }
    return x*w;
}
void dijkstra(){
    for(int i=1;i<=n;i++){//n次循环，将每个节点都变成永久节点（考虑连通图的情况，实际上如果是非连通图到不了n次）
        //找出最小的非永久节点
        int minP = -1;
        for(int j=1;j<=n;j++){
            //判断条件：非永久并且dis[j]不等于无穷大
            if(!isPerma[j]&&dis[j]!=INT_MAX){
                if(minP==-1||dis[j]<dis[minP]){
                    minP = j;
                }
            }
        }
        //如果找不到非永久节点了，说明所有可达节点都已经永久化了
        if(minP == -1){
            return;
        }
        //确认n的最短路径就可以提前退出
        if(minP == n){
            flag = 1;
            return;
        }
        isPerma[minP] = 1;
        int mostLen = min(n-minP,k[minP]);
        int endP;
        //对后继节点进行松弛操作
        for(int len = 1;len<=mostLen;len++){
            endP = minP+len-a[minP+len];
            dis[endP] = min(dis[endP],dis[minP]+1);
        }
    }
}
int main(){
    n = read();
    a.resize(n+1);
    k.resize(n+1);
    isPerma.resize(n+1,0);
    dis.resize(n+1,INT_MAX);
    dis[1] = 0;
    for(int i=1;i<=n;i++){
        a[i] = read();
    }
    for(int i=1;i<=n;i++){
        k[i] = read();
    }
    dijkstra();
    if(!flag){
        printf("-1");
        return 0;
    }
    printf("%d",dis[n]);
}
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