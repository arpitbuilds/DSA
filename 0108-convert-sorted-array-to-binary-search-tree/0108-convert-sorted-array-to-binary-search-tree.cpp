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
    TreeNode*bst(vector<int>&nums,int l,int r){
        if(l>r){
            return NULL;
        }
        int mid=l+(r-l)/2;
        TreeNode*temp=new TreeNode(nums[mid]);
        temp->left=bst(nums,l,mid-1);
        temp->right=bst(nums,mid+1,r);
        return temp;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        TreeNode*ans=bst(nums,l,r);
        return ans;
        
    }
};