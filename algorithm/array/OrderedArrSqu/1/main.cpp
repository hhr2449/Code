#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//暴力破解：平方之后再排序
//时间复杂度为O(nlogn)
class Solution {
    public:
        vector<int> sortedSquares(vector<int>& nums) {
           for(int i=0;i<nums.size();i++){
                nums[i] = nums[i]*nums[i];
           }
           sort(nums.begin(),nums.end());
              return nums; 
        }
    };
int main(){

}