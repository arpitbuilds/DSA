class Solution {
  public:
    int ans=-1;
    void inorder(Node*root,int x){
        if(root==NULL){
            return;
        }
        inorder(root->left,x);
        if(root->data>=x && ans==-1){
            ans=root->data;
        }
        inorder(root->right,x);
    }
    int findCeil(Node* root, int x) {
        // code here
        inorder(root,x);
        return ans;
        
    }
};
