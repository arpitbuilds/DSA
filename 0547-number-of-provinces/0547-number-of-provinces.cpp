class Solution {
public:
    void solve(int i,vector<int>&vis,vector<vector<int>>&adj){
        vis[i]=1;
        for(auto it : adj[i]){
            if(!vis[it]){
                solve(it,vis,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& is) {
        int n=is.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(is[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                solve(i,vis,adj);
            }
        }
        return cnt;
    }
};