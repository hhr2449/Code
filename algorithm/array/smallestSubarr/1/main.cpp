#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//注意子数组是数组中连续的一串元素
//暴力搜索：遍历所有子数组，以首尾位置为变量，两个for循环
//时间复杂度为O(n^2)
class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int res = 10000000000;
            int sum = 0;
            for(int i=0;i<nums.size();i++){
                sum = 0;
                for(int j=i;j<nums.size();j++){
                    sum += nums[j];
                    if(sum >= target){
                        res = min(res,j-i+1);
                        break;
                    }
                }
            }
            if(res == 10000000000){
                return 0;
            }
            return res;
        }
    };
int main(){
    vector<int> nums = {12,28,83,4,25,26,25,2,25,25,25,12};
    Solution s;
    cout<<s.minSubArrayLen(213,nums);
}