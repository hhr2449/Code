#include <iostream>
#include <vector>
using namespace std;
//删除数组中的一个元素的方法：
//将哪个元素之后的所有元素全部前移一个单位（一个for循环）
//因此想要实现移除数组中的所有元素只需要一个for循环遍历指定元素，再来一个for循环来删除指定元素即可
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        for(int i = 0; i < size; i++) {
            if(nums[i] == val) {
                removeOneElement(nums, i);
                //注意此时数组的元素全部前移一个单位，所以应该将遍历的指针也前移
                --i;
                --size;
            }
        }
        return size;
    }

    void removeOneElement(vector<int>& nums, int pos) {
        int size = nums.size();
        for(int i = pos; i < size - 1; i++) {
            nums[i] = nums[i + 1];
        }
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