// Function to search a node in BST.
class Solution {

  public:
  int ans=-1;
    void inorder(Node* root, int x) {
        if (!root) return;

      
        inorder(root->left, x);


        if (root->data <= x) {
            ans = root->data; 
        } else {
            return; 
        }

       
        inorder(root->right, x);
    }

    int floor(Node* root, int x) {
        // Code here
        inorder(root, x);
        return ans;

        
    }
};