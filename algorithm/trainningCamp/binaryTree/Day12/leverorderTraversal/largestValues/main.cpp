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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            int maxVal = INT_MIN;
            for(int i = 0; i < size; i++) {
                TreeNode* cur = q.front();
                q.pop();
                maxVal = max(maxVal, cur->val);
                if(cur->left != nullptr) {
                    q.push(cur->left);
                }
                if(cur->right != nullptr) {
                    q.push(cur->right);
                }
            }
            res.push_back(maxVal);
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
    vector<int> res = s.largestValues(root);
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << ' ';
        cout << endl;
    }
    return 0; 
}