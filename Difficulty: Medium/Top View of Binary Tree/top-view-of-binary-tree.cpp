/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
   map<int,int>mpp;
   vector<int>ans;
   queue<pair<Node*,int>>q;
   q.push({root,0});
   while(!q.empty()){
       int line=q.front().second;
       Node*root=q.front().first;
       q.pop();
       if(mpp.find(line)==mpp.end()){
           mpp[line]=root->data;
       }
       if(root->left){
           q.push({root->left,line-1});
       }
       if(root->right){
           q.push({root->right,line+1});
       }
   }
        for(auto it :mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};