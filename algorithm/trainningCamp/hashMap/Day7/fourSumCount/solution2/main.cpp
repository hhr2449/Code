#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
*/

//思路：延续之前的两数相加的思路，在两数相加里面，我们在一遍遍历中确定第一个数，这样第二个数就可以确定为sub=target-numFirst
//这样就可以直接使用map来直接获取第二个数，从而减少搜索成本
//这道题中需要寻找的是一个四元组，那么我们可以考虑将其二分，这样就可以化归为类似之前的两数相加的一遍遍历，直接搜索的思路
//遍历前面两个数组的所有组合，使用map将(sum, cnt)这个键值对进行储存
//然后遍历后面两个数组，对于后面两个数组的和sum,前面两个数组的数的和就应该是-sum，那么就可以直接使用key=-sum进行查找
//时间复杂度将为n^2

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int cnt = 0;
        int sum;
        unordered_map<int,int> note;
        for(int i = 0; i < nums1.size(); i++) {
            for(int j = 0; j < nums2.size(); j++) {
                sum = nums1[i] + nums2[j];
                note[sum]++;
            } 
        }
        for(int i = 0; i < nums3.size(); i++) {
            for(int j = 0; j < nums4.size(); j++) {
                sum = nums3[i] + nums4[j];
                cnt += note[-sum];
            } 
        }
        return cnt;
    }
};

int main() {
    Solution s;
    vector<int> v1{1, 2};
    vector<int> v2{-2, -1};
    vector<int> v3{-1, 2};
    vector<int> v4{0, 2};
    cout << s.fourSumCount(v1, v2, v3, v4);
}