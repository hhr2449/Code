#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//注意子数组是数组中连续的一串元素

class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int res = 100000;
            int sum = 0;
            for(int i=0;i<nums.size();i++){
                sum = 0;
                for(int j=i;j<nums.size()&&j-i+1<=res;j++){//剪枝优化，但是仍是O(n^2)
                    sum += nums[j];
                    if(sum >= target){
                        res = min(res,j-i+1);
                        break;
                    }
                }
            }
            if(res == 100000){
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