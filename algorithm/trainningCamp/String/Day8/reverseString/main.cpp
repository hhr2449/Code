#include <iostream>
#include <vector>
using namespace std;
//反转一个字符串
//思路：对撞指针：两端各设定一个指针，交换两个指针指向的元素即可
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        char tmp;
        while(left < right) {
            tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
    }
};
int main() {
    ios::sync_with_stdio(false);
    Solution s;
    vector<char> v{'H', 'E', 'L', 'L', 'O'};
    s.reverseString(v);
    for(char ch : v) {
        cout << ch;
    }
}