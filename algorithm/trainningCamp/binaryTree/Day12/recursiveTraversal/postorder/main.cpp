//后序遍历的顺序是左、右、根

#include <iostream>
#include <vector>
using namespace std;

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
    //函数功能：以后续遍历的方式遍历以root为根节点的二叉树，返回节点值的列表
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        //递归终止条件
        if(root == nullptr) {
            return res;
        }
        //遍历左子树
        vector<int> leftRes = postorderTraversal(root->left);
        //遍历右子树
        vector<int> rightRes = postorderTraversal(root->right);
        res.insert(res.end(), leftRes.begin(), leftRes.end());
        res.insert(res.end(), rightRes.begin(), rightRes.end());
        //遍历根节点
        res.push_back(root->val);
        return res;
    }
};

TreeNode* createBinaryTree() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(8);
    return root;
}

int main() {
    TreeNode* root = createBinaryTree();
    Solution s;
    vector<int> res = s.postorderTraversal(root);
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}