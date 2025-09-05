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
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        vector<int>ans;
        map<int,int>mpp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            Node*n=q.front().first;
            int line =q.front().second;
            q.pop();
            if(mpp.find(line)==mpp.end()){
                mpp[line]=n->data;
            }
            if(n->left){
                q.push({n->left,line-1});
            }
            if(n->right){
                q.push({n->right,line+1});
            }
        }
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};