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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if (root == NULL) {
            return ans;
        }
        queue < pair<TreeNode*, pair<int, vector<int>>>> q;
        vector<int> temp;
        temp.push_back(root->val);
        q.push({root,{root->val,temp}});
        while (!q.empty()) {
            TreeNode* x = q.front().first;
            int sum = q.front().second.first;
            vector<int> v = q.front().second.second;
            q.pop();
            if (x->left == NULL && x->right == NULL) {
                if (sum == targetSum) {
        ans.push_back(v);
    }
            }
            if (x->left) {
                vector<int> left = v;
                left.push_back(x->left->val);
                q.push({x->left, {sum + x->left->val, left}});
            }
            if (x->right) {
                vector<int> right = v;
                right.push_back(x->right->val);
                q.push({x->right, {sum + x->right->val, right}});
            }
        }
        return ans;
    }
};