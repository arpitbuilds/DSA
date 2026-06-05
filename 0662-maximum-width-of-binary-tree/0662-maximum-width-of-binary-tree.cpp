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
        queue<pair<TreeNode*,unsigned long long>>q;
        q.push({root,0});
        unsigned long long l,r;
       int maxi=INT_MIN;
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode*x=q.front().first;
                unsigned long long ind=q.front().second;
                q.pop();
                if(x->left){
                    q.push({x->left,2*ind+1});
                }
                if(x->right){
                    q.push({x->right,2*ind+2});
                }
                if(i==0){
                    l=ind;
                }
                if(i==s-1){
                    r=ind;
                }
            }
            maxi=max(maxi,(int)(r-l+1));
        }
        return maxi;
    }
};