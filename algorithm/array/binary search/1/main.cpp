#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        int search(vector<int>& nums, int target) {
            //关键点：明确target一定在的区间
            //这里设定一定在[left,right]区间，因此初始的left设为0，right设为最后一个元素的下标
            int left=0,right=nums.size()-1,middle;
            while(left<=right){//因为left=right时，区间还有一个元素，所以要包含
                middle = left + ((right-left) >> 1);//注意这种写法，一是防止溢出，二是使用移位效率更高
                if(nums[middle]>target){
                    right = middle - 1;//这时候一定在[left,middle-1]区间
                }
                else if(nums[middle]<target){
                    left = middle + 1;
                }
                else{
                    return middle;
                }
            }
            //当没有找到需要顺序插入时，一定是middle和边界重叠,left右移超过right或是right左移超过left
            //这时候left就是需要插入的位置
            return left;
            // if(nums[middle] > target){
            //     return middle;
            // }
            // else{
            //     return middle + 1;
            // }
        }
    };
int main(){
    vector<int> nums = {1,3,5,6};
    int target = 0;
    Solution s;
    cout << s.search(nums,target) << '\n';
    return 0;
}
//当然，其实也可以直接进行暴力搜索来实现，但是这样的时间复杂度是O(n)