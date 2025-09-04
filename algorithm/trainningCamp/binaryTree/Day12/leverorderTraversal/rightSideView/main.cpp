// 给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
//思路：其实问题的本质就是返回二叉树每一层中的最右边的元素
//使用之前的层序遍历即可
#include <iostream>
#include <vector>
#include <queue>
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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> res;
        if(root == nullptr) {
            return res;
        }
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            //遍历某一层
            for(int i = 0; i < size; i++) {
                TreeNode* cur = q.front();
                q.pop();
                if(cur->left != nullptr) {
                    q.push(cur->left);
                }
                if(cur->right != nullptr) {
                    q.push(cur->right);
                }
                //将该层最右边的节点加入结果中
                if(i == size - 1) {
                    res.push_back(cur->val);
                }
            }
        }
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
    vector<int> res = s.rightSideView(root);
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << ' ';
        cout << endl;
    }
    return 0; 
}