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
        Node*start=NULL;
         unordered_map<int,Node*> mpp;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            if(node->data==target){
                start=node;
            }
            if (node->left) {
                q.push(node->left);
                mpp[node->left->data] = node;
            }
            if (node->right) {
                q.push(node->right);
                mpp[node->right->data] = node;
            }
        }
        q.push(start);
        unordered_map<int,int>vis;
        vis[start->data]=1;
       
        int time=0;
        while(!q.empty()){
            int s=q.size();
             bool burned=false;
            for(int i=0;i<s;i++){
                Node*node=q.front();
                q.pop();
                vis[node->data]=1;
                if(node->left && !vis[node->left->data]){
                    q.push(node->left);
                    burned=true;
                     vis[node->left->data] = 1;
                }
                if(node->right && !vis[node->right->data]){
                    q.push(node->right);
                    burned=true;
                     vis[node->right->data] = 1;
                }
                if(mpp[node->data]  && !vis[mpp[node->data]->data]){
                    q.push(mpp[node->data]);
                    burned=true;
                     vis[mpp[node->data]->data] = 1;
                }
                
            }
            if(burned){
                time+=1;
            }
        }
        return time;
    }
};