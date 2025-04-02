#include<cstdio>
#include<vector>
#include<climits>
using namespace std;
int n;
int flag = 0;
vector<int> a;
vector<int> k;
vector<int> isPerma;
vector<int> dis;
int read(){
    int x = 0,w = 1;
    char ch = 0;
    while(ch<'0'||ch>'9'){
        if(ch == '-'){
            w = -1;
        }
        ch = getchar();
    }
    while(ch>='0'&&ch<='9'){
        x = x*10+ch-'0';
        ch = getchar();
    }
    return x*w;
}
int main(){
    n = read();
    a.resize(n+1);
    k.resize(n+1);
    isPerma.resize(n+1,0);
    dis.resize(n+1,INT_MAX);
    dis[1] = 0;
    for(int i=1;i<=n;i++){
        a[i] = read();
    }
    for(int i=1;i<=n;i++){
        k[i] = read();
    }
}