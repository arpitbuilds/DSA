/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
  public:
    void solve(Node*root,int k,int &cnt,int &ans){
        if(root==NULL){
            return;
        }
         solve(root->right,k,cnt,ans);
        cnt++;
        if(cnt==k){
            ans=root->data;
        }
      
         solve(root->left,k,cnt,ans);

    }
    int kthLargest(Node *root, int k) {
        // Your code here
        int ans;
        int cnt=0;
        solve(root,k,cnt,ans);
        return ans;
        
    }
};