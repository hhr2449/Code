#include <iostream>
#include <vector>
using namespace std;

//1. 左闭右开
//初始时区间应该是[0, nums.size())，也就是left = 0, right = nums.size()
//循环时应该使用left < right，因为相等时区间没有意义
//注意middle的选取
class Solution {
public:
    int search(vector<int>& nums, int target) {
       int left = 0, right = nums.size(), middle = 0;
       while(left < right) {
        middle = left + ((right - left) >> 1);
        //如果更大，说明一定在左半边，也就是区间[left, middle) (middle可以确定不是)
        if(nums[middle] > target) {
            right = middle;
        }
        //[middle + 1, right)
        else if(nums[middle] < target) {
            left = middle + 1;
        }
        else {
            return middle;
        }
       }
       return -1;
        
    }
};


int main() {
    Solution s;
    vector<int> nums = {-8, -4, -1, 0, 3, 4, 6};
    int target = 0;
    cout << s.search(nums, target) << endl;
    return 0;
}

//二分查找是针对于有序且元素不重复的数组中进行查找的方法
//因为数组有序，因此只要查找中间的元素，如果中间的元素比目标元素小，则目标元素在数组的左侧，否则在右侧（以升序为例）
//关键在于区间的选取，必须要实现不重不漏，因此对于不同区间有不同的写法