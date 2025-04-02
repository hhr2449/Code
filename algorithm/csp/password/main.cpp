#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    int n,flag = 0,num = 0,zifu = 0,zimu = 0;
    string s;
    cin >> n;
    vector<int> v(200,0);
    for(int i=0;i<n;i++){
        cin >> s;
        flag = 0,num = 0,zifu = 0,zimu = 0;
        fill(v.begin(),v.end(),0);
        for(int j = 0;j<s.length();j++){
            if(s[j] == '*'||s[j] == '#'){
                zifu = 1;
            }
            else if(s[j]>='0'&&s[j]<='9'){
                num = 1;
            }
            else{
                zimu = 1;
            }
            v[s[j]]++;
            if(v[s[j]]>2){
                flag = 1;
            }
        }
        if(num == 1&&zimu == 1&&zifu == 1){
            if(flag == 1){
                cout << 1 << '\n';
            }
            else{
                cout << 2 << '\n';
            }
        }
        else{
            cout << 0 << '\n';
        }
    }
    
}