#include <iostream>
#include <vector>
using namespace std;

//滑动窗口法：
//选取右端点为遍历的变量，此时左端点一定是单调向右的，否则得到的子序列不可能比之前的情况更短
//此时可以使用滑动窗口
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int res = INT_MAX, sum = 0, len = 0, left = 0;
       //遍历右端点
       for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            //右端点右移，直到超过target
            if(sum >= target) {
                //左端点左移，直到小于target，可获取当前右端点下的最小长度
                while(1) {
                    sum -= nums[left++];
                    if(sum < target) {
                        res = min(res, i - left + 2);
                        break;
                    }
                }
                
            }
       }
       return res == INT_MAX ? 0 : res;
    } 
};

int main() {

    Solution s;
    int target = 7;
    vector<int> v = {2,3,1,2,4,3};
    cout << s.minSubArrayLen(7, v);

}