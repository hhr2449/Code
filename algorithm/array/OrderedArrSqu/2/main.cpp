//暴力求解显然不是最佳做法，此时要考虑数组的特点：非递减，这样平方之后要不然是非递减，要不然是先非递增，再非递减
//此时可以考虑使用双指针法，一个指向头，一个指向尾，从两边开始同时进行排序
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size());
        int right = nums.size() - 1,resPtr = nums.size()-1;
        for(int i = 0;i<nums.size();i++){
            nums[i] = nums[i]*nums[i];
        }
        for(int left = 0;left<=right;){
            if(nums[left] > nums[right]){
                res[resPtr--] = nums[left++];
            }
            else{
                res[resPtr--] = nums[right--];
            }
        }
        return res;
    }
};
int main(){

}