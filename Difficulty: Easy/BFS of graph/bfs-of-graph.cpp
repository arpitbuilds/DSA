class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int n=adj.size();
        vector<int>v;
        vector<int>vis(n,false);
        vis[0]=1;
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int top=q.front();
            q.pop();
            v.push_back(top);
            for(auto it : adj[top]){
                if(!vis[it]){
                    vis[it]=true;
                    q.push(it);
                }
            }
        }
       return v;
    }
};