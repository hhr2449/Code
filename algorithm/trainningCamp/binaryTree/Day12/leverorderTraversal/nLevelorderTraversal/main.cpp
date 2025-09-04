#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//n叉树的节点，其实就是将子节点的储存放在一个vector中，这样一个节点可以拥有多个儿子节点
struct Node {
    int val;
    vector<Node*> children;
    
    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
//实际上n叉树的遍历和二叉树是相似的，只是在遍历子节点的时候需要使用一个for循环
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(root == nullptr) {
            return res;
        }
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<int> level;
            for(int i = 0; i < size; i++) {
                Node* cur = q.front();
                q.pop();
                level.push_back(cur->val);
                for(int i = 0; i < cur->children.size(); i++) {
                    if(cur->children[i] != nullptr) {
                        q.push(cur->children[i]);
                    }
                }
            }
            res.push_back(level);
        }
        return res;
    }
};

Node* createTree() {
    // 创建节点
    Node* root = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    
    // 构建N叉树结构
    //       1
    //    /  |  \
    //   2   3   4
    //  /|   |
    // 5 6   6
    
    root->children.push_back(node2);
    root->children.push_back(node3);
    root->children.push_back(node4);
    
    node2->children.push_back(node5);
    node2->children.push_back(node6);
    
    node3->children.push_back(new Node(6));
    
    return root;
}
int main() {
    Node* root = createTree();  // 修改这里
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