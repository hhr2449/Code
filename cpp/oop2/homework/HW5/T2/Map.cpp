#include "Map.h"
    Map::Map(int n) {
        data = new Pair[n+1];
    }
    //搜索键为指定target的pair，如果搜到了返回其下标（从1开始），否则返回0
    int Map::search(string target) {
        int sizePair = num;
        for(int i = 1; i <= sizePair; ++i){
            if(data[i].hasKey(target)) {
                return i;
            }
        }
        return 0;
    }
    
    int Map::search(string target) const {
        int sizePair = num;
        for(int i = 1; i <= sizePair; ++i){
            if(data[i].hasKey(target)) {
                return i;
            }
        }
        return 0;
    }
    int& Map::operator[] (string key_) {//普通对象的[]重载，返回的是引用
        int a = search(key_);
        if(a) {
            return data[a].getVal();
        }
        else {
            data[++num].reset(key_,0);
            return data[num].getVal();
        }
    }
    int Map::operator[] (string key_) const {//常量对象[]重载，返回的是值
        int a = search(key_);
        if(a) {
            return data[a].getVal();
        }
        else {
            return 0;
        }
    }
    int Map::size () {
        return num - 1;
    }
    Map::~Map() {
        if(data != nullptr){
            delete [] data;
        }
    }