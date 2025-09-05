/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // Your Code Here
        vector<int>v;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        map<int,int>mpp;
        if(root==NULL){
            return v;
        }
        while(!q.empty()){
            auto it =q.front();
            int line=it.second;
            Node*x=it.first;
            q.pop();
                mpp[line]=x->data;
            if(x->left){
                q.push({x->left,line-1});
            }
            if(x->right){
                q.push({x->right,line+1});
            }
            
        }
        for(auto it:mpp){
            v.push_back(it.second);
        }
        return v;  
    }
};