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
        queue<pair<TreeNode*,unsigned long long>>q;
        q.push({root,0});
        int maxw=INT_MIN;
        while(!q.empty()){
            int s=q.size();
           unsigned long long l,r;
            for(int i=0;i<s;i++){
                TreeNode*node=q.front().first;
                unsigned long long ind=q.front().second;
                q.pop();
                if(i==0){
                    l=ind;
                }
                if(i==s-1){
                    r=ind;
                }
                if(node->left){
                    q.push({node->left,2*ind+1});
                }
                if(node->right){
                    q.push({node->right,2*ind+2});
                }
                
                
            }
            maxw=max(maxw,(int)(r-l+1));
        }
        return maxw;
    }
};