//并查集可以对数据进行分组，并且实现不同组和合并（merging）和查询某个元素组别(finding)
//思路：并查集是一种树状结构，同一组元素构成一颗树，用树根节点来代表一个组
//merging:合并两个组，只需要将一个组的根节点指向另一个组的根节点即可
//finding:查询某个元素所在的组别，只需要找到这个元素所在的树根节点即可
//luogu P3367 【模板】并查集
#include <iostream>
using namespace std;

const int maxN = 200050;

int fa[maxN];//fa[i]代表节点i的父节点
int h[maxN];

void init(int n) {//n是节点数，这里是初始化各个节点的父节点，最开始时没有分组，可以看作每个节点都自成一组，父节点就是其本身
    for (int i = 0; i < n; i++) {
        fa[i] = i;
        h[i] = 0;
    }
    return;
}


int find(int x) {//递归实现
    return fa[x]==x ? fa[x] : fa[x] = find(fa[x]);
    //find的优化：原先查找根节点需要从某一个节点开始沿着父节点一直向上找，直到找到根节点，
    //但是现在可以利用fa[x] = find(fa[x])直接将组内的节点的父节点指向根节点，节约查找的时间
}

void merge(int x, int y) {
    int a = find(x);
    int b = find(y);//先找每一组的根节点
    if(a == b) {
        return;
    }
    //merge优化：引入h[i]代表i所在树的高度，将高度小的树合并到高度大的树中，尽量减少树的高度，从而减少遍历的节点数
    if(h[a] < h[b]) {
        fa[a] = b;
    }
    else {
        fa[b] = a;
        if(h[a] == h[b]) {
            h[a]++;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    init(n);
    int z, x, y;
    for (int i = 0; i < m; i++) {
        cin >> z >> x >> y;
        if(z == 1) {
            merge(x, y);
        }
        if(z == 2) {
            if(find(x) == find(y)) {
                cout << "Y" << endl;
            }
            else {
                cout << "N" << endl;
            }
        }
    }

}