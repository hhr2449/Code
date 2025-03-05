#include<iostream>
#include<vector>
#include<string>
using namespace std;
//vector的成员函数：v.resize(),v.pop_back(),v.push_back(),v.size()
//注意高精度储存的顺序是反过来的，左放低位，右放高位
//思想：每一位都只取其应该取得，也就是t（或者t补足以后的）的个位数，剩下的多的或者少的都同一加（减）到后面去处理
vector<int> add(const vector<int> &a,const vector<int> &b){
    vector<int> c;//用于储存结果
    int t = 0;//计算中介
    for(int i = 0;i<a.size()||i<b.size();i++){//要将较长的遍历完
        if(i<a.size()){
            t += a[i];
        }
        if(i<b.size()){
            t += b[i];
        }//对应位相加
        c.push_back(t%10);//结果的个位数(t%10)储存在c的对应位中
        t/=10;//结果的10位作为进位继承到下一位
    }
    if(t){//如果最高位有进位就再加上一个1
        c.push_back(1);
    }
    return c;
}
bool cmp(const vector<int> &a,const vector<int> &b){//比较两个数的大小（减法必须是大减小）
    if(a.size()!=b.size()){
        return a.size()>b.size();
    }
    else{
        for(int i = a.size()-1;i>=0;i--){
            if(a[i]!=b[i]){
                return a[i]>b[i];
            }
        }
        return false;
    }
}
vector<int> sub(const vector<int> &a,const vector<int> &b){
    vector<int> c;
    int t = 0;
    for(int i = 0;i<a.size();i++){
        t = a[i] - t;
        if(i<b.size()){
            t -= b[i];
        }
        c.push_back((t+10)%10);//模拟借位操作，如果t>=0，则结果不变，如果t<0，结果就是加上10
        if(t<0){//考虑下一位是否要因为借位减去1
            t = 1;
        }
        else{
            t = 0;
        }
    }
    while(c.size()>1&&c.back() == 0){//最后要去掉前面的0，直到前面没有0或者只剩下一个0
        c.pop_back();
    }
    return c;
}
vector<int> multi(const vector<int> &a,int n){
    vector<int> c;
    int t = 0;
    for(int i = 0;i<a.size()||t;i++){//注意乘法的进位可能有很多位，所以要一直处理完t
        if(i<a.size()){
            t += a[i]*n;
        }//n与a的每一位相乘
        c.push_back(t%10);//只取这一位应该取得（即t的个位）
        t /= 10;//剩下的除10进位扔到后面处理
    }
    return c;
}
void test01(){
    string temp1,temp2;//输入可以使用string作为媒介，再转成vector
    vector<int> a,b,c;
    cin >> temp1 >> temp2;
    for(int i = temp1.size()-1;i>=0;i--){
        a.push_back(temp1[i]-'0');//注意减掉'0'
    }
    for(int i = temp2.size()-1;i>=0;i--){
        b.push_back(temp2[i]-'0');
    }
    c = add(a,b);
    for(int i = c.size()-1;i>=0;i--){
        cout << c[i];
    }
    cout << '\n';
    vector<int> c2;
    if(cmp(a,b)){
        c2 = sub(a,b);
    }
    else{
        c2 = sub(b,a);
    }
    for(int i = c2.size()-1;i>=0;i--){
        cout << c2[i];
    }
    cout << '\n';
    int n = 100;
    vector<int> c3 = multi(a,n);
    for(int i = c3.size()-1;i>=0;i--){
        cout << c3[i];
    }
}
int main(){
    test01();
}