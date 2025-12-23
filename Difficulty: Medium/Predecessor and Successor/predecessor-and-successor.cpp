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
    void solve(Node*root,Node*&prev,Node*&suc,int key){
        if(root==NULL){
            return;
        }
        solve(root->left,prev,suc,key);
        if(root->data<key){
            prev=root;
        }
        if(root->data>key && suc==NULL){
            suc=root;
        }
        solve(root->right,prev,suc,key);
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node*prev=NULL;
        Node*suc=NULL;
        solve(root,prev,suc,key);
        return {prev,suc};
    }
};