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
        queue<TreeNode*> q;
        q.push(root);
        unordered_map<int, TreeNode*> mpp;
        while (!q.empty()) {
            int s = q.size();

            for (int i = 0; i < s; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left);
                    mpp[node->left->val] = node;
                }
                if (node->right) {
                    mpp[node->right->val] = node;
                    q.push(node->right);
                }
            }
        }
        q.push(target);
        unordered_map<int, int> vis;
        while (k-- && !q.empty()) {

            int s = q.size();
            for (int i = 0; i < s; i++) {
                TreeNode* node = q.front();
                q.pop();
                vis[node->val] = 1;
                if (node->left && !vis[node->left->val]) {
                    q.push(node->left);
                }
                if (node->right && !vis[node->right->val]) {
                    q.push(node->right);
                }
                if (mpp[node->val] && !vis[mpp[node->val]->val]) {
                    q.push(mpp[node->val]);
                }
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};