#include <iostream>
#include <vector>
using namespace std;
struct Node {
    int x;
    int w;
    int next = 0;
    int MyNum;
    Node() = default;
    Node(int _x,int _w,int _num):x(_x),w(_w),MyNum(_num){}
};
struct Edge{
    int u;
    int v;
    int w = 0;
};
int main(){
    int n,m;
    cin >> n >> m;
    vector<Edge> edge(m+1);
    vector<vector<int>> matrix(n+1,vector<int>(n+1,0));
    vector<vector<Node>> EdgeList(n+1);
    vector<Node> EdgeNode(m+1);
    int u,v,w;
    for(int i=1;i<=m;i++){
        cin >> u >> v >> w;
        edge[i].u = u;
        edge[i].v = v;
        edge[i].w = w;
        if(matrix[u][v] == 0){
            matrix[u][v] = w;
        }
        else{
            matrix[u][v] = -1;
        }

    }
    for(int i=1;i<=n;i++){//找以第i个节点为起始节点的边链表（即第i个链表）
        int flag = 0;//用于判断链表是否为空
        for(int j=m;j>=1;j--){//从后往前遍历所有的边
            if(edge[j].u == i){
                if(flag == 1){
                    EdgeList[i][EdgeList[i].size()-1].next = j;
                    EdgeNode[EdgeList[i][EdgeList[i].size()-1].MyNum].next = j;
                }
                EdgeList[i].push_back(Node(edge[j].v,edge[j].w,j));
                EdgeNode[j] = Node(edge[j].v,edge[j].w,j);
                flag = 1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    for(int i=1;i<=n;i++){
        if(EdgeList[i].size() == 0){
            cout << 0 << '\n';
        }
        else{
            cout << EdgeList[i][0].MyNum << '\n';
        }
    }
    for(int i=1;i<=m;i++){
        cout << EdgeNode[i].x << " " << EdgeNode[i].w << " " << EdgeNode[i].next << endl;
    }
}