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
//层序遍历再求平均值即可
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> res;
        double sum = 0;
        if(root == nullptr) {
            return res;
        }
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode* cur = q.front();
                q.pop();
                sum += cur->val;
                if(cur->left != nullptr) {
                    q.push(cur->left);
                }
                if(cur->right != nullptr) {
                    q.push(cur->right);
                }
                if(i == size - 1) {
                    res.push_back(sum / size);
                    sum = 0;
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
    vector<double> res = s.averageOfLevels(root);
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << ' ';
        cout << endl;
    }
    return 0; 
}