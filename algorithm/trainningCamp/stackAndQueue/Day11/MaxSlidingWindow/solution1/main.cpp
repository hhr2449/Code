// 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

// 返回 滑动窗口中的最大值 。

//注意理解题目，这里是要求给出滑动窗口的最大数值，不是要求给出滑动窗口的数字之和
//想要求解最值，可以考虑使用优先队列，维护一个大根堆（大的优先），则队首的元素就是最大值
//但是现在问题是我们的滑动窗口实在不断变化的，也就是当前队首的元素不一定处于窗口中（也就是在窗口的左边界以左）
//想要解决这个问题，可以考虑在每次移动窗口的时候来验证队首元素是否在窗口中，如果不在就将其弹出
//于是想到在队列中储存二元组，包含数值和索引，这样可以通过索引来验证元素是否处于窗口中



#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //大根堆，大的优先，pair的比较会先比较的一个元素，在比较后一个元素
        priority_queue<pair<int, int>> q;
        vector<int> res;
        //初始的窗口
        for(int i = 0; i < k; i++) {
            q.push(make_pair(nums[i], i));
        }
        res.push_back(q.top().first);
        //移动窗口
        for(int i = k; i < nums.size(); i++) {
            //将新加入的元素加入队列
            q.push(make_pair(nums[i], i)); 
            //检验队列的首元素，直到首元素位于窗口中
            while(!q.empty() && q.top().second < i - k + 1) {
                q.pop();
            }
            //队首元素就是当前窗口的最大值
            res.push_back(q.top().first);
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