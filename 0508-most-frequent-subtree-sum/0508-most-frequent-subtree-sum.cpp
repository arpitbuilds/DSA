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
    int ans=0;
    unordered_map<int,int>mpp;
    int solve(TreeNode*root){
        if(root==NULL){
            return 0;
        }
        int left=solve(root->left);
        int right=solve(root->right);
        int sum=root->val+left+right;
        mpp[sum]++;
        ans=max(ans,mpp[sum]);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int>v;
        solve(root);
        for(auto it : mpp){
            if(it.second==ans){
                v.push_back(it.first);
            }
        }
        return v;
        
    }
};