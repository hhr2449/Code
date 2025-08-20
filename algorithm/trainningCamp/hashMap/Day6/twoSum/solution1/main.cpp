#include <iostream>
#include <vector>
using namespace std;
//给定一个数组和目标值targer，要求从中找出两个数使其和为target，返回这两个数的下标
//暴力解法：使用两层for循环，遍历所有可能的组合
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int sum;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                sum = nums[i];
                sum += nums[j];
                if(sum == target) {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        return res;
    }
};
int main() {
    Solution s;
    vector<int> v{3,2,4};
    vector<int> res = s.twoSum(v, 6);
    for(int i = 0; i < 2; i++) {
        cout << res[i] << ' ';
    }
}