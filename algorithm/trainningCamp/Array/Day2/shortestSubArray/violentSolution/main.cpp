#include <iostream>
#include <vector>
using namespace std;

//暴力解法：以右端点为标准进行遍历，所有以特定位置为右端点的最短情况中的最小的就是答案
//所以应该两个for循环，外层用于遍历右端点，内层用于获取特定右端点情况下的最短子数组
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX, sum = 0;
        //遍历右端点
        for(int i = 0; i < nums.size(); i++) {
            sum = 0;
            //从右端点开始累加
            for(int j = i; j >= 0; j--) {
                sum += nums[j];
                //刚好大于等于target时，就是该右端点情况下的最小值
                if(sum >= target) {
                    res = min(res, i - j + 1);
                    break;
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