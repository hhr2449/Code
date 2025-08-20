#include <iostream>
#include <vector>
using namespace std;
/*
给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
*/

//暴力解法：使用4个for循环，直接遍历所有组合，时间超限

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int cnt = 0;
        int sum;
        for(int i = 0; i < nums1.size(); i++) {
            for(int j = 0; j < nums2.size(); j++) {
                for(int m = 0; m < nums3.size(); m++) {
                    for(int n = 0; n < nums4.size(); n++) {
                        sum = nums1[i] + nums2[j] + nums3[m] + nums4[n];
                        if(sum == 0) {
                            cnt++;
                        }
                    }
                }
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