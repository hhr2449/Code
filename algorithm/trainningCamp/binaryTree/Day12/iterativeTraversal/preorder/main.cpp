//使用递归来完成的操作往往使用栈迭代也可以实现
//前序遍历的顺序是中、左、右
//可以建立一个栈，将根节点入栈，循环栈非空，在每一次循环中，访问栈顶节点并且弹出，将栈顶节点的右节点、左节点分别入栈
//注意空节点不入栈

//!可以这样认为：从栈中取出一个节点，相当于开始执行以这个节点为根节点的树的前序遍历，对应递归中进入该函数的调用
//比如说，栈中初始只有root节点，此时root出栈相当于开始执行以root为根节点的树的遍历
//处理完root，其右儿子和左儿子分别入栈，然后左儿子出栈，相当于开始执行左子树的遍历
//经过一系列调用，最后完成了左子树的遍历，最后栈中只剩下root->right节点，其出栈，执行右子树的遍历，完成后就是根->左->右的前序遍历

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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> res;
        if(root == nullptr) {
            return res;
        }
        s.push(root);
        // while(!s.empty()) {
        //     //获取栈顶节点
        //     TreeNode* cur = s.top();
        //     //弹出栈顶节点
        //     s.pop();
        //     //访问栈顶节点
        //     res.push_back(cur->val);
        //     //将右儿子放入栈中
        //     if(cur->right != nullptr) {
        //         s.push(cur->right);
        //     }
        //     //将左儿子放入栈中
        //     if(cur->left != nullptr) {
        //         s.push(cur->left);
        //     }
        // }
        //!使用栈迭代和递归其实是可以进行一一对应的
        while(!s.empty()) {
            //获取栈顶节点
            TreeNode* cur = s.top();
            //弹出栈顶节点
            s.pop();
            //!对应递归边界，递归中遇到边界会返回空的res，这里直接continue
            if(cur == nullptr) {
                continue;
            }
            //!递归写法中也右访问当前的节点
            //访问栈顶节点
            res.push_back(cur->val);
            //!对应递归中递归调用左、右儿子
            //将右儿子放入栈中
            s.push(cur->right);
            //将左儿子放入栈中
            s.push(cur->left);
            
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
    vector<int> res = s.preorderTraversal(root);
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}