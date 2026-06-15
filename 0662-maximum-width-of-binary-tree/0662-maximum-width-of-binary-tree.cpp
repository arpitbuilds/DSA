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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        int maxi = INT_MIN;
        unsigned long long left, right;
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                TreeNode* x = q.front().first;
                unsigned long long ind = q.front().second;
                q.pop();
                if (x->left) {
                    q.push({x->left, 2 * ind + 1});
                }
                if (x->right) {
                    q.push({x->right, 2 * ind + 2});
                }
                if (i == 0) {
                    left = ind;
                }
                if (i == s - 1) {
                    right = ind;
                }
            }
            maxi = max(maxi, (int)(right - left + 1));
        }
        return maxi;
    }
};