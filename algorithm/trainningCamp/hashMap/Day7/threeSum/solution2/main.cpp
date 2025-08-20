#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
/*
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，
同时还满足 nums[i] + nums[j] + nums[k] == 0 。
请你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。三元组的顺序并不重要
*/


//!参照这里的解决思路，实际上for循环遍历第一个元素，三元组问题可以转化为二元组问题，以此类推，for循环遍历第一个元素
//!n元组问题可以转化为n-1元素问题，所以理论上只要解决了二元组问题就可以解决n元组问题
//!所以我们只需要思考如何更高效的解决二元组问题

class Solution {
public: 
    //使用双指针法来寻找二元组
    //这种涉及选取两个元素的问题可以考虑使用双指针遍历+剪枝
    //!使用两个指针，left初始位于head,right初始位于nums.size()-1，
    //!如果nums[left]+nums[right] > target，则对于当前的right的位置而言，left及其往右的所有情况都不可能成立
    //!也就是当前的right位置下的所有情况已经遍历完成，可以将right左移，直到小于等于
    //!小于的情况类似

    //!对撞指针一般用于需要选取两个元素的情况
    //!一般要求指针的移动具有单调性，这样就可以根据当前的结果来决定移动哪个指针
    //!比如说这里，左值针移动一定会导致和变大，右指针移动一定会导致和变小，
    //!那么如果当前的和大于目标，则左值针移动不可能得到结果，所以只能移动右指针，小于也类似

    //类似题目：接雨水：双指针分别作为左右两边，则指向较长的边的指针移动一定会导致面积变小
    //所以每次应该只移动较短边

    vector<vector<int>> twoSum(vector<int>& nums, int head, int target) {
        int left = head, right = nums.size() - 1;
        vector<vector<int>> res;
        //移动指针，直到相撞
        while(right > left) {
            int sum = nums[left] + nums[right];
            //如果大于，就让右指针移动
            if(sum > target) {
                right--;
            }
            //如果小于，让左值针移动
            else if(sum < target) {
                left++;
            }
            //如果等于，放入res
            //注意去重，对于连续相同的数，只取第一个
            else {
                vector<int> v{nums[left], nums[right]};
                res.push_back(v);
                left++;
                right--;
                while(right > left && nums[left] == nums[left-1]) {
                    left++;
                }
                while(right > left && nums[right] == nums[right+1]) {
                    right--;
                }
            }
        }
        
        
        return res;
    }
    //twoSum函数可以实现查找nums中[head, nums.size())范围内的，和为target的所有不重复二元组（nums单增）
    //对于三元组，只需要进行排序，然后遍历，对于重复的数只选取一个最靠前的即可
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int nowNum = INT_MAX;
        //不到三个元素，直接返回空
        if(nums.size() < 3) {
            return res;
        }
        //选取第一个数
        for(int i = 0; i < nums.size() - 2; i++) {
            //如果第一个数就大于0，直接可以判断不可能
            if(nums[i] > 0) {
                return res;
            }
            if(nowNum != nums[i]) {
                nowNum = nums[i];
            }
            else {
                continue;
            }
            vector<vector<int>> v = twoSum(nums, i + 1, -nowNum);
            for(int i = 0; i < v.size(); i++) {
                v[i].push_back(nowNum);
                res.push_back(v[i]);
            }
        }
        return res;
    }
};
// 辅助函数：打印二维向量
void printResult(const vector<vector<int>>& result) {
    cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < result[i].size(); ++j) {
            cout << result[i][j];
            if (j < result[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

// 测试函数
void testCase(vector<int> nums, const string& testName) {
    Solution sol;
    cout << "测试用例: " << testName << endl;
    cout << "输入数组: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    
    vector<vector<int>> result = sol.threeSum(nums);
    cout << "输出结果: ";
    printResult(result);
    cout << "-------------------------" << endl;
}

int main() {
    // 测试用例1: 基础案例
    testCase({-1, 0, 1, 2, -1, -4}, "基础案例");
    
    // 测试用例2: 空数组
    testCase({}, "空数组");
    
    // 测试用例3: 元素不足3个
    testCase({1, 2}, "元素不足3个");
    
    // 测试用例4: 全为0的数组
    testCase({0, 0, 0, 0}, "全为0的数组");
    
    // 测试用例5: 含重复元素的数组
    testCase({-2, 0, 0, 2, 2}, "含重复元素的数组");
    
    // 测试用例6: 无符合条件的三元组
    testCase({1, 2, 3, 4, 5}, "无符合条件的三元组");
    
    // 测试用例7: 包含负数、零和正数
    testCase({-3, -2, -1, 0, 1, 2, 3}, "包含负数、零和正数");
    
    // 测试用例8: 大量重复元素
    testCase({-1, -1, -1, 0, 0, 0, 1, 1, 1}, "大量重复元素");
    
    return 0;
}