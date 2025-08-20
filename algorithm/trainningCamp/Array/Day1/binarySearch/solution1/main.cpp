#include <iostream>
#include <vector>
using namespace std;

//1. 左闭右闭
//初始时区间应该是[0, nums.size() - 1]，也就是left = 0, right = nums.size() - 1
//循环时应该使用left <= right，因为相等时区间有意义
//注意middle的选取
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, middle = 0;
        //如果中间的元素更大，那么就说明目标在左半区间，那么改变right，然后再来一次循环，更小的情况同理
        //如果是目标元素，就直接返回
        //如果一直left > right还没有找到，则说明不存在（因为在二分查找中left和right会逐渐接近，极端情况是当left == right时
        //如果此时仍然不是，要么right-1，要么left+1，一定会出现left > right，所以可以以此作为边界）
        while(left <= right) {
            middle = left + ((right - left) >> 1);
            if(nums[middle] > target) {
                right = middle - 1;
            }
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