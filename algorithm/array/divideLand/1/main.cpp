//做法1：暴力枚举，一个for循环来遍历所有的划分方法，再用两个for循环来求和，时间复杂度为O(n^3)
//做法2：前缀和：分别求行和列的前缀和，则两个地块之差是S[总]-S[i]-S[i]
//做法3：遍历：利用做法2中得到的公式，再输入数据的时候就算出S[总]，然后遍历行和列，在每行（列）的末尾来计算面积差
//后两种做法的时间复杂度都是O(n^2)
//这里采用做法2
#include<stdio.h>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;
int main(){
    int n,m,sum=0,res=INT_MAX,preSum=0;
    scanf("%d%d",&n,&m);
    vector<vector<int>> land(n,vector<int>(m,0));
    vector<int>row(n,0),col(m,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&land[i][j]);
            sum+=land[i][j];
        }
    }//输入数组
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            preSum+=land[i][j];
        }
        row[i]=preSum;
    }//求行的前缀和（row[i]等于前面i行的和）
    preSum=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            preSum+=land[j][i];
        }
        col[i]=preSum;
    }//列的前缀和
    for(int i=0;i<n;i++){
        res = min(res,abs(sum-row[i]-row[i]));
    }
    for(int i=0;i<n;i++){
        res = min(res,abs(sum-col[i]-col[i]));
    }//计算最小差值
    printf("%d",res);
    return 0;
}