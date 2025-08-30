//进行中、右、左的遍历，再进行反转即可
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* cur = root;
        stack<TreeNode*> st;
        if(cur == nullptr) {
            return res;
        }
        st.push(cur);
        while(!st.empty()) {
            cur = st.top();
            st.pop();
            if(cur == nullptr) {
                continue;
            }
            res.push_back(cur->val);
            st.push(cur->left);
            st.push(cur->right);
        }
        reverse(res.begin(), res.end());
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