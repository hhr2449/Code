#include<iostream>
#include<queue>
#include<algorithm>
const int MAXN = 16;
const int INF = 1000000;
using namespace std;
struct Road {
    //始点默认为1
    int e;//终点
    int k;//已经访问的节点个数
    int sumv;//当前道路总长
    int lb;//当前道路所形成的回路长度下界
    bool visited[MAXN];//当前道路访问过的节点
    bool operator< (const Road& other) const{//注意是const，否则会报错
        return other.lb < lb;//注意这里的小于号含义反过来了
    }
};
int n, low, up;
int dis[MAXN][MAXN];
bool dfs_visited[MAXN];
priority_queue<Road> pq;
int dfs(int u, int k, int l) {//u为当前节点，k为访问节点个数，l为当前路径总长度，使用贪心dfs来得到一个粗略的上界
    if (k == n) {//已经走过了n个节点，形成了H道路，只需要在回到起点即可
        return l + dis[u][1];
    }
    //选择后继节点中距离最小的节点走
    int minDis = INF;
    //遍历所有节点，找到距离最小的节点，并且走到哪个节点
    for (int i = 1; i <= n; i++){
        if (!dfs_visited[i] && dis[u][i] < minDis) {
            minDis = dis[u][i];
            u = i;
        }
    }
    dfs_visited[u] = true;
    return dfs(u, k+1, l+minDis);//以u为起点，继续走

}
void getUp() {//使用贪心法得到初始上界，方便后面剪枝
    dfs_visited[1] = true;
    up = dfs(1, 1, 0);
}
void getLow() {//得到初始下界
    low = 0;
    for (int i = 1; i<=n; i++) {//遍历每一行
        int temp[MAXN];
        for (int j = 1; j<=n; j++) {
            temp[j] = dis[i][j];
        }
        sort(temp+1, temp+n+1);//将每一行排序
        low += temp[1];//加上每一行的最小值
    }
}
void getLb(Road& road) {//得到特定一条道路形成的回路的距离下界
    //（道路距离的两倍+到路径起点的最短距离+到路径终点的最短距离+其他没有访问的节点的最短出入边）/2
    int res = 2*road.sumv;
    int min1 = INF, min2 = INF;
    //回到起点的距离最小值
    for(int i = 1; i<=n; i++) {
        if(!road.visited[i]) {
            if(dis[i][1] < min1) {
                min1 = dis[i][1];
            }
        } 
    }
    res += min1;
    //到路径终点的距离最小值
    for(int i = 1; i<=n; i++) {
        if(!road.visited[i]) {
            if(dis[i][road.e] < min2) {
                min2 = dis[i][road.e];
            }
        }
    }
    res += min2;
    for(int i = 1; i<=n; i++) {
        if(!road.visited[i]) {
            for(int j = 1; j<=n; j++) {
                if(!road.visited[i]) {
                    if(dis[i][j] < min1) {
                        min1 = dis[i][j];
                    }
                }
            }
            for(int j = 1; j<=n; j++) {
                if(!road.visited[i]) {
                    if(dis[j][i] < min2) {
                        min2 = dis[i][j];
                    }
                }
            }
        }
        res += (min1 + min2);
    }
    road.lb = (res+1)/2;
}
int solution() {
    getUp();
    getLow();
    Road r;//初始化一条道路（只有始点）
    r.e = 1;
    r.k = 1;
    r.sumv = 0;
    r.lb = low;//此时的下界就是初始下界
    for (int i = 1; i<=n; i++) {
        r.visited[i] = false;
    }
    r.visited[1] = true;
    int res = INF;//最终的答案
    pq.push(r);//将r放入队列
    while(!pq.empty()) {//开始bfs
        Road tem = pq.top();//将队列中的道路取出
        pq.pop();
        if(tem.k == n-1) {//如果已经访问了n-1个节点
            int p;//寻找没有访问的节点
            for(int i = 1; i<=n; i++) {
                if(!tem.visited[i]) {
                    p = i;
                    break;
                }
            }
            //形成的H道路长度为：道路长度+终点到到未访问节点+未访问节点到起点
            int ans = tem.sumv + dis[tem.e][p] + dis[p][1];
            if(ans <= tem.lb) {//因为是优先队列，先出的是下界最小的，所以如果ans小于下界，那么后面的道路也小于下界，可以直接确定这就是答案
                res = min(res,ans);
                break;
            }
            else {
                res = min(res, ans);//更新答案
                up = min(up, ans);//更新上界
                continue;
            }
        }
        //扩展道路
        Road next;
        for(int i = 1; i<=n; i++) {//遍历当前点的所有后继节点
            if(!tem.visited[i]) {
                next = tem;
                next.e = i;
                next.k++;
                next.sumv += dis[tem.e][i];
                next.visited[i] = true;
                getLb(next);
                if(next.lb < up) {//只有后继节点的下界小于当前的上界，才需要将其放入队列
                    pq.push(next);
                }
            }
        }
    }
    return res;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> dis[i][j];
            if (i == j)
            {
                dis[i][j] = INF;
            }
        }
    }
    cout << solution() << endl;
    return 0;
}
//总体思路：bfs+优先队列+界值剪枝
//研究的对象Road，代表一条道路，用结构体来表示
//优先队列：按照下界从大到小排序，下界越小，越有可能找到最优解，所以越先出队
//使用dfs贪心得到最初上界，取每行最小值得到最初下界
//getLb函数：得到特定一条道路形成的回路的距离下界
//bfs：从起点开始，逐步扩展道路，并且使用界值剪枝，只有后继节点的下界小于当前的上界，才需要将其放入队列 
//当当前道路形成了H回路时，更新答案和界值，并且继续下一轮bfs