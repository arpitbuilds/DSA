class Solution {
  public:
    void dfs(int s ,vector<int>&ans,vector<int>&vis,vector<vector<int>>& adj){
        vis[s]=1;
        ans.push_back(s);
        for(auto it : adj[s]){
            if(!vis[it]){
                dfs(it,ans,vis,adj);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int>ans;
        int n=adj.size();
        vector<int>vis(n,0);
        int s=0;
        dfs(s,ans,vis,adj);
        return ans;
    }
};