#include <iostream>
using namespace std;

int main()
{
    int x = 0;
    int y[10] = {};
    int z = 0;

    int * a[] = {
        nullptr, nullptr, &x, y, &z
    };
    
    *a[2] = 123;
    a[3][5] = 456;
    if(!a[0]) {
        cout << *a[2] << "," << a[3][5];
    }
    return 0;
}