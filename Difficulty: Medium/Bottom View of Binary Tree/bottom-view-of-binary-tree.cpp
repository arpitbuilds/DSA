/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        queue<pair<Node*,int>>q;
        q.push({root,0});
        map<int,int>mpp;
        while(!q.empty()){
            Node*x=q.front().first;
            int line=q.front().second;
            q.pop();
           
                mpp[line]=x->data;
            
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