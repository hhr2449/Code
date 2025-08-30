// 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

//思路：统计+排序
//使用map来统计数字出现的频次，在对其进行排序
//!关键在于排序的方法，核心问题就是：给出n个元素，返回其中最大的k个应该如何做
//如果是一个对于n个元素进行全排列的问题，那么快排，大根堆，小根堆都是一样的o(nlogn)
//但是这里只是部分排序，只要前面k个，就可以进行优化：始终只排k个
//维护一个小根堆，堆得大小为k，每次添加元素时都将堆顶的元素pop出去，这样保证堆中的k个是当前最大的k个，这样维持堆的大小为k，则复杂度为o(nlogk)

//这种思路就有点类似于求最大值的思路，求最大值的时候，我们保存变量max，然后每次都进行比较，如果更大就进行更换
//这里则是扩展到k个，手里面留k个元素，每次进行比较，淘汰掉最小的哪一个

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
//小根堆使用的比较函数对象
class MyComparision {
public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //统计频率
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        //小根堆
        priority_queue<pair<int, int>, vector<pair<int, int>>, MyComparision> pq;
        //使用iterator来对map进行遍历
        for(auto it = map.begin(); it != map.end(); it++) {
            pq.push(*it);
            //维持容量为k，如果超出，则将最小的那个淘汰
            if(pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> res;
        while(!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    Solution s;
    vector<int> res = s.topKFrequent(nums, k);
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;

}