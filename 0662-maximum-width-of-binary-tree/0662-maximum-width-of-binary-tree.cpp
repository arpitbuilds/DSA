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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int maxw=1;
        queue<pair<TreeNode*,unsigned long long>>q;
        q.push({root,0});
        while(!q.empty()){
            int s=q.size();
            int l,r;
            for(int i=0;i<s;i++){
                TreeNode*node=q.front().first;
                unsigned long long  idx=q.front().second;
                q.pop();
                if(i==0){
                    l=idx;
                }
                if(i==s-1){
                    r=idx;
                }
                if(node->left){
                    q.push({node->left,2*idx+1});
                }
                if(node->right){
                    q.push({node->right,2*idx+2});
                }
            }
            maxw=max(maxw,r-l+1);
        }
        return maxw;
    }
};