/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
   void solve(vector<vector<int>>&ans,vector<int>&temp,Node*root){
       if(root==NULL){
           return ;
       }
       temp.push_back(root->data);
       if(root->left==NULL && root->right==NULL){
           ans.push_back(temp);
       }
       solve(ans,temp,root->left);
       solve(ans,temp,root->right);
       temp.pop_back();
   }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>>ans;
        vector<int>temp;
        solve(ans,temp,root);
        return ans;
    }
};