//中序遍历的顺序是左、中、右
//根节点的访问在中间，所以不能访问的同时进行处理
//1. 压栈：递归写法中会先递归调用左儿子的函数，这里对应的就是不断将左儿子进行压栈，边界就是左儿子为空的时候
//2. 出栈：弹出栈顶节点，此时该该节点的左子树已经处理完了，此时可以访问该节点
//3. 将cur指向右儿子，相当于开始处理右子树

#include <iostream>
#include <vector>
#include <stack>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* cur = root;
        stack<TreeNode*> st;
        //这里循环条件有两个，第一个当前节点不为空是专门为了处理第一次进入循环使用的
        while(cur != nullptr || !st.empty()) {
            //不断将左儿子入栈，相当于递归调用处理左子树，直到边界（左儿子为空）
            while(cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            }
            //处理根节点 
            cur = st.top();
            st.pop();
            res.push_back(cur->val);
            //相当于递归处理右儿子
            cur = cur->right;
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
    vector<int> res = s.inorderTraversal(root);
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}