//回忆递归的要点
//1.确定参数和返回值，这个往往是串起递归链条的要点（或者说要想明白这个function要实现什么）
//2.确定递归的终止条件
//3.确定递归逻辑，也就是再每一层递归中要做什么，如何调用下一层递归

//以前序遍历为例，函数为preorderTravalsal，这个函数实现的功能是：以前序遍历的方式遍历一棵树
//所以这里的参数就应该是树的根节点root，返回值为void
//思考递归的逻辑，可以发现二叉树可以分解成：根节点 + 左子树 + 右子树，那么遍历左子树和右子树就可以调用递归函数
//也就是函数中应该先输出根节点，然后递归调用遍历左右子树
//终止条件：当根节点为空的时候，说明遍历结束，返回

#include <iostream>
#include <vector>
using namespace std;
//定义节点结构体
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    //递归函数，能够接受一个根节点root，返回一个vector<int>，储存的是前序遍历的结果
    //可以先将根节点放入结构中，然后递归调用左右子树，并且将返回值合并后返回
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        //递归边界
        if(root == nullptr) {
            return res;
        }
        //放入根节点
        res.push_back(root->val);
        //递归调用，返回左子树的遍历结果
        vector<int> leftRes = preorderTraversal(root->left);
        vector<int> rightRes = preorderTraversal(root->right);
        //使用insert进行合并
        res.insert(res.end(), leftRes.begin(), leftRes.end());
        res.insert(res.end(), rightRes.begin(), rightRes.end());
        return res;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    Solution s;
    vector<int> res = s.preorderTraversal(root);
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}

