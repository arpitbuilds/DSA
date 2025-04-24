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
    bool help(long left, TreeNode* root, long right){
        if (root==NULL) return true;
        if (left >= root->val || right <= root->val) return false;
        return help(left, root->left, root->val) && help(root->val, root->right, right);
    }
    bool isValidBST(TreeNode* root) {
        return help(LONG_MIN, root, LONG_MAX);
    }
};