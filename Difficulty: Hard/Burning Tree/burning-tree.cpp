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
         unordered_map<int,Node*>mpp;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                Node*node=q.front();
                q.pop();
                if(node->data==target){
                    start=node;
                }
                if(node->left){
                    q.push(node->left);
                    mpp[node->left->data]=node;
                }
                if(node->right){
                    q.push(node->right);
                    mpp[node->right->data]=node;
                }
            }
        }
        unordered_map<int,int>vis;
        vis[start->data]=1;
        q.push(start);
        int t=0;
        while(!q.empty()){
            int s=q.size();
            bool burned=false;
            for(int i=0;i<s;i++){
            Node*node=q.front();
            q.pop();
              if(node->left && !vis[node->left->data]){
                    q.push(node->left);
                    vis[node->left->data]=1;
                    burned=true;
                }
                if(node->right && !vis[node->right->data]){
                    q.push(node->right);
                    vis[node->right->data]=1;
                    burned=true;
                }
                if(mpp[node->data] && !vis[mpp[node->data]->data]){
                    q.push(mpp[node->data]);
                    vis[mpp[node->data]->data]=1;
                    burned=true;
                }
            }
            if(burned){
                t++;
            }
            
        }
        return t;
        
    }
};