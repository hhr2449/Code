#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int now, pre = 0, cur = 1, res = 1;
        if(nums[cur] > nums[pre]) {
            now = 1;
        }
        else {
            return false;
        }
        while(cur < nums.size()) {
            if(nums[pre] == nums[cur]) {
                return false;
            }
            if(now == 1) {
                if(nums[cur] < nums[pre]) {
                    now = -1;
                    res++;
                }
            }
            else {
                if(nums[cur] > nums[pre]) {
                    now = 1;
                    res++;
                }
            }
            cur++;
            pre++;
        }
        if(res == 3) {
            return res;
        }
        else {
            return false;
        }
    }
};

int main() {
    Solution s;
    vector<int> v{6,5,1};
    cout << s.isTrionic(v);
}