/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    Node* pre = NULL;
    Node* suc = NULL;

    void inorder(Node* root, int key) {
        if (!root) return;

        inorder(root->left, key);

        // if node value < key → it could be predecessor
        if (root->data < key)
            pre = root;

        // if node value > key → it could be successor
        else if (root->data > key && !suc)
            suc = root;

        inorder(root->right, key);
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
                pre = suc = NULL;
        inorder(root, key);
        return {pre, suc};

        
    }
};