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
    void solve(TreeNode* root, vector<int>& s) {
        if (root == NULL) {
            return;
        }
        solve(root->left, s);
        s.push_back(root->val);
        solve(root->right, s);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        solve(root, v);
        int s = 0;
        int e = v.size() - 1;
        while (s < e) {
           int sum = v[s] + v[e];
            if (sum == k) {
                return true;
            }  else if (sum < k) {
                s++;
            } else {
                e--;
            }
        }
        return false;
    }
};