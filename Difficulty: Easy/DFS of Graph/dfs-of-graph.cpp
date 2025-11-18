class Solution {
  public:
    void solve(int s,vector<vector<int>>&adj,vector<int>&vis,vector<int>&ans){
        vis[s]=1;
        ans.push_back(s);
        for(auto it : adj[s]){
            if(!vis[it]){
                solve(it,adj,vis,ans);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        vector<int>ans;
        vector<int>vis(n,0);
        solve(0,adj,vis,ans);
        return ans;
    }
};