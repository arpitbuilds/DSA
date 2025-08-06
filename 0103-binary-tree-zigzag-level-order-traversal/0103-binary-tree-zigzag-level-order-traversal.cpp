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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
      queue<TreeNode*>q;
      q.push(root);
      bool flag=1;
      while(!q.empty()){
        int s=q.size();
        vector<int>v(s);
        for(int i=0;i<s;i++){
            TreeNode *n=q.front();
            q.pop();
            int index;
            if(flag==1){
                index=i;
            }
            else{
                index=s-i-1;
            }
            if(n->left){
                q.push(n->left);
            }
            if(n->right){
                q.push(n->right);
            }
            v[index]=n->val;
        }
        flag=!flag;
        ans.push_back(v);
      }
        return ans;
    }
};