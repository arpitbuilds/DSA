/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
     void inorderMin(Node* root, int &mini) {
        if (!root) return;
        inorderMin(root->left, mini);
        // first element visited in inorder is smallest
        mini = min(mini, root->data);
        inorderMin(root->right, mini);
    }

    void inorderMax(Node* root, int &maxi) {
        if (!root) return;
        inorderMax(root->left, maxi);
        // last element visited in inorder is largest
        maxi = max(maxi, root->data);
        inorderMax(root->right, maxi);
    }
    int findMax(Node *root) {
        // code here
          int maxi = INT_MIN;
        inorderMax(root, maxi);
        return maxi;
        
    }

    int findMin(Node *root) {
        
        // code here
          int mini = INT_MAX;
        inorderMin(root, mini);
        return mini;
    }
};