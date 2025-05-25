//并查集可以对数据进行分组，并且实现不同组和合并（merging）和查询某个元素组别(finding)
//思路：并查集是一种树状结构，同一组元素构成一颗树，用树根节点来代表一个组
//merging:合并两个组，只需要将一个组的根节点指向另一个组的根节点即可
//finding:查询某个元素所在的组别，只需要找到这个元素所在的树根节点即可
#include <iostream>
using namespace std;

const int maxN = 20005;

int fa[maxN];//fa[i]代表节点i的父节点

void init(int n) {//n是节点数，这里是初始化各个节点的父节点，最开始时没有分组，可以看作每个节点都自成一组，父节点就是其本身
    for (int i = 0; i < n; i++) {
        fa[i] = i;
    }
    return;
}

int find1(int x) {//查询节点x所在的组别（搜索x所在的树的根节点）
    while (x != fa[x]) {
        x = fa[x];//区分根节点和非根节点的依据：根节点的父节点就是自己，所以这里从节点x开始向父节点方向走，直到走到根节点
    }
    return x;
}

int find2(int x) {//递归实现
    if(x == fa[x]) {
        return x;
    }
    return find2(fa[x]);
}

void merge(int x, int y) {
    int a = find1(x);
    int b = find1(y);//先找每一组的根节点
    if(a != b) {//如果根节点不同，则合并
        fa[a] = b;
    }
    return;
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
            if(find1(x) == find1(y)) {
                cout << "Y" << endl;
            }
            else {
                cout << "N" << endl;
            }
        }
    }

}