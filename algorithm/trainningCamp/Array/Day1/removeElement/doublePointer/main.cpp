#include <iostream>
#include <vector>
using namespace std;
//思路：快慢指针
//快慢指针一般可以用于将两个for循环简化到一个for循环
//很多数组、链表、字符串的操作都会用到快慢指针
//本题思路：这道题限制了必须在一个数组里面完成操作，不妨先去掉这个限制
//这时候一个最显而易见的思路就是开一个新的数组，然后遍历原来的数组，将满足条件的元素丢尽新的数组里面
//当限制在同一个数组时，可以使用快慢指针，快指针用于遍历原本的数组，获取符合条件的元素
//慢指针相当于新的数组的tail，如果fastPtr获取的元素符合条件，就将其放入慢指针指的位置，并且移动slowPtr（相当于向新的数组放入元素）
//如果不符合，则不改变slowPtr

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int fastPtr = 0, slowPtr = 0;
        //快指针遍历数组
        for(; fastPtr < nums.size(); fastPtr++) {
            //如果满足条件，则放入新数组
            if(nums[fastPtr] != val) {
                //放入慢指针指向位置
                nums[slowPtr] = nums[fastPtr];
                //指针右移
                slowPtr++;
            }
        }
        return slowPtr;
    }
};

int main() {
    Solution* s = new Solution();
    vector v = {3, 2, 2, 3};
    int size = s -> removeElement(v, 3);
    cout << size << endl;
    for(int i = 0; i < size; i++) {
        cout << v[i] << endl;
    }
}