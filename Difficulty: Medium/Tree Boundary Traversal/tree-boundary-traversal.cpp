/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    bool isleaf(Node*root){
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        else{
        return false;
        }
    }
    void addr(Node*root,vector<int>&ans){
      Node *cur=root->right;
        vector<int>temp;
        while(cur){
           if(!isleaf(cur)){
            temp.push_back(cur->data);
        }
        if(cur->right){
            cur=cur->right;
        }
        else{
            cur=cur->left;
        }
        }
        for(int i=temp.size()-1;i>=0;i--){
            ans.push_back(temp[i]);
        }
    }
      void addl(Node*root,vector<int>&ans){
        Node*cur=root->left;
        while(cur){
             if(!isleaf(cur)){
             ans.push_back(cur->data);
        }
            if(cur->left){
                cur=cur->left;
            }
            else{
                cur=cur->right;
            }
        }
    }
    void adde(Node*root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        if(isleaf(root)){
            ans.push_back(root->data);
            return;
        }
        adde(root->left,ans);
        adde(root->right,ans);
    }
    
    vector<int> boundaryTraversal(Node *root) {
        // code here
          vector<int>res;
        if(!root){
            return res;
        }
         if(!isleaf(root)){
           res.push_back(root->data); 
        }
        
        addl(root,res);
        adde(root,res);
        addr(root,res);
        return res;
        
    }
};