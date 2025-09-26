#include <queue>
#include <cstdio>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
//使用递归，二叉树的最大深度就是左子树和右子树的最大深度的最大值加上1
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        int depth = 0;
        if(root->left != nullptr) {
            depth = max(depth, maxDepth(root->left));
        }
        if(root->right != nullptr) {
            depth = max(depth, maxDepth(root->right));
        }
        return depth + 1;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution s;
    printf("%d\n", s.maxDepth(root)); 
    return 0;

}