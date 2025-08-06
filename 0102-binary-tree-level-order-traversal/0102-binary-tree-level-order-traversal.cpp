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
    vector<vector<int>> levelOrder(TreeNode* root) {
     vector<vector<int>>ans;
     if(root==NULL){
        return ans;
     }
     queue<TreeNode*>q;   
     q.push(root);
     while(!q.empty()){
        vector<int>lvl;
        int size=q.size();
        for(int i=0;i<size;i++){
            TreeNode*Node=q.front();
            q.pop();
            lvl.push_back(Node->val);
            if(Node->left){
                q.push(Node->left);
            }
            if(Node->right){
                q.push(Node->right);
            }

        }
        ans.push_back(lvl);
     }
     return ans;
    }
};