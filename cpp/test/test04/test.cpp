#include<iostream>
using namespace std;
bool isPrime(int n){
    if(n==1){
        return true;
    }
    for(int i = 1;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    cout << isPrime(29);
}