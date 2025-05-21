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
    void solve(TreeNode*root,int &sum,bool isleft){
        if(root==NULL){
            return ;
        }
       
        solve(root->left,sum,true);
        if(isleft &&root->left==NULL && root->right==NULL){
            sum+=root->val;
        }
        solve(root->right,sum,false);
        
    }
    int sumOfLeftLeaves(TreeNode* root) {
    int ans=0;
    solve(root,ans,false);
    return ans;
    }
};