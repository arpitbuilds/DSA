/*
class Node {
  public:
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
    int minTime(Node* root, int target) {
        // code here
           Node* start = nullptr;
        queue<Node*> q;
        q.push(root);
        unordered_map<int, Node*> mpp;
        while (!q.empty()) {
            int s = q.size();
         

            for (int i = 0; i < s; i++) {
                Node* node = q.front();
                q.pop();
                if (node->data == target) start = node;
                if (node->left) {
                    q.push(node->left);
                    mpp[node->left->data] = node;
                }
                if (node->right) {
                    mpp[node->right->data] = node;
                    q.push(node->right);
                }
            }
        }
         unordered_map<int, int> vis;
        int time=0;
          q.push(start);
        vis[start->data] = true;
       
        while (!q.empty()) {
               bool burned = false;
            int s = q.size();
            for (int i = 0; i < s; i++) {
                Node* node = q.front();
                q.pop();
               
                vis[node->data] = 1;
                if (node->left && !vis[node->left->data]) {
                    q.push(node->left);
                    burned=true;
                }
                if (node->right && !vis[node->right->data]) {
                    q.push(node->right);
                    burned=true;
                }
                if (mpp[node->data] && !vis[mpp[node->data]->data]) {
                    q.push(mpp[node->data]);
                    burned=true;
                }
            }
              if (burned) time++;
        }
        return time;
    }
};