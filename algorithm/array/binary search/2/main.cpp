#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        int search(vector<int>& nums, int target) {
            //关键点：明确target一定在的区间
            //这里设定一定在[left,right)区间，因此初始的left设为0，right设为最后一个元素的下标加1
            int left=0,right=nums.size(),middle;
            while(left<right){//因为left=right时，区间没有元素
                middle = left + ((right-left) >> 1);//注意这种写法，一是防止溢出，二是使用移位效率更高
                if(nums[middle]>target){
                    right = middle;//注意是后开的
                }
                else if(nums[middle]<target){
                    left = middle + 1;
                }
                else{
                    return middle;
                }
            }
            return -1;
        }
    };
int main(){
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    Solution s;
    cout << s.search(nums,target) << '\n';
    return 0;
}