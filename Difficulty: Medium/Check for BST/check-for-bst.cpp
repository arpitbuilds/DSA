/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool solve(Node* root, int& prv){
        if (!root) return true;
        bool left=solve(root->left, prv);
        if (root->data <= prv) return false;
        prv = root->data;
        bool right=solve(root->right, prv);
        return left && right;
        
    }
    bool isBST(Node* root) {
        // code here
        int prv = INT_MIN;
        return solve(root, prv);
        
    }
};