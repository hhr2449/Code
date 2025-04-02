#include <iostream>
#include <string>
using namespace std;
int main(){
    int n , k;
    cin >> n >> k;
    string order;
    int x,y;
    for(int i=0;i<k;i++){
        cin >> x >> y;
        cin >> order;
        for (int j=0;j<order.length();j++){
            if(order[j]=='f'){
                if(y<n){
                    y+=1;
                }
            }
            else if(order[j]=='b'){
                if(y>1){
                    y-=1;
                }
            }
            else if(order[j]=='l'){
                if(x>1){
                    x-=1;
                }
            }
            else if(order[j]=='r'){
                if(x<n){
                    x+=1;
                }
            }
        }
        cout << x << ' ' << y << '\n';
    }
    return 0;
} 