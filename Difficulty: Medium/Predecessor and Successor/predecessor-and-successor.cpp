/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    
    void solve(Node*root,int key,Node*&pre,Node*&suc){
        if(root==NULL){
            return;
        }
        solve(root->left,key,pre,suc);
        if(root->data<key){
            pre=root;
        }
        else if(root->data>key && !suc){
            suc=root;
        }
        solve(root->right,key,pre,suc);
        
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* pre=NULL;
        Node* suc=NULL;
        solve(root,key,pre,suc);
        return {pre,suc};
    }
};