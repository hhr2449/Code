#include <iostream>
using namespace std;
int main() {
    void* ptr;
    float x = 1.0;
    ptr = &x;
    cout << *((float*)ptr);
}