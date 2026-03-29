class Solution {
public:
    void solve(int i,vector<int>&vis,vector<vector<int>>&adj,int &cnt){
        vis[i]=1;
        for(auto it : adj[i]){
            if(!vis[it]){
                solve(it,vis,adj,cnt);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& is) {
        int n=is.size();
        vector<vector<int>>v(n);
        vector<int>vis(n);
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(is[i][j]==1 && i!=j){
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                  cnt++;
                solve(i,vis,v,cnt);
            }
        }
        return cnt;
    }
};