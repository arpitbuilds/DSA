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
    int solve(TreeNode*root,int &d){
        if(root==NULL){
            return 0;
        }
        int lh=max(0,solve(root->left,d));
        int rh=max(0,solve(root->right,d));
        d=max(d,root->val+lh+rh);
        return root->val+max(lh,rh);
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        if(root==NULL){
            return ans;
        }
        solve(root,ans);
        return ans;
        
    }
};