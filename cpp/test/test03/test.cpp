#include<iostream>
using namespace std;    
#define ll long long
int main()
{
    ll n;
    cin >> n;
    double ans = 0;
    double len = 1.0/n;
    double x = 0;
    for(ll i = 0; i < n; i++) {
        ans += len*x*x*x;
        x += len;
    }
    cout << ans << endl;
}
