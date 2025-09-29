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
    string smallest;
    void solve(TreeNode*root,string path){
        if(root==NULL){
            return ;
        }
        path.push_back('a'+root->val);
        if(root->left==NULL && root->right==NULL){
            string x=path;
            reverse(x.begin(),x.end());
            if(smallest.empty() || smallest>x){
                smallest=x;
            }
        }
            solve(root->left,path);
            solve(root->right,path);
        }
    
    string smallestFromLeaf(TreeNode* root) {
        smallest="";
        solve(root,"");
        return smallest;
        
    }
};