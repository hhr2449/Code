#ifndef LINE
#define LINE
#include<iostream>
using namespace std;    
template<typename T>
class Line {
    public:
    T k , b = 0;
    Line (T k,T b):k(k),b(b){}
    Line (T k):k(k){}
    bool operator<(const Line& other){
        return k<other.k;
    }
    bool intersect(const Line& other){
        if(k == other.k&& b != other.b){
            return false;
        }
        return true;
    }
    void show(){
        cout << k << ',' << b  << '\n';
    }
};
#endif