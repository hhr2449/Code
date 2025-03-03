#include<stdio.h>
#include<vector>
using namespace std;
//前缀和：当计算区间和时，当数据量较大，如果每次都计算一次，会出现大量的重复计算（区间重叠），浪费时间
//此时可以使用前缀和，前缀和时前n个数的和，可以在O(1)的时间内计算出区间和
int main() {
    int temp1,temp2, sum = 0;
    scanf("%d", &temp1);//用scanf和printf代替cin和cout，可以减少时间
    vector<int> prefixSum(temp1, 0);
    for (int i = 0; i < temp1; i++) {
        scanf("%d", &temp2);
        sum += temp2;
        prefixSum[i] = sum;
    }//计算前缀和
    int left, right;
    //计算区间和时直接前缀和相减
    while (~scanf("%d%d", &left, &right)) {//~代表二进制补码取反，当读取文件读取到EOF时，scanf会返回-1，~(-1) = 0，可以用于循环条件中判断是否读取结束文件
        if (left == 0) {
            printf("%d\n", prefixSum[right]);
        }
        else {
            printf("%d\n", prefixSum[right] - prefixSum[left - 1]);
        }
    }
}