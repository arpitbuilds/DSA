/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, TreeNode*> mpp;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                TreeNode* x = q.front();
                q.pop();
                if (x->left) {
                    q.push(x->left);
                    mpp[x->left->val] = x;
                }
                if (x->right) {
                    q.push(x->right);
                    mpp[x->right->val] = x;
                }
            }
        }
        q.push(target);
        unordered_map<int, int> vis;
        vis[target->val] = 1;
        while (!q.empty() && k--) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                TreeNode* x = q.front();
                q.pop();
                if (x->left && !vis[x->left->val]) {
                    q.push(x->left);
                    vis[x->left->val]=1;
                }
                if(x->right && !vis[x->right->val]){
                    q.push(x->right);
                    vis[x->right->val]=1;
                }
                if(mpp[x->val] && !vis[mpp[x->val]->val]){
                    q.push(mpp[x->val]);
                    vis[mpp[x->val]->val]=1;
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};