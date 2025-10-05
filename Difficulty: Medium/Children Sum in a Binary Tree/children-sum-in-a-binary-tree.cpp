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
    bool helper(Node *&root){
        
         if(root==NULL){
            return true;
        }
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        int lsum=root->left?root->left->data:0;
        int rsum=root->right?root->right->data:0;
        if(root->data!=lsum+rsum){
            return false;
            }
    return helper(root->left)&& helper(root->right);
        
    }
    int isSumProperty(Node *root) {
        // code here
        return helper(root);
    }
       
};