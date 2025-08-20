#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//暴力解法：直接平方，然后使用stl中的排序
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        //进行平方
        for(int i = 0; i < size; i++) {
            nums[i] *= nums[i];
        }
        //排序
        sort(nums.begin(), nums.end());
        return nums;
    }

    
};

int main() {
        Solution* s = new Solution();
        vector<int> v = {-3, -2, -1, 0, 9, 10};
        vector<int> sv = s -> sortedSquares(v);
        for(int i = 0; i < sv.size(); i++) {
            cout << sv[i] << ' ';
        }
    }