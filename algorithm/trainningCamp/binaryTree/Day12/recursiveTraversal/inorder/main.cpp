
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) {
            return res;
        }
        vector<int> leftRes = inorderTraversal(root->left);
        vector<int> rightRes = inorderTraversal(root->right);
        res.insert(res.end(), leftRes.begin(), leftRes.end());
        res.push_back(root->val);
        res.insert(res.end(), rightRes.begin(), rightRes.end());
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
    vector<int> res = s.inorderTraversal(root);
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}