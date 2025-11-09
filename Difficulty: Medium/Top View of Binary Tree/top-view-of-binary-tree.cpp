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
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        map<int,int>mpp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            Node*x=q.front().first;
            int line=q.front().second;
            q.pop();
            if(mpp.find(line)==mpp.end()){
                mpp[line]=x->data;
            }
            if(x->left){
                q.push({x->left,line-1});
            }
            if(x->right){
                q.push({x->right,line+1});
            }
        }
        for(auto it : mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};