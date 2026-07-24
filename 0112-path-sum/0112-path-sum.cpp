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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
        queue<pair<TreeNode*,int>>q;
        q.push({root,root->val});
        while(!q.empty()){
            TreeNode*x=q.front().first;
            int sum=q.front().second;
            q.pop();
            if(x->left==NULL && x->right==NULL){
            if(sum==targetSum){
                return true;
            }
            }
            if(x->left){
                q.push({x->left,sum+x->left->val});
            }
            if(x->right){
                q.push({x->right,sum+x->right->val});
            }
        }
        return false;
    }
};