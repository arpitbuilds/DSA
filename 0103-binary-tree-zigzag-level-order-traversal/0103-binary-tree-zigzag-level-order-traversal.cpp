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
           vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool flag=true;
        while (!q.empty()) {
            int s = q.size();
            vector<int> v(s);
            int ind;
            for (int i = 0; i < s; i++) {
                TreeNode* x = q.front();
                q.pop();
                 if(flag){
                    ind=i;
                 }
                 else{
                    ind=s-i-1;
                 }
                if (x->left) {
                    q.push(x->left);
                }
                if (x->right) {
                    q.push(x->right);
                }
                v[ind]=x->val;
            }
            flag=!flag;
            ans.push_back(v);
        }
        return ans;
    }
};