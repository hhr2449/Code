#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
//计算两个数组的交集
//考虑使用unordered_map，先遍历一个数组，将（元素，1）这个键值对放入map中
//然后遍历另外一个数组，如果里面的值已经位于map中，则放入一个set,最后再
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> note;
        unordered_set<int> res_set;
        for(int i = 0; i < nums1.size(); i++) {
            note[nums1[i]] = 1;
        }
        for(int i = 0; i < nums2.size(); i++ ) {
            if(note[nums2[i]] == 1) {
                res_set.insert(nums2[i]);
            }
        }
        vector<int> res(res_set.begin(), res_set.end());
        return res;
        
    }
};
int main() {
    vector<int> nums1{2,3,5,9};
    vector<int> nums2{1,2,2,3,4};
    Solution s;
    vector<int> res = s.intersection(nums1, nums2);
    for(int v : res) {
        cout << v << ' ';
    }
}