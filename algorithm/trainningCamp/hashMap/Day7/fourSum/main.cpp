class Solution {
public: 
    

    vector<vector<int>> twoSum(vector<int>& nums, int head, long long target) {
        int left = head, right = nums.size() - 1;
        vector<vector<int>> res;
        
        //移动指针，直到相撞
        while(right > left) {
            int sum = (long long)nums[left] + nums[right];
            //如果大于，就让右指针移动
            if(sum > target) {
                right--;
            }
            //如果小于，让左值针移动
            else if(sum < target) {
                left++;
            }
            //如果等于，放入res
            //注意去重，对于连续相同的数，只取第一个
            else {
                vector<int> v{nums[left], nums[right]};
                res.push_back(v);
                left++;
                right--;
                while(right > left && nums[left] == nums[left-1]) {
                    left++;
                }
                while(right > left && nums[right] == nums[right+1]) {
                    right--;
                }
            }
        }
        
        return res;
    }

    //对于四元组，只需要两层for循环用于选取前面两个数即可
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        //不到四个元素，直接返回空
        if(nums.size() < 4) {
            return res;
        }
        //!1.去重：两个for循环中分别去重即可，也就是如果nums[i]==nums[i-1]就将其去掉，j也一样，都是只取遇到的第一个
        //!2.剪枝：注意这里target不一定是0，不能仅凭nums[i]>target就剪枝，还要加上条件nums[i]>=0
        //选取第一个数
        for(int i = 0; i < nums.size() - 3; i++) {
            //剪枝
            if(nums[i] > target && nums[i] >= 0) {
                break;
            }
            //去重
            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            //选取第二个数
            for(int j = i + 1; j < nums.size() - 2; j++) {
                if((long long)nums[i] + nums[j] > target && (long long)nums[i] + nums[j] >= 0) {
                    break;
                }
                if(j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                vector<vector<int>> v = twoSum(nums, j + 1, (long long)target - nums[i] - nums[j]);
                for(int k = 0; k < v.size(); k++) {
                    v[k].push_back(nums[i]);
                    v[k].push_back(nums[j]);
                    res.push_back(v[k]);
                }
                
            }
        }
        return res;
    }
};