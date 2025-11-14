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
    void addl(Node*root ,vector<int>&res){
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
    void addt(Node*root,vector<int>&res){
        if(root==NULL){
            return;
        }
        if(isleaf(root)){
            res.push_back(root->data);
        }
        addt(root->left,res);
        addt(root->right,res);
        }
    void addr(Node*root,vector<int>&res){
        Node*cur=root->right;
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
            res.push_back(temp[i]);
        }
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        if(!isleaf(root)){
            ans.push_back(root->data);
        }
        addl(root,ans);
        addt(root,ans);
        addr(root,ans);
        return ans;
    }
};