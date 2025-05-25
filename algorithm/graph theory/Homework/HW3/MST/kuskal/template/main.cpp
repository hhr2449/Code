#include <iostream>
#include <algorithm>
using namespace std;
struct Edge {//边结构体，包含起点，终点，权值
    int pre, to;
    int w;
};
int n, m, num = 0, ans = 0;//n是节点数，m是边数，num是已经选取的节点数,ans是最小生成树的权值
Edge edge[200005];//用于储存边
int fa[10005];//储存节点的父节点
bool cmp(Edge a, Edge b) {//定义比较函数，用于后边边权的排序
    return a.w < b.w;
}
void init(int n) {//并查集操作：初始化
    for(int i = 1; i < n+1; i++ ) {
        fa[i] = i;
    }
}
int find(int x) {//并查集操作：查找根节点
    return fa[x] == x ? x : fa[x] = find(fa[x]);//优化：路径压缩
}
void merge(int x, int y) {//将两个节点所处的集合合并
    int a = find(x);
    int b = find(y);
    if(a != b) {
        fa[a] = b;
    }
}
void addEdge(Edge e) {//将边添加进生成树中
    ans +=e.w;//将边权加到ans中
    merge(e.pre, e.to);//将边的两端节点所处的集合合并
}
int kruskal(int n, int m) {
    init(n);
    sort(edge+1, edge + m+1, cmp);//排序
    for(int i = 1; i < m+1; i++) {//从小到大遍历所有边
        if(num == n-1) {//加到边数满足生成树要求时结束
            break;
        }
        if(find(edge[i].pre) != find(edge[i].to)) {//如果加入这个边不成环（即两个端点不在同一个集合中）
            addEdge(edge[i]);//则加边
            num++;
        }
    }
    return ans;
}
int main() {
    cin >> n >> m;
    for(int i = 1; i < m+1; i++) {
        cin >> edge[i].pre >> edge[i].to >> edge[i].w;
    }
   kruskal(n, m);

    if (num == n - 1) {
        cout << ans << endl;
    } else {
        cout << "orz" << endl;
    }
}
//kruskal思路：将边权值由小到大排列，从小到大遍历所有的边，如果加入后不成环，则加入，否则不加入，最后凑够n-1个顶点就是最小生成树


/*
测例：
6 7
1 2 4
2 6 3
5 6 5
5 4 4
3 4 1
2 3 8
2 4 6
17
*/