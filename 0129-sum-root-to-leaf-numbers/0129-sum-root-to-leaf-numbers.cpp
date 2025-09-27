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
    int sumNumbers(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});
        int total = 0;
        while (!q.empty()) {
            auto [node, num] = q.front();
            q.pop();
            if (node->left == NULL && node->right == NULL) {
                total += num;
            }
            if (node->left) {
                q.push({node->left, num*10 + node->left->val});
            }
            if (node->right) {
                q.push({node->right, num*10  + node->right->val});
            }
        }
        return total;
    }
};