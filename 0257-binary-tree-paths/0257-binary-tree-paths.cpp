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
    void findpath(TreeNode*root,vector<string>&ans,string temp){
        temp+=to_string(root->val);
        if(root->left){
            findpath(root->left,ans,temp + "->");
        }
        if(root->right){
            findpath(root->right,ans,temp + "->");
        }
        if(!root->left && !root->right){
            ans.push_back(temp);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        if(root){
            findpath(root,ans,"");
        }
        return ans;
    }
};