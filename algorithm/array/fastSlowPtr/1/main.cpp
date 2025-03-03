// 时间复杂度：O(n)
// 空间复杂度：O(1)
#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            int slowIndex = 0;
            for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
                if (val != nums[fastIndex]) {
                    nums[slowIndex++] = nums[fastIndex];
                }
            }
            return slowIndex;
        }
    };
int main(){
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    Solution s;
    cout << s.removeElement(nums,val) << '\n';
    return 0;
}