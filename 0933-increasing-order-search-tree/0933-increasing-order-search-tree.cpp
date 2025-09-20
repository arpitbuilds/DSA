/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode*&prev,TreeNode*root){
        if(root==NULL){
            return;
        }
        inorder(prev,root->left);
        prev->right=new TreeNode(root->val);
        prev=prev->right;
        inorder(prev,root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode*dummy=new TreeNode(-1);
        TreeNode*prev=dummy;
        inorder(prev,root);
        return dummy->right;
    }
};