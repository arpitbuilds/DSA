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
    bool solve(Node*root,int &prev){
        if(root==NULL){
            return true;
        }
        bool left=solve(root->left,prev);
        if(root->data<prev){
            return false;
        }
        prev=root->data;
        bool right=solve(root->right,prev);
        return left && right;
    }
    bool isBST(Node* root) {
        // code here
        int prev=INT_MIN;
        return solve(root,prev);
    }
};