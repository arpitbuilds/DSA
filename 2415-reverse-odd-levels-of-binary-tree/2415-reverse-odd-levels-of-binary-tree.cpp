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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        bool reversed=0;
        while(!q.empty()){
            int s=q.size();
            vector<TreeNode*>arr(s);
            for(int i=0;i<s;i++){
                auto Node=q.front();
                q.pop();
                if(Node->left){
                    q.push(Node->left);
                }
                if(Node->right){
                    q.push(Node->right);
                }
                if(reversed){
                    arr[i]=Node;
                    if(i>=s/2){
                        swap(arr[i]->val,arr[s-i-1]->val);
                    }
                }
            }
            reversed=!reversed;
        }
        return root;
    }
};