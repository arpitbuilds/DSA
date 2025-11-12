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
    void addl(Node*root,vector<int>&res){
        Node*cur=root->left;
        while(cur){
            if(!isleaf(cur)){
                res.push_back(cur->data);
            }
            if(cur->left){
                cur=cur->left;
            }
            else{
                cur=cur->right;
            }
            
        }
    }
    void addr(Node*root,vector<int>&res){
           Node*cur=root->right;
           vector<int>ans;
        while(cur){
            if(!isleaf(cur)){
                ans.push_back(cur->data);
            }
            if(cur->right){
                cur=cur->right;
            }
            else{
                cur=cur->left;
            }
            
        }
        for(int i=ans.size()-1;i>=0;i--){
            res.push_back(ans[i]);
        }
        
    }
    void addt(Node*root,vector<int>&res){
        if(root==NULL){
            return ;
        }
        if(isleaf(root)){
            res.push_back(root->data);
            // return;
        }
        addt(root->left,res);
        addt(root->right,res);
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int>res;
        if(root==NULL){
            return res;
        }
       if (!isleaf(root)) res.push_back(root->data);
        addl(root,res);
        addt(root,res);
        addr(root,res);
        return res;
        
    }
};