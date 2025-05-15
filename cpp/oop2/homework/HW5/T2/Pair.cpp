#include "Pair.h"
#include <string>
#include <iostream>
using namespace std;

int Pair::n_create = 0;//总共创建pair对象的个数
int Pair::n_free = 0;

Pair::Pair():val(0){//构造函数，创建pair类型的对象，同时创建次数增加
    ++Pair::n_create;
}

void Pair::reset(string k, int v){//重新设置pair对象的键和值的接口
    key = k;
    val = v;
}

bool Pair::hasKey(string k){//判断k是否与pair对象中的key相等的接口
    return key == k;
}

int & Pair::getVal(){//获取值的接口（获取的是引用）
    return val;
}

Pair::~Pair(){
    --Pair::n_free;
}
//n_free+n_create即为实际剩余的元素的个数