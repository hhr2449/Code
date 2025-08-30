//遍历的难点在于访问顺序和处理顺序的不统一。根节点是最先访问的，所以如果根节点不是最先进行处理，则会造成顺序不统一
//在原本的迭代方法中，将元素放入栈中不仅仅是处理该元素本身，而是处理该元素为根节点的子树，所以没有办法将根节点入栈来留到后面处理
//这时候我们可以想到对节点进行标记，对于标记为已访问的节点，在出栈的时候就只处理其自身，如果没有标记，则处理子树
//使用递归来完成的操作往往使用栈迭代也可以实现
//前序遍历的顺序是中、左、右
//可以建立一个栈，将根节点入栈，循环栈非空，在每一次循环中，访问栈顶节点并且弹出，将栈顶节点的右节点、左节点分别入栈
//注意空节点不入栈

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
        //栈中储存的是pair，用于标记是否被访问过
        stack<pair<TreeNode*, bool>> s;
        vector<int> res;
        if(root == nullptr) {
            return res;
        }
        s.push(make_pair(root, false));
        while (!s.empty()) {
            TreeNode* cur = s.top().first;
            bool visited = s.top().second;
            s.pop();
            //如果标记已经访问，则只用处理该节点本身
            if(visited) {
                res.push_back(cur->val);
                continue;
            }
            //如果没有访问过，则要处理以该节点为根的子树，也就是要将该节点本身和其儿子节点入栈
            //入栈的顺序是遍历的顺序的反序
            else {
                if(cur->right != nullptr) {
                    s.push(make_pair(cur->right, false));
                }
                if(cur->left != nullptr) {
                    s.push(make_pair(cur->left, false));
                }
                s.push(make_pair(cur, true));
                continue;
            }
        }
        return res;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        //栈中储存的是pair，用于标记是否被访问过
        stack<pair<TreeNode*, bool>> s;
        vector<int> res;
        if(root == nullptr) {
            return res;
        }
        s.push(make_pair(root, false));
        while (!s.empty()) {
            TreeNode* cur = s.top().first;
            bool visited = s.top().second;
            s.pop();
            //如果标记已经访问，则只用处理该节点本身
            if(visited) {
                res.push_back(cur->val);
                continue;
            }
            //如果没有访问过，则要处理以该节点为根的子树，也就是要将该节点本身和其儿子节点入栈
            //入栈的顺序是遍历的顺序的反序
            else {
                if(cur->right != nullptr) {
                    s.push(make_pair(cur->right, false));
                }
                s.push(make_pair(cur, true));
                if(cur->left != nullptr) {
                    s.push(make_pair(cur->left, false));
                }
                continue;
            }
        }
        return res;
    }


    vector<int> postorderTraversal(TreeNode* root) {
        //栈中储存的是pair，用于标记是否被访问过
        stack<pair<TreeNode*, bool>> s;
        vector<int> res;
        if(root == nullptr) {
            return res;
        }
        s.push(make_pair(root, false));
        while (!s.empty()) {
            TreeNode* cur = s.top().first;
            bool visited = s.top().second;
            s.pop();
            //如果标记已经访问，则只用处理该节点本身
            if(visited) {
                res.push_back(cur->val);
                continue;
            }
            //如果没有访问过，则要处理以该节点为根的子树，也就是要将该节点本身和其儿子节点入栈
            //入栈的顺序是遍历的顺序的反序
            else {
                
                s.push(make_pair(cur, true));
                if(cur->right != nullptr) {
                    s.push(make_pair(cur->right, false));
                }
                if(cur->left != nullptr) {
                    s.push(make_pair(cur->left, false));
                }
                continue;
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
    vector<int> res = s.preorderTraversal(root);
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}