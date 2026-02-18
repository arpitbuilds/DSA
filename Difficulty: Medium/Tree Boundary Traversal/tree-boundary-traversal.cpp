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
    void addr(Node*root,vector<int>&ans){
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
        reverse(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++){
            ans.push_back(temp[i]);
        }
    }
    void addt(Node*root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        if(isleaf(root)){
            ans.push_back(root->data);
        }
        addt(root->left,ans);
        addt(root->right,ans);
        
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int>ans;
        if(!isleaf(root)){
            ans.push_back(root->data);
        }
        addl(root,ans);
        addt(root,ans);
        addr(root,ans);
        return ans;
    }
};