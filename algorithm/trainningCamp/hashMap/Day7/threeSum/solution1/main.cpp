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
    //只要能做到寻找所有不重复的二元组即可
    //这里的数组nums是经过排序的
    //思路：考虑第一个元素的下标一定小于第二个元素
    //第一个元素的选取不重复，也就是遍历的时候对于相同的元素只选取第一个
    //这里使用了nowNum来记录，如果遍历的元素和nowNum一样，说明其不是相同元素中的第一个，则跳过去
    //第二个元素的选取：使用一个set来记录当前可选的元素，考虑初始先把所有元素全部放入
    //然后在第一个元素选取过程中动态删除（因为第二个元素的下标大于第一个）（set中只放下标为[i+1, nums.size())的元素）
    vector<vector<int>> twoSum(vector<int>& nums, int head, int target) {
        int nowNum = INT_MAX;
        unordered_set<int> s;
        vector<vector<int>> res;
        //初始化集合
        for(int i = head; i < nums.size(); i++) {
            s.insert(nums[i]);
        }
        for(int i = head; i < nums.size(); i++) {
            //删除元素，考虑第i个元素是否需要删除
            //如果后面还有相同元素，不删除，否则删除（没有相同元素或者是最后一个元素）
            if(i + 1 == nums.size()) {
                s.erase(nums[i]);
            }
            if(i + 1 < nums.size() && nums[i] != nums[i+1]) {
                s.erase(nums[i]);
            }
            if(nowNum != nums[i]) {
                nowNum = nums[i];
            }
            else {
                //如果相同，说明前面已经有过第一个元素是nums[i]的情况了，此时可以跳过
                continue;
            }
            //开始查找第二个元素
            auto it = s.find(target - nums[i]);
            if(it != s.end()) {
                vector v{nums[i], target - nums[i]};
                res.push_back(v);
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