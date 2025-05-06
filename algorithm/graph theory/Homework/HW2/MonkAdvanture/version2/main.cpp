#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
const int MAXN = 20;
const int INF = 1000000;
using namespace std;

int costH[MAXN][MAXN];
int costF[MAXN][MAXN];
int n, m;
int flag = 0;
struct Road {
    int node[MAXN];
    int k;
    int e;
    int sumH;
    int sumF;
    int lb;
    int visited_mask; // 位掩码代替visited数组
    bool operator < (const Road& other) const {
        return other.lb < lb;
    }               
};
int up = INF;
priority_queue<Road> pq;
Road minRoad;

// 修改后的getLb函数
int getLb(const Road& r, const int* minInH, const int* minOutH) {
    int res = 2*r.sumH;
    int min1 = INF, max1 = 0;
    
    // 当前终点的最小出边
    for(int i = 1; i <= n; i++) {
        if(i != r.e && !(r.visited_mask & (1 << (i-1)))) {
            min1 = min(min1, costH[r.e][i]);
        }
    }
    res += min1;
    
    // 累加所有未访问节点的in/out最小值
    for(int i = 1; i <= n; i++) {
        if(!(r.visited_mask & (1 << (i-1)))) {
            int currMinIn = minInH[i];
            int currMinOut = minOutH[i];
            max1 = max(max(currMinIn, currMinOut), max1);
            res += currMinIn + currMinOut;
        }
    }
    res -= max1;
    return (res + 1)/2;
}

int solution() {
    // 预处理最小入边/出边
    int minInH[MAXN], minOutH[MAXN];
    memset(minInH, 0x3f, sizeof(minInH));
    memset(minOutH, 0x3f, sizeof(minOutH));
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(i != j) {
                minOutH[i] = min(minOutH[i], costH[i][j]);
                minInH[j] = min(minInH[j], costH[i][j]);
            }
        }
    }
    
    for(int s = 1; s <= n; s++){
        while (!pq.empty()) pq.pop(); 
        Road r;
        r.e = s;
        r.sumH = 0;
        r.sumF = 0;
        r.k = 1;
        r.visited_mask = 1 << (s-1);
        r.node[1] = s;
        r.lb = getLb(r, minInH, minOutH);
        pq.push(r);
        
        while (!pq.empty()) {
            Road tem = pq.top();
            pq.pop();
            if(tem.k == n-1) {
                int p;
                for(int i = 1; i <= n; i++){
                    if(!(tem.visited_mask & (1 << (i-1)))) {
                        p = i;
                        break;
                    }
                }
                if(costH[tem.e][p] + tem.sumH < up && costF[tem.e][p] + tem.sumF <= m) {
                    up = costH[tem.e][p] + tem.sumH;
                    tem.node[tem.k + 1] = p;
                    minRoad = tem;
                    flag = 1;
                }
                continue;
            }
            Road next;
            for(int i = 1; i <= n; i++) {
                if(!(tem.visited_mask & (1 << (i-1)))) {
                    next = tem;
                    next.e = i;
                    next.k++;
                    next.sumH += costH[tem.e][i];
                    next.sumF += costF[tem.e][i];
                    next.visited_mask |= 1 << (i-1);
                    next.lb = getLb(next, minInH, minOutH);
                    next.node[next.k] = i;
                    // 修正剪枝条件
                    if(next.lb < up && next.sumF <= m) {
                        pq.push(next);
                    }
                }
            }
        }
    }
    return up;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> costH[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> costF[i][j];
        }
    }
    int ans = solution();
    if(flag == 0) {
        cout << -1;
        return 0;
    }
    cout << ans << '\n';
    for(int i = 1; i <= n; i++) {
       
        cout << minRoad.node[i] << ' ';
    }
}