#include <iostream>
using namespace std;
void increase(int &x) {
    x++;
}
void decrease(int &x) {
    x--;
}
int main() {
    void (*ptr)(int &);
    int flag;
    cin >> flag;
    switch(flag) {
        case 1: ptr = increase;
            break;
        case 2: ptr = decrease;
            break;
    }
    int x = 10;
    ptr(x);
    cout << x << '\n';
}