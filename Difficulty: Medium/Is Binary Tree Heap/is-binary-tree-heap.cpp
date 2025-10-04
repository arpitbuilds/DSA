// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

bool isCompleteTree(Node* root) {
    if (!root) return true;

    queue<Node*> q;
    q.push(root);
    bool flag = false;

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();

        if (!node) {
            flag = true;
        } else {
            if (flag) return false;
            q.push(node->left);
            q.push(node->right);
        }
    }
    return true;
}

bool isHeapProperty(Node* root) {
    if (!root) return true;

    if (root->left && root->left->data > root->data) return false;
    if (root->right && root->right->data > root->data) return false;

    return isHeapProperty(root->left) && isHeapProperty(root->right);
}
class Solution {
  public:
    bool isHeap(Node* tree) {
        // code here
         return isCompleteTree(tree) && isHeapProperty(tree);
        
    }
};