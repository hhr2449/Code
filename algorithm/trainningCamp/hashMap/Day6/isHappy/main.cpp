#include <iostream>
#include <unordered_set>
using namespace std;
//判断一个数是否是欢乐数
/*
「快乐数」 定义为：
对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果这个过程 结果为 1，那么这个数就是快乐数。
*/
//思路：重复执行求平方和的过程，设置一个set用于储存过程中出现数字，如果再次出现某个数字就说明已经陷入了无限循环，返回false
class Solution {
public:
    //用于获取平方和
    int getSum(int n) {
        int res = 0;
        //使用模10除10法进行求和
        while(n >= 1) {
            res += (n%10)*(n%10);
            n /= 10;
        }
        return res;
    }
    bool isHappy(int n) {
        unordered_set<int> note;
        while(1) {
            if(n == 1) {
                return true;
            }
            //使用find()方法，如果存在，则返回对应的迭代器，如果不存在返回note.end()
            if(note.find(n) != note.end()) {
                return false;
            }
            note.insert(n);
            n = getSum(n);
        }
    }
};
int main() {
    Solution s;
    cout << s.isHappy(19);
}