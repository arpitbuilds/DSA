/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    int minValue(Node* root) {
        // code here
        if(root==NULL){
            return -1;
        }
        Node*cur=root;
        while(cur->left){
            cur=cur->left;
        }
        return cur->data;
    }
};