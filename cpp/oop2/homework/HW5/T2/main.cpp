#include <iostream>
#include "Pair.h"
#include "Map.h"
using namespace std;

void test(){
    int n, k;//最大键值对数和操作数 
    cin >> n >> k;
    Map map(n);//构造函数，初始化一个map对象
    const Map & cmap = map;//常量map对象
    int query;
    string key;
    int val;
    for(int i = 0; i < k; ++i){
        cin >> query;//代表某种操作
        if(query == 1){//获取值
            cin >> key;
            cout << map[key] << endl;
        }
        else if(query == 2){//修改值
            cin >> key >> val;
            map[key] = val;
        }
        else if(query == 3){//常量查询
            cin >> key;
            cout << cmap[key] << endl;
        }
    }
    cout << map.size() << endl;//输出对象个数
}

int main(){
    test();
    return 0;
}