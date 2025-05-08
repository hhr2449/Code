#pragma once
#include "Part.h"
#include <iostream>
using namespace std;
class Robot{
    public:
    int k;
    int cnt;
    long long int ans;
    Robot(int k) {
        this -> k = k;
        this -> cnt = 0;
        this -> ans = 0;
    }
    bool is_full() {
        if(cnt == k){
            return true;
        }
        else{
            return false;
        }
    }
    void add_part(Part p) {
        cnt++;
    }
    int run() {
        return ans;
    }
};