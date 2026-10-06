class Solution {
public:
    int cnt=0;
     void solve(int i , vector<vector<int>>&adj,vector<int>&vis){
        vis[i]=1;
        for(auto it : adj[i]){
            if(!vis[it]){
                vis[it]=1;
                solve(it,adj,vis);
            }
        }     
    }
    int findCircleNum(vector<vector<int>>&mat) {
        int x=mat.size();
        vector<vector<int>>v(x);
        vector<int>vis(x,0);
        for(int i=0;i<x;i++){
            for(int j=0;j<x;j++){
                if(mat[i][j]==1){
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
        }
        for(int i=0;i<x;i++){
            if(!vis[i]){
                cnt++;
                solve(i,v,vis);
            }
        }
        return cnt;
    }
};