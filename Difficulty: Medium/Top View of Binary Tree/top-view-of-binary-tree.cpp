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
        queue<pair<Node*,int>>q;
        map<int,int>mpp;
        q.push({root,0});
        while(!q.empty()){
            Node*top=q.front().first;
            int line=q.front().second;
            q.pop();
            if(mpp.find(line)==mpp.end()){
                mpp[line]=top->data;
            }
            if(top->left){
                q.push({top->left,line-1});
            }
            if(top->right){
                q.push({top->right,line+1});
            }
        }
        vector<int>v;
        for(auto it : mpp){
            v.push_back(it.second);
        }
        return v;
    }
};