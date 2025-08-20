//充分利用数组的结构
//数组原本是增的，那么平方过后一定是两边大，中间小的
//这样就可以使用对撞指针，从两边分别进行遍历
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
        //两根指针分别从两边进行遍历，谁大就将谁放入，直到两根指针撞到一起
        int left = 0, right = size - 1;
        vector<int> v = vector<int>(size);
        int tail = size - 1;
        while(left < right) {
            if(nums[left] <= nums[right]) {
                v[tail] = nums[right];
                right--;
            }
            else {
                v[tail] = nums[left];
                left++;
            }
            tail--;
        }
        return v;
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