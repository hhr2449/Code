//滑动窗口法：用于寻找满足特定条件的连续区间
//1. 左右两个指针，区间[left,right]就是窗口
//2. 右指针不断右移，直到满足条件
//3. 左值针右移直到不满足条件
//重复第2，3步即可
//复杂度O(n)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
          int res = INT_MAX;
          int left = 0;
          int sum = 0;
          //一直到右指针达到数组末尾结束
          for(int right = 0;right<nums.size();right++){
            //右指针右移，直到满足条件
            sum += nums[right];
            //左值针右移，直到不满足条件
            while(sum>=target){
                res = min(res,right-left+1);
                sum -= nums[left++];
            }
          }
         return res == INT_MAX ? 0 : res;
        }
    };
int main(){
    vector<int> nums = {12,28,83,4,25,26,25,2,25,25,25,12};
    Solution s;
    cout<<s.minSubArrayLen(213,nums);
}