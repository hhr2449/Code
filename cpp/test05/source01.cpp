#include"header.h"
int main(){
    std::vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    change(v);
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i]+10086 << std::endl;
    }
    return 0;
}