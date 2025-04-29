#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <queue>
using namespace std;
int n;
vector<double> v;
vector<double> s;
vector<int> lable;//lable[i]表示原图中的顶点i在变化后的图中的编号，即label[i] = j表示顶点i在变化后的图中的顶点编号是j
vector<int> IsDel;
vector<double> costTime;
vector<int> outDegree;
struct Edge{
    int start;
    double w;
};
struct Node{
    int id;
    int num;
};
vector<vector<Edge>> graph;
vector<vector<Edge>> graph_;//graph_表示变化后的图，其中的graph_[lable[i]]表示的就是原图中以i为终点的边，to随即修改为lable[to]
//计算每个生产条件用时，p为技术编号，w为生产的目标量
//生产条件用时就是边权值
double calculateTime(int p, double w) {
    if(v[p] * s[p] <= 1e-9) return 0; // 防止除零
    double discriminant = 1 + 8*w/(v[p]*s[p]);
    int k = floor((sqrt(discriminant) - 1)/2); // 精确二次方程求根
    k = max(k, 0);
    
    double sum = v[p] * s[p] * k * (k + 1) / 2;
    double remaining = max(w - sum, 0.0);
    double t = remaining / ((k+1) * v[p]);
    
    return k * s[p] + t;
}
void reNum() {
    //这里使用了拓扑排序，将图中的节点重新编号，使得点由小指向大
    //思路：统计节点入度，将入度为零的节点入队，之后每出队一个节点，
    //就将其放入重新排序的数组中，同时将其所有后继节点的入度减一，之后再次将入度为零的节点入队
    //直到队列为空，此时重新排序的数组就是拓扑排序的结果
    //这里使用出度来进行排序，思路是一样的，只不过是将入度为零的节点入队，
    queue<int> s;
    int cnt = n;
    for(int i = 1; i <= n; i++) {
        if(outDegree[i] == 0) {
            s.push(i);
        }
    }
    while(!s.empty()) {
        int u = s.front();
        s.pop();
        lable[u] = cnt;
        cnt--;
        for(int i = 0; i < graph[u].size(); i++) {
            outDegree[graph[u][i].start]--;
            if(outDegree[graph[u][i].start] == 0) {
               s.push(graph[u][i].start); 
            }
        }
    }
}
void reBuild() {
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < graph[i].size(); j++){
            graph_[lable[i]].push_back((Edge){lable[graph[i][j].start], graph[i][j].w});
        }
    }
}
double solution() {
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < graph_[i].size(); j++) {
            costTime[i] = max(costTime[i], costTime[graph_[i][j].start] + graph_[i][j].w);
        }
    }
    return costTime[lable[n]];//注意原图中的节点n在变化后的图中的编号是lable[n]
}
int main() {
    cin >> n;
    v.resize(n);//生产速度
    s.resize(n);//新建生产线的时间
    lable.resize(n+1);
    IsDel.resize(n+1,0);
    costTime.resize(n+1,0);
    outDegree.resize(n+1,0);
    graph.resize(n+1);//建图，使用PT图，p是q的前置技术，则存在e(p,q)，边权值为满足生产量要求所需时间
    graph_.resize(n+1);
    for(int i = 1; i <= n-1; i++) {
        cin >> v[i];
    }
    for(int i = 1; i <= n-1; i++) {
        cin >> s[i];
    }
    int cntP = 0, p_ = 0;
    double w_ = 0, time = 0;
    for(int i = 1; i <= n; i++) {
            cin >> cntP;
        for(int j = 1; j <= cntP; j++) {
            cin >> p_ >> w_;
            outDegree[p_]++;
            time = calculateTime(p_, w_);
            graph[i].push_back((Edge){p_, time});//注意这里graph[i]表示的是以i为终点的边
        }
    }
    reNum();
    reBuild();
    cout << fixed << setprecision(1) << solution() << endl;
}