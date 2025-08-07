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
    TreeNode* solve(int start,int end,vector<int>& preorder, vector<int>& inorder,int &ind){
        if(start>end){
            return NULL;
        }
        int rootv=preorder[ind];
        int i=start;
        for(;i<=end;i++){
            if(inorder[i]==rootv){
                break;
            }
        }
            ind++;
            TreeNode *root=new TreeNode(rootv);
            root->left=solve(start,i-1,preorder,inorder,ind);
            root->right=solve(i+1,end,preorder,inorder,ind);
            return root;

        }
        
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int ind=0;
        int n=preorder.size();
        return solve(0,n-1,preorder,inorder,ind);
    }
};