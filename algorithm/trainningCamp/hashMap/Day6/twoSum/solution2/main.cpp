#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
//给定一个数组和目标值targer，要求从中找出两个数使其和为target，返回这两个数的下标
//思考如何优化刚刚的算法
//刚刚的暴力算法的复杂度为o(n^2)，可以先考虑复杂度的来源
//第一遍遍历提供o(n),此时确定了第一个数，第二个循环提供o(n)，这个循环负责查找可能可以和刚刚的第一个数组合形成target的数
//那么第二个循环实质上就是一个查找，如果使用map就可以优化到o(1)的复杂度
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        //设置一个map，将数组中的元素全部放入，这样只用遍历一次，每次确定需要寻找的sub，使用set进行查找即可
        unordered_map<int, int> note;
        for(int i = 0; i < nums.size(); i++) {
            note[nums[i]] = i;
        }
        int sub;
        for(int i = 0; i < nums.size(); i++) {
            sub = target - nums[i];
            auto it = note.find(sub);
            if(it != note.end() && i != it->second) {
                res.push_back(i);
                res.push_back(it->second);
                return res;
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