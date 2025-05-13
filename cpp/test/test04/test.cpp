#include <iostream>
#include <vector>
using namespace std;
void print(vector<int> vec) {
    for(auto i = vec.begin(); i != vec.end(); ++i) {
        cout << *i << ' ';
    }
    cout << '\n';
}
int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    cout << vec.size() << '\n';
    print(vec);
}