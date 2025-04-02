#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int n;
int cnt = 0;
int flag = 0;
int pos = 0;
vector<int> a;
vector<int> k;
vector<int> vis;
queue<int> q;
//高速读入整型数据的函数
int read(){
    int x = 0,w = 1;
    char ch = 0;
    while(ch<'0'||ch>'9'){
        if(ch == '-')w = -1;
        ch = getchar();//使用getchar()函数读取字符效率更高
    }
    while(ch>='0'&&ch<='9'){
        x = x*10+ch-'0';
        ch = getchar();
    }
    return x*w;
}
//广度优先搜索函数
void bfs(){
    q.push(1);
    vis[1] = 1;
    while(!q.empty()){
        //通过层数来计数，当前队列中的点称为一层，这一层节点遍历完成后送入队列中的点就是下一层
        int levelSize = q.size();//统计层中的节点数，通过for循环来遍历这一层所有节点
        cnt++;
        //遍历队列中的节点的后继节点
        for(int j=0;j<levelSize;j++){
            int u = q.front();
            q.pop();
            int mostLen = min(n-u,k[u]);
            int endP;
            //关键优化：引入pos变量，pos变量记录了当前已经处理的右边界，右边界之前的所有节点都不需要再次遍历
            //避免重复处理节点
            //关键优化思想：减少重复，思考过程中有没有重复处理的部分，将这部分剪除
            if(u+mostLen <= pos){
                continue;
            }
            if(u+mostLen == n){
                flag = 1;
                return;
            }
            for(int i=max(pos+1-u,1);i<=mostLen;i++){
                endP = u+i-a[u+i];
                if(!vis[endP]){
                    vis[endP] = 1;
                    q.push(endP);
                }
            }
            pos = u+mostLen;
        }
    }
}
int main(){
    n = read();
    a.resize(n+1);
    k.resize(n+1);
    vis.resize(n+1,0);
    for(int i=1;i<=n;i++){
        a[i] = read();
    }
    for(int i=1;i<=n;i++){
        k[i] = read();
    }
    bfs();
    if(flag == 0){
        printf("-1");
        return 0;
    }
    printf("%d",cnt);
    return 0;
}