#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int temp = nums[0],slowptr = 1;
            for(int fastptr = 1;fastptr < nums.size();fastptr++){
                if(nums[fastptr]!=temp){
                    nums[slowptr++] = nums[fastptr];
                    temp = nums[fastptr];
                }
            }
            return slowptr;
        }
    };

    int main(){
        vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
        Solution s;
        cout << s.removeDuplicates(nums) << '\n';
        return 0;
    }