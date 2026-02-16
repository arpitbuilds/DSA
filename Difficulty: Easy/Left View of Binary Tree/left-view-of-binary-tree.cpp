/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
         vector<int> res;
        if (root == NULL) {
            return {};
        }
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int s = q.size();

            for (int i = 0; i < s; i++) {
                Node* x = q.front();
                q.pop();
                if (x->left) {
                    q.push(x->left);
                }
                if (x->right) {
                    q.push(x->right);
                }
                if (i == 0) {
                    res.push_back(x->data);
                }
            }
        }
        return res;
    }
};