#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if(root == nullptr) {
            return root;
        }
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            Node *pre = nullptr;
            Node *cur = nullptr;
            for(int i = 0; i < size; i++) {
                cur = q.front();
                q.pop();
                if(pre != nullptr) {
                    pre->next = cur;
                }
                if(cur->left != nullptr) {
                    q.push(cur->left);
                }
                if(cur->right != nullptr) {
                    q.push(cur->right);
                }
                pre = cur;
            }
        }
        return root;
    }
};
int main() {

}