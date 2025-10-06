/*
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
class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
     void inorder(Node* root, vector<int>& res) {
        if (!root) return;
        inorder(root->left, res);
        res.push_back(root->data);
        inorder(root->right, res);
    }
        vector<int> merge(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        int i = 0, j = 0;
        vector<int> ans;

        while (i < n && j < m) {
            if (a[i] < b[j])
                ans.push_back(a[i++]);
            else
                ans.push_back(b[j++]);
        }

        while (i < n) ans.push_back(a[i++]);
        while (j < m) ans.push_back(b[j++]);

        return ans;
    }

    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
             vector<int> bst1, bst2;
        inorder(root1, bst1);
        inorder(root2, bst2);
        return merge(bst1, bst2);
        
    }
};