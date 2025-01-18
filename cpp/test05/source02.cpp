#include"header.h"
void change(std::vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        v[i] += i%10;
    }
}