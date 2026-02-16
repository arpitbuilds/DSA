/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) {
            return ans;
        }
        bool flag = 1;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int s = q.size();
            vector<int> res(s);
            for (int i = 0; i < s; i++) {
                TreeNode* x = q.front();
                q.pop();
                int ind;
                if (x->left) {
                    q.push(x->left);
                }
                if (x->right) {
                    q.push(x->right);
                }
                if (flag) {
                    ind = i;
                } else {
                    ind = s - i - 1;
                }
                res[ind] = x->val;
            }
            flag = !flag;
            ans.push_back(res);
        }
        return ans;
    }
};