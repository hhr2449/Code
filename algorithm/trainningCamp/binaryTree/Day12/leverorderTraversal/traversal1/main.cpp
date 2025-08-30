//使用广度优先搜索即可实现二叉树的层序遍历
//维护一个队列，初始将根节点入队，每次弹出一个节点进行处理，同时将其儿子节点入队
//如果想要分层进行处理，可以在while循环里面加入一个for循环进行技术，在每次循环的开头就统计当前层级的节点数
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        if(root == nullptr) {
            return res; 
        }
        q.push(root);
        while(!q.empty()) {
            //当前层级中的节点个数
            int size = q.size();
            vector<int> level;
            //处理当前层级中的节点
            for(int i = 0; i < size; i++)  {
                //处理队首节点
                TreeNode* cur = q.front();
                q.pop();
                level.push_back(cur->val);
                //将队首节点的儿子节点入队
                if(cur->left != nullptr) {
                    q.push(cur->left);
                }
                if(cur->right != nullptr) {
                    q.push(cur->right);
                }
            }
            res.push_back(level);
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
    vector<vector<int>> res = s.levelOrder(root);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0; 
}