#include <cstdio>
#include <cstdlib>
using namespace std;
int main() {
    int k;
    scanf("%d", &k);
    int a, b, c;
    for(int i = 0; i < k; i++) {
        scanf("%d %d %d", &a, &b, &c);
        //注意浮点数的表示误差，比如结果为1.45可能会误差为1.449999999，所以这里加上0.001来修正
        double target = (double)(c - a)/b;      
        target += 0.001;
        target *= 100;
        int ans = (int)target;
        int j = ans % 10 + 1;
        int i1 = ans / 10 + 1;
        printf("%d %d\n", i1, j);
    }
}