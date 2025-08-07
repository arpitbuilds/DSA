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
    TreeNode *solve(int start,int end,vector<int>& inorder, vector<int>& postorder,int &ind){
        if(start>end){
            return NULL;
        }
        int rootv=postorder[ind];
        ind--;
        TreeNode *root=new TreeNode(rootv);
        int i=start;
        for(;i<=end;i++){
            if(inorder[i]==rootv){
                break;
            }
        }
        root->right=solve(i+1,end,inorder,postorder,ind);
        root->left=solve(start,i-1,inorder,postorder,ind);
       
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int ind=inorder.size()-1;
       return   solve(0,inorder.size()-1,inorder,postorder,ind);
            }
};