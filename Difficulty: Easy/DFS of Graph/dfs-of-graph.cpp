class Solution {
  public:
    void solve(int s,vector<int>&ans,vector<int>&vis,vector<vector<int>>& adj){
        vis[s]=1;
        ans.push_back(s);
        for(auto it : adj[s]){
            if(!vis[it]){
                solve(it,ans,vis,adj);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int>ans;
        int n=adj.size();
        vector<int>vis(n,0);
        solve(0,ans,vis,adj);
        return ans;
    }
};