// 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

// 返回 滑动窗口中的最大值 。

//注意理解题目，这里是要求给出滑动窗口的最大数值，不是要求给出滑动窗口的数字之和

//思路：原则：又老又劣的不可能成为最值，那么对于这些又老又劣的元素就可以淘汰掉不用参与比较了
//比如下表为i,j的两个元素，且 i < j，nums[i] < nums[j]，那么当j入队之后，有i就一定会有j，且j对应的值一定比i对应的大
//那么j入队之后，i就永远不可能成为最大的了，也就是j可以将i（包括队中所有对应元素不如j的大的）给淘汰掉

//维护一个单调队列（这个不是真正的队列，因为要进行队尾的删除操作，可以使用数组或是deque进行模拟）
//在这个单调队列中，加入一个新的元素的时候，如果队尾的元素不如新的元素大，那么就一直删除队尾的元素，直到队尾的元素比新的元素大
//这样得到的队列中，从队尾到队首，储存的值一定是单调递增的，并且元素出现的顺序一定是从新到老（因为如果新的更大，就一定会把老的淘汰掉）
//在本题中，为了方便删除已经出窗口的元素，可以储存元素对应的下标值，只要队首的下标值比当前窗口的左边界小，就一直删除队首的元素
//由于队尾到队首下标的递递减性，可以保证队列中的元素一定是窗口中的

//类比一下，这个队列可以比作一个公司，每次进来的新员工可以淘汰掉不如他强的老员工，这样做可以保证员工队伍最优




#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;
        for (int i = 0; i < k; i++) {
            //队尾元素比当前元素小，则队尾元素出队
            while(!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        res.push_back(nums[q.front()]);

        for(int i = k; i < nums.size(); i++) {
            //新加入的元素要淘汰掉不如他的旧元素
            while(!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
            //去除不在窗口内的元素
            while(q.front() < i - k + 1) {
                q.pop_front();
            }
            res.push_back(nums[q.front()]);
        } 
        return res;
    }
};
int main() {
    Solution s;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> res = s.maxSlidingWindow(nums, k);
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}